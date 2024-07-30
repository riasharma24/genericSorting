#include<stdio.h>
#include<tm_utils.h>

int main()
{
int x[5]={1,2,3,4,5};
int i;
printf("Before flipping\n");
for(i=0;i<5;i++)printf("%d\n",x[i]);
printf("After flipping\n");
flip(x,5,sizeof(int));
for(i=0;i<5;i++)printf("%d\n",x[i]);
return 0;
}