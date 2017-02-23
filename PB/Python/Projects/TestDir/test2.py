#!/usr/local/bin/python3.6

#################################################################
# 第一个注释
print("Hello, Python!") # 第二个注释

#################################################################
if True:
    print("True")
else:
    print("False")

#################################################################
total = ['one' , 'two']
print(total)

#################################################################
print(r'hello world \n') #此处会显示\n

#################################################################
paragraph = """这是一个段落，
可以由多行组成"""
print(paragraph)

#################################################################
import sys; x = 'runoob'; sys.stdout.write(x + '\n')

#################################################################
a ,b , c = 1, 2, 'test'
print(a)
print(b)
print(c)

c = 1,2,'test'
print(c)
#################################################################
#Number（数字）

#################################################################
#string（字符串）
str = 'Runoob'

print (str)          # 输出字符串
print (str[0:-1])    # 输出第一个个到倒数第二个的所有字符
print (str[0])       # 输出字符串第一个字符
print (str[2:5])     # 输出从第三个开始到第五个的字符
print (str[2:])      # 输出从第三个开始的后的所有字符
print (str * 2)      # 输出字符串两次
print (str + "TEST") # 连接字符串

#################################################################
#List（列表）
List = [ 'abcd', 786 , 2.23, 'runoob', 70.2 ]
tinylist = [123, 'runoob']

print (List)            # 输出完整列表
print (List[0])         # 输出列表第一个元素
print (List[1:3])       # 从第二个开始输出到第三个元素
print (List[2:])        # 输出从第三个元素开始的所有元素
print (tinylist * 2)    # 输出两次列表
print (List + tinylist) # 连接列表
print ("%s | %s" % (List[0], List[1]))

ListA = list(range(10))
print (ListA)
print (ListA[:7:])


#################################################################
#Tuple（元组）
tuple = ( 'abcd', 786 , 2.23, 'runoob', 70.2  )
tinytuple = (123, 'runoob')

print (tuple)             # 输出完整元组
print (tuple[0])          # 输出元组的第一个元素
print (tuple[1:3])        # 输出从第二个元素开始到第三个元素
print (tuple[2:])         # 输出从第三个元素开始的所有元素
print (tinytuple * 2)     # 输出两次元组
print (tuple + tinytuple) # 连接元组

#################################################################
#Sets（集合）
student = ({'Tom', 'Jim', 'Mary', 'Tom', 'Jack', 'Rose'})

print(student)   # 输出集合，重复的元素被自动去掉

# 成员测试
if('Rose' in student) :
    print('Rose 在集合中')
else :
    print('Rose 不在集合中')


# set可以进行集合运算
a = set('abracadabra')
b = set('alacazam')

print(a)

print(a - b)     # a和b的差集

print(a | b)     # a和b的并集

print(a & b)     # a和b的交集

print(a ^ b)     # a和b中不同时存在的元素

#################################################################
#Dictionary（字典）
dict = {}
dict['one'] = "1 - 菜鸟教程"
dict[2]     = "2 - 菜鸟工具"

tinydict = {'name': 'runoob','code':1, 'site': 'www.runoob.com'}


print (dict['one'])       # 输出键为 'one' 的值
print (dict[2])           # 输出键为 2 的值
print (tinydict)          # 输出完整的字典
print (tinydict.keys())   # 输出所有键
print (tinydict.values()) # 输出所有值

import zipfile

