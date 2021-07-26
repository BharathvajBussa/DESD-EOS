#include<stdio.h>
#include"arith.h"

int main()
{
    int sum=0;
    int diff=0;
    sum=add(20,10);
    printf("addition is %d",sum);
    diff=sub(20,10);
    printf("subtraction is %d",diff);
    return 0;
}