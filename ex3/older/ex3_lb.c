#include <arpa/inet.h>
#include <assert.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define UPPER_PORT_BOUND 64000
#define LOWER_PORT_BOUND 1024
#define BUFFER_SIZE 1024
#define NUMBER_OF_SERVERS 1

bool isSubstringAtIndex(char* str, char* sub, int start)
{
    for (int i=start; i<(int) strlen(sub); i++){
        if (str[i] != sub[i]){
            return false;
        }
    }
    return true;
}

int countSubstringOccurrences(char* str, char* sub)
{
    int count = 0, str_len = strlen(str), sub_len = strlen(sub);
    if (str_len < sub_len){
        return 0;
    }
    for (int i=0; i<str_len-sub_len+1; i++){
        if (isSubstringAtIndex(str, sub, i)){
            count++;
        }
    }
    return count;
}

bool receiveMsg(char** msg_ptr, int* client_socket_ptr, int required_endings)
{
    char buffer[BUFFER_SIZE+1];
    free(*msg_ptr);
    *msg_ptr = NULL;
    *msg_ptr = (char*) calloc (BUFFER_SIZE+1, sizeof(char));
    assert(*msg_ptr);
    int cur_size = BUFFER_SIZE+1;
    int cur_recv_bytes;
    do
    {
        memset(buffer, 0, BUFFER_SIZE+1);
        do
        {
            printf("buffer = %s\n", buffer);
            cur_recv_bytes = recv(*client_socket_ptr, buffer, BUFFER_SIZE, 0);
            printf("2\n");
            if (cur_recv_bytes <= 0){
                free(*msg_ptr);
                *msg_ptr = NULL;
                return false;
            }
        } while (cur_recv_bytes == 0);        
        cur_size = cur_size + BUFFER_SIZE;
        *msg_ptr = (char*) realloc (*msg_ptr, cur_size);
        assert(*msg_ptr);
        strcat(*msg_ptr, buffer);
    } while (countSubstringOccurrences(*msg_ptr, "\r\n\r\n") < required_endings);
    return true;
}

void writePortToFile(char* filename, int num)
{
	FILE* fp = fopen(filename, "w");
	assert(fp);
	fprintf(fp, "%d", num);
	fclose(fp);
	fp = NULL;
}

int createSocket(int port)
{
    int sock;
    struct sockaddr_in server;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
		return -1;
    }
    bzero((char*)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        return -1;
    }
    if (listen(sock , 3) < 0)
	{
        return -1;
	}
    return sock;
}

void initSocket(int* port_ptr, int* server_sock_ptr)
{
    struct timeval te; 
	do
    {
        gettimeofday(&te, NULL);
        *port_ptr = (1+LOWER_PORT_BOUND) + ((te.tv_sec*te.tv_usec)%(UPPER_PORT_BOUND-LOWER_PORT_BOUND-1));
        *server_sock_ptr = createSocket(*port_ptr);
    } while (*server_sock_ptr == -1);
}

int main() {
    int pc_port, pc_server_socket, pc_client_socket;
    struct sockaddr_in pc_address;
    socklen_t pc_address_size=sizeof(pc_address);
    initSocket(&pc_port, &(pc_server_socket));
    writeNumToFile("server_port", pc_port);

    int user_port, user_server_socket, user_client_socket;
    struct sockaddr_in user_address;
    socklen_t user_address_size=sizeof(user_address);
    initSocket(&user_port, &user_server_socket);
    writeNumToFile("http_port", user_port);
    char *request=NULL, *response=NULL;
    int cur_pc = 0;
    while (true)
    {
        free(request);
        request = NULL;
        free(response);
        response = NULL;

        assert((user_client_socket = accept(user_server_socket, (struct sockaddr*)&user_address, &user_address_size)) >=0);
        if (!receiveMsg(&request, &user_client_socket, 1)){
            continue;
        }
        printf("request = %s", request);
        assert(shutdown(user_server_socket, SHUT_RD) != -1);

        assert((pc_client_socket = accept(pc_server_socket, (struct sockaddr*)&pc_address, &pc_address_size)) >= 0);
        send(pc_client_socket, request, strlen(request), 0);
        if (!receiveMsg(&response, &(pc_client_socket), 2)){
            continue;
        }
        printf("response = %s", response);
        send(pc_client_socket, response, strlen(response), 0);
        cur_pc = (cur_pc+1)%NUMBER_OF_SERVERS;

        close(pc_client_socket);
        close(pc_server_socket);
        close(user_client_socket);
        close(user_server_socket);
        free(request);
        request = NULL;
        free(response);
        response = NULL;
    }
    return 0;
}
