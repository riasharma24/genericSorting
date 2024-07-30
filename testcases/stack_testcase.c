#include<stdio.h>
#include<tm_utils.h>
#include<stdlib.h>


int main()
{
Stack *stk=(Stack*)malloc(sizeof(Stack));
int x;
int *y;
initStack(stk,sizeof(int));
for(x=0;x<10;x++)
{
push(stk,&x);
}
printf("Size of stack : %d\n",(stk->size));
for(x=0;x<10;x++)
{
pop(stk,y);
printf("element : %d\n",(*y));
}
return 0;
}