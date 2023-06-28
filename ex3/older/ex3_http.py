#!/usr/bin/python2.7 -tt
import socket
import sys

SERVER_ADDRESS = '127.0.0.1'
BUFFER_SIZE = 1024

def main():
    if len(sys.argv) == 1:
        with open("http_port", "r") as f:
            for line in f:
                server_port = int(line.rstrip())
    else:
        server_port = int(sys.argv[1])
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((SERVER_ADDRESS, server_port))

    # Send data to server
    request = \
    """GET /counter HTTP/1.1\r
    Host: nova.cs.tau.ac.il\r
    Connection: keep-alive\r
    Cache-Control: max-age=0\r
    Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r
    User-Agent: Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.57 Safari/537.36\r
    Accept-Encoding: gzip,deflate,sdch\r
    Accept-Language: en-US,en;q=0.8,he;q=0.6\r\n\r\n"""
    
    print("sending request")
    client_socket.send(request.encode('utf-8'))
    print("request sent")

    # Receive response from server
    response = b''
    while (True):
        print("recv")
        response += client_socket.recv(1024)
        if response.count(b'\r\n\r\n') == 2:
            break

    print("response:\n", response)


    # Close socket
    client_socket.close()

if __name__ == '__main__':
    for i in range(2):
        main()
