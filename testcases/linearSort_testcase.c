#include<tm_sorting.h>
#include<stdio.h>
#include<stdlib.h>

int myComparator(void* left,void *right)
{
int *a,*b;
a=(int*)left;
b=(int*)right;
return (*a)-(*b);
}

int main()
{
int *x;
int n,i;
printf("Enter the size of array : ");
scanf("%d",&n);
x=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter %dth element : ",i);
scanf("%d",&x[i]);
}
printf("Calling the sort function.\n");
linearSort(x,n,sizeof(x[0]),myComparator);
for(i=0;i<n;i++)
{
printf("%d\n",x[i]);
}
return 0;
}