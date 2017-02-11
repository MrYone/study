#include "iostream"
#include "stdio.h"

using namespace std;

int fun(int a , int b , int (*call)(int , int));

int main(){

	//auto max = [=](int a , int b){return (a > b ? a : b);}
	int(*min)(int,int) = [](int a , int b){return (a > b ? b : a);};
	//auto sum = [](int a , int b){return a + b;}


	//printf("max = %d\n",fun(1,2,[](int a , int b)->int{return (a > b ? a : b);}));
	printf("min = %d\n",fun(3,4,min));
	//printf("sum = %d\n",fun(5,6,sum));

	return 0;
}

int fun(int a , int b , int (*call)(int , int)){
//int fun(int a , int b , auto (*call)(int ,int) -> int){ //不能这么写
	return (call(a,b));
}