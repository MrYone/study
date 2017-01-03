#include "stdio.h"
#define MAXSIZE 100
int main (){
	char a[MAXSIZE];

	printf("enter a string: ");

	scanf("%s",a);

	printf("\n\t");

	for(int i = 0; a[i] != '\0';i++)
		printf("%c",a[i] + 1);

	printf("\n");
	
	return 0;
}

