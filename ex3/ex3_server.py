#!/usr/bin/python2.7 -tt

import socket
import sys

def update_addresses_dic(addresses_dic, address):
    if address not in addresses_dic:
        addresses_dic[address] = 0
    addresses_dic[address] = addresses_dic[address] + 1

def build_response(addresses_dic, address):
    if address == b'/counter':
        content = str(addresses_dic[address])
        content_length = len(content)
        response_str = \
        "HTTP/1.0 200 OK\r\n" +\
        "Content-Type: text/html\r\n" +\
        "Content-Length: " + str(content_length) + "\r\n" +\
        "\r\n" +\
        content + "\r\n" +\
        "\r\n"
    else:
        response_str = \
        "HTTP/1.1 404 Not Found\r\n" +\
        "Content-type: text/html\r\n" +\
        "Content-length: 113\r\n" +\
        "\r\n" +\
        "<html><head><title>Not Found</title></head><body>\r\n" +\
        "Sorry, the object you requested was not found.\r\n" +\
        "</body></html>\r\n" +\
        "\r\n"
    return bytearray(response_str, "utf-8")

def main():
    if len(sys.argv) == 1:
        with open("server_port", "r") as f:
            for line in f:
                server_port = int(line.rstrip())
    else:
        server_port = int(sys.argv[1])
    pc_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    pc_socket.connect(("localhost", server_port))
    addresses_dic = {}
    while (True):
        request = b''
        while (True):
            request += pc_socket.recv(1024)
            if request.count(b"\r\n\r\n") == 1:
                break
        address = request.split(b" ")[1]
        update_addresses_dic(addresses_dic, address)
        response = build_response(addresses_dic, address)
        pc_socket.send(response)
    client_socket.close()


if __name__ == "__main__":
    main()