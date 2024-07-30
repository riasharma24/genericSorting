#include<tm_sorting.h>
#include<stdio.h>
#include<stdlib.h>

int myComparator(void *a, void* b)
{
int *left=(int*)a;
int *right=(int*)b;
return *left-*right;
}

int main()
{
int *x;
int i,n;
printf("Enter the size of the array : ");
scanf("%d",&n);
x=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter the %dth element : ",i);
scanf("%d",&x[i]);
}
printf("Sorting the elements.\n");
quickSort(x,n,sizeof(int),myComparator);
for(i=0;i<n;i++)
{
printf("%d\n",x[i]);
}
return 0;
}