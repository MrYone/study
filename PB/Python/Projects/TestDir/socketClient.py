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
    other=0

def RecvThread(sock):
    try:
        while True:
            messageHead = sock.recv(12)
            type, = struct.unpack('i', messageHead[:4])
            lenth, = struct.unpack('i', messageHead[4:8])
            print(type, lenth)
            message = sock.recv(lenth)
            text = message.decode('gb2312')
            print(text)
    except ConnectionResetError as e:
        exit(0)

#============================================接收消息

#==============================================交互界面
print('=============ChatRoom-Client_@technical supportPython=============')
print('1.注册账号')
print('2.登陆')
print('0.退出')
#==============================================连接服务器

HOST='192.168.1.148'
PORT=12345
ADDR=(HOST,PORT)
#clientSocket = socket.socket()
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect(ADDR)

messageHead = clientSocket.recv(12)
type, = struct.unpack('i', messageHead[:4])
lenth, = struct.unpack('i', messageHead[4:8])
print(type, lenth)
message = clientSocket.recv(lenth)
text = message.decode('gb2312')
print(text)



clientSocket.close()

'''
try:
    t1 = threading.Thread(target=RecvThread, args=(clientSocket,))
    t1.start()
except:
    print('线程开启错误')


clientSocket.close()
'''