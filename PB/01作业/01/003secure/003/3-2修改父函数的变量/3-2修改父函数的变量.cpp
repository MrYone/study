// 3-2�޸ĸ������ı���.cpp : �������̨Ӧ�ó������ڵ㡣
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

