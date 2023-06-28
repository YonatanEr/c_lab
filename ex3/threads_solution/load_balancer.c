#include "load_balancer.h"
#include <arpa/inet.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#define UPPER_PORT_BOUND 64000
#define LOWER_PORT_BOUND 1024

int setSocket(int port)
{
  int sock;
  struct sockaddr_in server;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    return -1;
  }
  bzero((char *)&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    return -1;
  }
  int incoming_sockets = 1 + NUMBER_OF_SERVERS;
  if (listen(sock, incoming_sockets) < 0) {
    return -1;
  }
  return sock;
}

void initSocket(int *port_ptr, int *this_sock_ptr)
{
  struct timeval te;
  do {
    gettimeofday(&te, NULL);
    *port_ptr = (1 + LOWER_PORT_BOUND) + ((te.tv_sec * te.tv_usec) % (UPPER_PORT_BOUND - LOWER_PORT_BOUND - 1));
    *this_sock_ptr = setSocket(*port_ptr);
  } while (*this_sock_ptr == -1);
}

int acceptConnection(int lb_socket)
{
  struct sockaddr_in address;
  socklen_t address_size = sizeof(address);
  int client_socket = accept(lb_socket, (struct sockaddr *)&address, &address_size);
  assert(client_socket >= 0);
  return client_socket;
}

LoadBalancer *initLoadBalancer()
{
  LoadBalancer *lb = (LoadBalancer *)calloc(1, sizeof(LoadBalancer));
  assert(lb);
  int this_socket_lb2pc, this_socket_lb2user;
  initSocket(&(lb->server_port), &this_socket_lb2pc);
  initSocket(&(lb->http_port), &this_socket_lb2user);
  lb->threads = (Thread **)calloc(NUMBER_OF_SERVERS, sizeof(Thread *));
  assert(lb->threads);
  for (int i = 0; i < NUMBER_OF_SERVERS; i++) {
    Thread *thread = (Thread *)calloc(1, sizeof(Thread));
    assert(thread);
    thread->busy = false;
    thread->connected = false;
    thread->lb_socket = this_socket_lb2pc;
    thread->request = NULL;
    thread->response = NULL;
    lb->threads[i] = thread;
  }
  lb->lb_socket = this_socket_lb2user;
  return lb;
}

void freeLoadBalancer(LoadBalancer *lb)
{
  for (int i = 0; i < NUMBER_OF_SERVERS; i++) {
    Thread *thread = lb->threads[i];
    close(thread->lb_socket);
    free(thread->request);
    free(thread->response);
    free(thread);
    thread = NULL;
  }
  close(lb->lb_socket);
  close(lb->user_socket);
  free(lb->threads);
  lb->threads = NULL;
  free(lb);
  lb = NULL;
}