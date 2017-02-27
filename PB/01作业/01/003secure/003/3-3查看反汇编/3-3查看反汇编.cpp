// 3-3查看反汇编.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void t_ifelse()
{
	int a = 1;
	if (a)
	{
		printf("if");
	}
	else
	{
		printf("else");
	}
}

void t_swicth(){
	int a = 1;
	switch (a)
	{
	case 0:
		printf("case 0");
		break;
	case 1:
		printf("case 1");
		break;
	default:
		break;
	}
}

void t_while(){

	int a = 0;
	while (a < 2)
	{
		a++;
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	t_ifelse();
	t_swicth();
	t_while();


	return 0;
}

