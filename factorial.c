#include<stdio.h>
int fact(int n)
{
    if(n<=1)
    return 1;
    else
    return n*fact(n-1);
    
}
void main() 
{
    int a;
    printf("Enter the no");
    scanf("%d",&a);
    printf("Fact is %d",fact(a));
}
