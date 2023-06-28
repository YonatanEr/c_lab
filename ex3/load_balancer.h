#ifndef LOAD_BALANCER_H
#define LOAD_BALANCER_H
#include <pthread.h>
#include <stdbool.h>
#define NUMBER_OF_SERVERS 3

typedef struct Lb2PcThread {
  bool busy;
  bool connected;
  int lb_socket;
  int pc_socket;
  char *request;
  char *response;
  pthread_t tid;
} Thread;

typedef struct LoadBalancer {
  int server_port;
  int http_port;
  int lb_socket;
  int user_socket;
  Thread **threads;
} LoadBalancer;

int acceptConnection(int lb_socket);

LoadBalancer *initLoadBalancer();

void freeLoadBalancer(LoadBalancer *lb);

#endif