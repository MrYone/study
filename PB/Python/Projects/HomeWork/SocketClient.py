#!/usr/local/bin/python3.6

import socket

def main() :
    print('Socket Client Start')
    #create socket
    cSock = socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
    #Connect
    host = socket.gethostname()
    port = 12346
    cSock.connect(('127.0.0.1',port))
    #send,recv
    while True :
        print(cSock.recv(1024).decode('utf-8'))
        inStr = input('Client > : ')
        if(inStr == 'quit') :
            break
        cSock.send(inStr.encode('utf-8'))

    cSock.close()

if __name__ == '__main__' :
    main()