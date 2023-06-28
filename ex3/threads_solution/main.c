#include "load_balancer.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
#define NL 10
#define CR 13
#define HTTP_ENDING_LENGTH 4
#define ENDING_ARRAY(INDEX) ((INDEX % 2) ? (NL) : (CR))

bool isHttpRequestEnding(const char *str, int start)
{
  for (int i = 0; i < HTTP_ENDING_LENGTH; i++) {
    if (str[i + start] != ENDING_ARRAY(i)) {
      return false;
    }
  }
  return true;
}

int countHttpRequestEndings(char *str)
{
  int count = 0, str_len = strlen(str);
  for (int i = 0; i <= str_len - HTTP_ENDING_LENGTH; i++) {
    if (isHttpRequestEnding(str, i)) {
      count++;
    }
  }
  return count;
}

void stringCopy(char **dst_ptr, char **src_ptr)
{
  int len = strlen(*src_ptr);
  *dst_ptr = (char *)calloc(1 + len, sizeof(char));
  assert(*dst_ptr);
  for (int i = 0; i < len; i++) {
    (*dst_ptr)[i] = (*src_ptr)[i];
  }
}

void stringAppend(char **str_ptr, char **addition_ptr)
{
  int str_len = strlen(*str_ptr), addition_len = strlen(*addition_ptr);
  for (int i = str_len; i < str_len + addition_len; i++) {
    (*str_ptr)[i] = (*addition_ptr)[i - str_len];
  }
  (*str_ptr)[str_len + addition_len] = '\0';
}

void receiveMsg(int client_socket, char **msg_ptr, int required_endings_amount)
{
  free(*msg_ptr);
  *msg_ptr = NULL;
  *msg_ptr = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
  assert(*msg_ptr);
  int allocated_size = BUFFER_SIZE + 1, cur_recv_bytes = 0;
  do {
    char *buffer = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
    assert(buffer);
    do {
      cur_recv_bytes = recv(client_socket, buffer, BUFFER_SIZE, 0);
      assert(cur_recv_bytes >= 0);
    } while (cur_recv_bytes == 0);
    allocated_size = allocated_size + BUFFER_SIZE;
    *msg_ptr = (char *)realloc(*msg_ptr, allocated_size);
    assert(*msg_ptr);
    stringAppend(msg_ptr, &buffer);
    free(buffer);
    buffer = NULL;
  } while (countHttpRequestEndings(*msg_ptr) < required_endings_amount);
}

void assignThread(Thread *thread, char **request_ptr, char **response_ptr)
{
  stringCopy(&(thread->request), request_ptr);
  thread->busy = true;
  while (thread->busy) {
    continue;
  }
  stringCopy(response_ptr, &(thread->response));
  free(thread->request);
  thread->request = NULL;
  free(thread->response);
  thread->response = NULL;
}

void *threadExecution(void *args)
{
  Thread *thread = args;
  while (!thread->connected) {
    thread->pc_socket = acceptConnection(thread->lb_socket);
    thread->connected = true;
  }
  while (true) {
    if (!thread->busy) {
      continue;
    }
    send(thread->pc_socket, thread->request, strlen(thread->request), 0);
    receiveMsg(thread->pc_socket, &(thread->response), 2);
    thread->busy = false;
  }
}

void threadsCreation(LoadBalancer *lb)
{
  for (int i = 0; i < NUMBER_OF_SERVERS; i++) {
    Thread *thread = lb->threads[i];
    pthread_create(&thread->tid, NULL, threadExecution, thread);
  }
}

void threadsTermination(LoadBalancer *lb)
{
  for (int i = 0; i < NUMBER_OF_SERVERS; i++) {
    while ((lb->threads[i])->busy) {
      continue;
    }
    pthread_join(lb->threads[i]->tid, NULL);
    pthread_join(((lb->threads)[i])->tid, NULL);
  }
}

void writeNumToFile(char *filename, int num)
{
  FILE *fp = fopen(filename, "w");
  assert(fp);
  fprintf(fp, "%d", num);
  fclose(fp);
}

int main()
{
  LoadBalancer *lb = initLoadBalancer();
  threadsCreation(lb);
  writeNumToFile("server_port", lb->server_port);
  writeNumToFile("http_port", lb->http_port);
  char *request = NULL, *response = NULL;
  int cur_pc = 0;
  while (true) {
    lb->user_socket = acceptConnection(lb->lb_socket);
    receiveMsg(lb->user_socket, &request, 1);
    Thread *thread = lb->threads[cur_pc];
    cur_pc = (cur_pc + 1) % NUMBER_OF_SERVERS;
    assignThread(thread, &request, &response);
    send(lb->user_socket, response, strlen(response), 0);
    free(request);
    request = NULL;
    free(response);
    response = NULL;
  }
  close(lb->lb_socket);
  threadsTermination(lb);
  freeLoadBalancer(lb);
  return 0;
}
