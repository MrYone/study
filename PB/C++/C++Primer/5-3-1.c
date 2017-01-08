#include "time.h"
#include "stdlib.h"
#include <stdio.h>

#define LENTH 10

int main(){
	
	int arr[LENTH] = {0};
	int *p = arr;

	printf("enter 10 num : ");
	
	for( int i = 0; i < 10; i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Your enter num: \n");
	for( int i = 0; i < 10; i++){
		printf("%d, ", *(p+i));
	}

	return 0;
}

