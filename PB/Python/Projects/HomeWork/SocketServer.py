#!/usr/local/bin/python3.6

import socket,threading,time

def recv(cSock) :
    while True :
        print(cSock.recv(1024).decode('utf-8'))

def send(cSock) :
    name = 123
    inStr = ''
    while True :
        inStr = input(name + ' > ')
        cSock.send(inStr.encode('utf-8'))
        if (inStr == 'quit'):
            break
    print(name + ' Lost')
    cSock.close()

def main() :
    print('Socket Server Start')

    #creat socket
    sSock = socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
    #bind
    sSock.bind(('127.0.0.1',12346))
    #listen
    sSock.listen(5)
    #accept,thread
    while True :

        cSock,addr = sSock.accept()

        #print('Link Success')
        #cSock.send('Welcome: '.encode('utf-8'))
        #send,recv
        #while True :
          #  print(cSock.recv(1024).decode('utf-8'))

          #  inStr = input('Server > : ')
          #   if(inStr == 'quit') :
          #      break

         #   cSock.send(inStr.encode('utf-8'))

        #cSock.close()

if __name__ == '__main__' :
    main()