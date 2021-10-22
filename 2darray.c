#include<stdio.h>
int main()
{
    int n,m,i,j,a[10][10];
    printf("Enter the number of elemnts");
    scanf("%d%d",&n,&m);
    printf("Emter the array elements");
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf("%d",&a[i][j]);
    printf("The array  is ");
      for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
      printf("%d ",a[i][j]);
      printf("\n");
     }
    return 0;
}
