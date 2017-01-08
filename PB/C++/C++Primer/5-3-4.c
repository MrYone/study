#include "time.h"
#include "stdlib.h"
#include <stdio.h>

int main(){
	int arr[40][40] = {0};

	for ( int i = 0; i < 40; i++){
		arr[0][i] = arr[i][0] = arr[39][i] = arr[i][39] = 1;
	}

	for(int i = 0; i < 40; i++){
		for(int j = 0; j < 40; j++){
			if(arr[i][j] == 1)
				printf("□");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
