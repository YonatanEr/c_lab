from socket import *
s1 = socket()
s1.connect(('www.google.com', 80))
print(s1.send(str.encode('GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n')))
print(s1.recv(1024))

print()

s2 = socket()
s2.bind(('', 12345))
s2.listen(10) 
print(s2.accept())
