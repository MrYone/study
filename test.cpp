#include <stdio.h>
 
int add1(int a1,int b1);
int add2(int a2,int b2);
 
int main(void)
{
    int numa1 = 1, numb1 = 2;
    int numa2 = 2, numb2 = 3;
    int(*op[2])(int a,int b);
     
    op[0] = add1;
    op[1] = add2;
     
    printf("%d\t%d\n", op[0](numa1, numb1), op[1](numa2, numb2));

	return 0;
}
 
int add1(int a1,int b1)
{
    return a1 + b1;
}
 
int add2(int a2,int b2)
{
    return a2 + b2;
}
