#ifndef __tm_utils__c
#define __tm_utils__c
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<tm_utils.h>

void flip(void *x,int cs,int es)
{
void *g,*a,*b;
int i,j;
i=0;
j=cs-1;
g=(void*)malloc(es);
while(i<j)
{
a=x+(es*i);
b=x+(es*j);
memcpy(g,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)g,es);
i++;
j--;
}
free(g);
}

void initStack(Stack *stack,int elementSize)
{
stack->top=NULL;
stack->elementSize=elementSize;
stack->size=0;
}

void push(Stack* stack,void *ptr)
{
StackNode *t=(StackNode*)malloc(sizeof(StackNode));
t->ptr=(void*)malloc(stack->elementSize);
memcpy(t->ptr,(const void*)ptr,stack->elementSize);
t->next=stack->top;
stack->top=t;
stack->size++;
}

void pop(Stack* stack,void *ptr)
{
StackNode *t=stack->top;
memcpy(ptr,(const void*)t->ptr,stack->elementSize);
stack->top=stack->top->next;
free(t->ptr);
free(t);
stack->size--;
}

int isStackEmpty(Stack *stack)
{
return stack->size==0;
}

void initQueue(Queue* queue,int elementSize)
{
queue->front=NULL;
queue->rear=NULL;
queue->elementSize=elementSize;
queue->size=0;
}

void enqueue(Queue* queue,void* ptr)
{
QueueNode *t=(QueueNode*)malloc(sizeof(QueueNode));
t->ptr=(void*)malloc(queue->elementSize);
memcpy(t->ptr,(const void *)ptr,queue->elementSize);
if(queue->front==NULL && queue->rear==NULL)
{
queue->front=t;
queue->rear=t;
t->next=NULL;
queue->size++;
return;
}
queue->front->next=t;
queue->front=t;
t->next=NULL;
queue->size++;
}

void dequeue(Queue* queue,void* ptr)
{
QueueNode *t=queue->rear;
if(t==NULL)return;
queue->rear=queue->rear->next;
memcpy(ptr,(const void *)t->ptr,queue->elementSize);
free(t->ptr);
free(t);
queue->size--;
}

int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}

int binary_search(void *x,void* target,int high,int low,int elementSize,int(*p2f)(void*,void*))
{
int mid,w;
if(high<=low)
{
w=p2f(target,x+(low*elementSize));
if(w<0)
{
return low;
}
else return low+1;
}
mid=(high+low)/2;
w=p2f(x+(elementSize*mid),target);
if(w==0)
{
return mid+1;
}
if(w<0)
{
return binary_search(x,target,high,mid+1,elementSize,p2f);
}
if(w>0)
{
return binary_search(x,target,mid-1,low,elementSize,p2f);
}
}


#endif