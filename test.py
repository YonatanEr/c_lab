#!/usr/bin/python2.7 -tt

import socket
from ctypes import *

class Payload(Structure):
    _fields_ = [("id", c_uint32),
                ("counter", c_uint32),
                ("temp", c_float)]


def main():
    port = 0
    with open("server_port") as f:
        for line in f:
            port = int(line.rstrip())
    server_addr = ('localhost', port)
    ssock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Socket created")

    try:
        # bind the server socket and listen
        ssock.bind(server_addr)
        print("Bind done")
        ssock.listen(100)

        while True:
            csock, client_address = ssock.accept()
            print("Accepted connection from {:s}".format(client_address[0]))

            buff = csock.recv(512)
            while buff:
                print("\nReceived {:d} bytes".format(len(buff)))
                payload_in = Payload.from_buffer_copy(buff)
                print("Received contents id={:d}, counter={:d}, temp={:f}".format(payload_in.id,
                                                            payload_in.counter,
                                                            payload_in.temp))
                print("Sending it back.. ", end='')
                nsent = csock.send(payload_in)
                print("Sent {:d} bytes".format(nsent))
                buff = csock.recv(512)

            csock.close()
    except KeyboardInterrupt:
        if ssock is not None:
            ssock.close()
            ssock = None
    finally:
        if ssock is not None:
            ssock.close()
            ssock = None


if __name__ == "__main__":
    main()









int gen_random_port()
{
    struct timeval te; 
    gettimeofday(&te, NULL);
    long long r = te.tv_sec * te.tv_usec;
    int port = 1+LOWER_BOUND+(r%(UPPER_BOUND-LOWER_BOUND-1));
    return port;
}

void get_free_port(int* port_ptr, int* sock_ptr)
{
    int sock;
    int port;
    do
    {
        port = gen_random_port();
        sock = createSocket(port);
    } while (sock == -1);
    *port_ptr = port;
    *sock_ptr = sock;
}

void write_num_to_file(char* filename, int num)
{
    FILE* fp = fopen(filename, "w");
    assert(fp);
    fprintf(fp, "%d", num);
    fclose(fp);
}