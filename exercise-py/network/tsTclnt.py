#!/usr/bin/python

import sys
from socket import *


HOST = '127.0.0.1'
PORT = 21568
BUFSIZ = 1024


def usage():
    print 'usage: tsTclint $host $port'

nargv = len(sys.argv)
if nargv > 3 or nargv == 2:
    usage()
elif nargv == 3:
    ADDR = (sys.argv[1], int(sys.argv[2]))
else:
    ADDR = (HOST, PORT)


tcpClisock = socket(AF_INET, SOCK_STREAM)
tcpClisock.connect(ADDR)

while True:
    data = raw_input('> ')
    if not data:
        break
    tcpClisock.send(data)
    data = tcpClisock.recv(BUFSIZ)
    if not data:
        break
    print data

tcpClisock.close()