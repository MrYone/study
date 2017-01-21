#include "iostream"
#include "stdio.h"

using namespace std;
int max(int a , int b){
	return (a > b ? a : b);
}

int min(int a , int b){
	return (a > b ? b : a);
}

int sum(int a , int b){
	return a + b;
}

int fun(int a , int b , int (*call)(int , int)){
//int fun(int a , int b , auto (*call)(int ,int) -> int){ //不能这么写
	return (call(a,b));
}

int main(){

	printf("max = %d\n",fun(1,2,max));
	printf("min = %d\n",fun(3,4,min));
	printf("sum = %d\n",fun(5,6,sum));

	return 0;
}