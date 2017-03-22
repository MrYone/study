#!/usr/local/bin/python3.6

import threading
from socket import *
from enum import Enum
import struct

class Message(Enum):#建立类模拟枚举
    sendRegister = 1
    sendLogin=2
    sendMessage_room=3
    sendPic_room=4
    sendMessage_sing1=5
    sendPic_sing1=6
    getUserList=7
    getFirendList=8
    addFriends=9
    other=10
    e_error = 11

def sendThread(clientSocket):
    try:
        while True:
            userMessage = username + " : > " + input()
            if(userMessage == username + " : > " + "exit()"):
                clientSocket.close()
                break
            clientSocket.send(struct.pack('iid', 3, len(userMessage) + 1, 0))
            clientSocket.send(userMessage.encode('gb2312'))
        return
    except ConnectionResetError as e:
        clientSocket.close()
        return

#============================================接收消息
def recvThread(clientSocket):
    try:
        while True:
            messageHead = clientSocket.recv(16)
            type, = struct.unpack('i', messageHead[:4])
            lenth, = struct.unpack('i', messageHead[4:8])
            # print(type,lenth)
            message = clientSocket.recv(lenth)
            text = message.decode('gb2312')
            print(text)
    except:
        return

#==============================================交互界面
print('=============ChatRoom-Client_@technical supportPython=============')
#==============================================连接服务器

HOST='10.211.55.4'
PORT=12345
ADDR=(HOST,PORT)
#clientSocket = socket.socket()
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect(ADDR)

#接受消息
messageHead = clientSocket.recv(16)
type, = struct.unpack('i', messageHead[:4])
lenth, = struct.unpack('i', messageHead[4:8])
#print(type,lenth)
message = clientSocket.recv(lenth)
text = message.decode('gb2312')
print(text)

#发送用户名
username = input("username: > ")
login = struct.pack('iid',2,len(username)+1,0)
clientSocket.send(login)
clientSocket.send(username.encode('gb2312'))

#发送密码
passwd = input("passwd: > ")
login1 = struct.pack('iid',2,len(passwd)+1,0)
clientSocket.send(login1)
clientSocket.send(passwd.encode('gb2312'))

#接受服务器回显
messageHead = clientSocket.recv(16)
type, = struct.unpack('i', messageHead[:4])
lenth, = struct.unpack('i', messageHead[4:8])
#print(type,lenth)
message = clientSocket.recv(lenth)
text = message.decode('gb2312')
print(text)

#input()

if type == 11:
    clientSocket.close()
    exit(0)
else :
    try:
        t1 = threading.Thread(target=sendThread, args=(clientSocket,))
        t1.start()
    except:
        print('线程开启错误')
        clientSocket.close()
        exit(0)

    try:
        t2 = threading.Thread(target=recvThread, args=(clientSocket,))
        t2.start()
    except:
        print('线程开启错误')
        clientSocket.close()
        exit(0)

    t1.join()

    clientSocket.close()

'''
try:
    t1 = threading.Thread(target=RecvThread, args=(clientSocket,))
    t1.start()
except:
    print('线程开启错误')


clientSocket.close()
'''