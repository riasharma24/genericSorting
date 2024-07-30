#include<stdio.h>
#include<stdlib.h>
#include<tm_sorting.h>

int myComparator(void *a,void *b)
{
int *left=(int*)a;
int *right=(int*)b;
return *left-*right;
}

int main()
{
int i,n;
int *x;
printf("Enter the size of array : ");
scanf("%d",&n);
x=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter a number : ");
scanf("%d",&x[i]);
}
printf("Sorting the numbers\n");
pigeonHoleSort(x,n,sizeof(int),myComparator);
for(i=0;i<n;i++)
{
printf("%d\n",x[i]);
}
return 0;
}