#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

# define UPPER_BOUND 64000
# define LOWER_BOUND 1024

int gen_random_port()
{
    struct timeval te; 
    gettimeofday(&te, NULL);
    long long r = te.tv_sec * te.tv_usec;
    int port = (1+LOWER_BOUND) + (r%(UPPER_BOUND-LOWER_BOUND-1));
    return port;
}

void get_free_port(int* port_ptr, int* sock_ptr)
{
    do
    {
        *port_ptr = gen_random_port();
        *sock_ptr = createSocket(*port_ptr);
    } while (*sock_ptr == -1);
}
