#include "time.h"
#include "stdlib.h"
#include <stdio.h>

int main(){
	int a1,a2,a3;
	int *p1,*p2,*p3;

	p1 = &a1;
	p2 = &a2;
	p3 = &a3;

	printf("enter 3 num : ");

	scanf("%d %d %d",p1,p2,p3);

	//min
	printf("%d < ",(*p1 < *p2 ? *p1 : *p2) < *p3 ? (*p1 < *p2 ? *p1 : *p2) : *p3);

	//mid
	if(((*p1 < *p2 ? *p1 : *p2) < *p3 ? (*p1 < *p2 ? *p1 : *p2) : *p3 ) < *p1 && *p1 < ((*p1 > *p2 ? *p1 : *p2) > *p3 ? (*p1 > *p2 ? *p1 : *p2) : *p3))
		printf("%d < ",*p1);

	if(((*p1 < *p2 ? *p1 : *p2) < *p3 ? (*p1 < *p2 ? *p1 : *p2) : *p3 ) < *p2 && *p2 < ((*p1 > *p2 ? *p1 : *p2) > *p3 ? (*p1 > *p2 ? *p1 : *p2) : *p3))
		printf("%d < ",*p2);

	if(((*p1 < *p2 ? *p1 : *p2) < *p3 ? (*p1 < *p2 ? *p1 : *p2) : *p3 ) < *p3 && *p3 < ((*p1 > *p2 ? *p1 : *p2) > *p3 ? (*p1 > *p2 ? *p1 : *p2) : *p3))
		printf("%d < ",*p3);

	//max
	printf("%d \n",(*p1 > *p2 ? *p1 : *p2) > *p3 ? (*p1 > *p2 ? *p1 : *p2) : *p3);

	return 0;
}
