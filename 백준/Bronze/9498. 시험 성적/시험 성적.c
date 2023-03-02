#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int ivalue;
    scanf("%d",&ivalue);
    
    if(ivalue>=90)
        printf("A\n");     
    else if(ivalue>=80)
        printf("B\n");
    else if(ivalue>=70)
        printf("C\n");
    else if(ivalue>=60)
        printf("D\n");
    else
        printf("F\n");
        
        return 0;
}