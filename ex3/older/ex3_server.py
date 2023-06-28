#!/usr/bin/python2.7 -tt
import socket
import sys

SERVER_ADDRESS = '127.0.0.1'
addresses_dic = {}

if len(sys.argv) == 1:
    with open("server_port", "r") as f:
        for line in f:
            server_port = int(line.rstrip())
else:
    server_port = int(sys.argv[1])
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((SERVER_ADDRESS, server_port))

while (True):
    request = b''
    while (True):
        print("recv")
        request += client_socket.recv(1024)
        if request.count(b'\r\n\r\n') == 1:
            break

    print("request", request)
    address = (request.split())[1]
    if address not in addresses_dic:
        addresses_dic[address] = 0
    addresses_dic[address] += 1    
    content = str(addresses_dic[address])
    content_length = len(content)
    response = \
    f'HTTP/1.0 200 OK\r\nContent-Type: text/html\r\nContent-Length: {content_length}\r\n\r\n{content}\r\n\r\n'
    
    print("sending response")
    client_socket.send(response.encode('utf-8'))
    print("response sent")

client_socket.close()
