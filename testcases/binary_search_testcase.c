#include<stdio.h>
#include<stdlib.h>
#include<tm_utils.h>

int p2f(void *left, void* right)
{
int* l=(int*)left;
int* r=(int*)right;
return (*l)-(*r);
}

int main()
{
int *x;
int n,i,num;
printf("Enter the size of the array : ");
scanf("%d",&n);
x=(int*)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
{
printf("Enter an element : ");
scanf("%d",&x[i]);
}
printf("Enter the number to search : ");
scanf("%d",&num);
i=binary_search(x,&num,n-1,0,sizeof(int),p2f);
printf("Index is : %d\n",i);
return 0;
}