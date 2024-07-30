#include<stdio.h>
#include<stdlib.h>
#include<tm_utils.h>

int main()
{
int x;
int *y;
Queue *q=(Queue*)malloc(sizeof(Queue));
initQueue(q,sizeof(int));
for(x=0;x<10;x++)
{
enqueue(q,&x);
}
printf("Size of queue : %d\n",q->size);
for(x=0;x<10;x++)
{
dequeue(q,y);
printf("%d\n",*y);
}


return 0;
} 