#!/usr/bin/python2.7 -tt

import sys
from socket import *
import random
import time

def get_split_point(request):
    if random.choice([True, False]):
        return random.randint(-4, -1)
    return random.randint(0, len(request))

if len(sys.argv) == 1:
    with open("http_port", "r") as f:
        for line in f:
            port = int(line.rstrip())
else:
    port = int(sys.argv[1])

request = \
b"""GET /dounter HTTP/1.1\r
Host: nova.cs.tau.ac.il\r
Connection: keep-alive\r
Cache-Control: max-age=0\r
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r
User-Agent: Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.57 Safari/537.36\r
Accept-Encoding: gzip,deflate,sdch\r
Accept-Language: en-US,en;q=0.8,he;q=0.6\r\n\r\n"""

s = socket()
s.connect(('localhost', port))
first_part_len = get_split_point(request)
s.send(request[:first_part_len])
time.sleep(0.1)
s.send(request[first_part_len:])

response = b''
while 1:
    response += s.recv(1024)
    if response.count(b'\r\n\r\n') == 2:
        break

print("response:\n", response)
lines = response.split(b'\r\n')
assert len(lines) == 7
assert lines[0] == b'HTTP/1.0 200 OK'
assert lines[1] == b'Content-Type: text/html'
assert lines[2].startswith(b'Content-Length: ')
content_length = int(lines[2][len(b"Content-Length: "):])
assert lines[3] == b''

assert len(lines[4]) == content_length
content = lines[4]
assert lines[-2:] == [b'', b'']

print(content)
