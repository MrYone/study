// 3-2修改父函数的变量.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int fun()
{
	int  p[1] = {};
	p[0x39] = 0x9999999;
	return 0;

}


int _tmain(int argc, _TCHAR* argv[])
{
	char buff[] = "hello";
	fun();
	printf(buff);
	return 0;
}

