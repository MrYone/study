#!/usr/local/bin/python3.6

import threading
import socket
import struct
#线程回调函数，接收消息
def Threadfun(pSock):
    while True:
        try:
            #获取消息
            Messages=pSock.recv(1074)
            #获取消息的结构体
            name,msg= struct.unpack('50s1024s',Messages)
            #获取到的数据需要解码
            print(name.decode('gb2312'),msg.decode('gb2312'))
        except:
            print('获取失败')


def main():

    #1.创建socket
    sSock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    host=('127.0.0.1',1234)

    #2.发起链接
    sSock.connect(host)

    print('链接成功！')

    #开启线程,1.回调函数，2.元组参数
    try:
        #线程需要启动用start
        t1=threading.Thread(target=Threadfun,args=(sSock,))
        t1.start();
    except:
        print('错误')
    name = input('注册名字>>:')

    while True:
        #等待消息

        msg = input('消息>>:')
            #发送消息
        #打包错误
        packdata = struct.pack('50s1024s',name.encode('gb2312'),msg.encode('gb2312'))

        try:
            sSock.send(packdata)
        except:
            print('断开服务')
            break

    #关闭套接字
    sSock.close()
if __name__=='__main__':
    main()




