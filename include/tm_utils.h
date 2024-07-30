#ifndef __tm_utils__h
#define __tm_utils__h

typedef struct __stack_node
{
void *ptr;
struct __stack_node *next;
}StackNode;

typedef struct __stack
{
int elementSize;
int size;
struct __stack_node *top;
}Stack;

typedef struct __queue_node
{
void* ptr;
struct __queue_node* next;
}QueueNode;

typedef struct __queue
{
int elementSize;
int size;
struct __queue_node *front;
struct __queue_node *rear;
}Queue;

void flip(void *x,int cs,int es);

//For stack
void initStack(Stack *stack,int elementSize);
void push(Stack* stack,void *ptr);
void pop(Stack* stack,void *ptr);
int isStackEmpty(Stack *stack);

//For queue
void initQueue(Queue* queue,int elementSize);
void enqueue(Queue* queue,void* ptr);
void dequeue(Queue* queue,void* ptr);
int isQueueEmpty(Queue *queue);

//binary search that returns index if elem found and probable index if not found
int binary_search(void *x,void* target,int high,int low,int elementSize,int(*p2f)(void*,void*));


#endif