#include<stdio.h>
int main()
{
    int n,i,a[10];
    printf("Enter the number of elemnts");
    scanf("%d",&n);
    printf("Emter the array elements");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("The array  is ");
      for(i=0;i<n;i++)
      printf("%d ",a[i]);
    return 0;
}
