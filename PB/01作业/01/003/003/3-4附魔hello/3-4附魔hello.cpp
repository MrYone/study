// 3-4附魔hello.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int fun1()
{
	printf("0x222222");
	return 0;
}

int fun()
{
	int p[1] = { 0 };
	p[3] = (int)fun1;
	return 0;

}

int _tmain(int argc, _TCHAR* argv[])
{
	fun();
	printf("Hello");
	return 0;
}

