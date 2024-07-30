#ifndef __tm_sorting_c_
#define __tm_sorting_c_
#include<tm_sorting.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<tm_utils.h>

void linearSort(void *x,int cs,int es,int(*p2f)(void*,void*))
{
int e,f;
void *a,*b,*c;
int w=0;
c=(void*)malloc(es);
for(int e=0;e<=cs-2;e++)
{
for(int f=e+1;f<=cs-1;f++)
{
a=x+(es*e);
b=x+(es*f);
w=p2f(a,b);
if(w>0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
}
free(c);
}

void bubbleSort(void *x,int cs,int es,int(*p2f)(void*,void*))
{
int e,f,m,w=0;
void *a,*b,*c;
c=(void*)malloc(es);
for(m=cs-2;m>=0;m--)
{
e=0;
f=1;
while(e<=m)
{
a=x+(es*e);
b=x+(es*f);
w=p2f(a,b);
if(w>0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
e++;
f++;
}
}
free(c);
}

void selectionSort(void *x,int cs,int es, int(*p2f)(void*,void*))
{
int e,f,w=0;
void *a,*c,*smallest;
c=(void*)malloc(sizeof(int)*es);
for(e=0;e<=cs-1;e++)
{
a=x+(e*es);
smallest=x+(e*es);
for(f=e+1;f<=cs-1;f++)
{
w=p2f(smallest,(x+(es*f)));
if(w>0)smallest=x+(es*f);
}
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)smallest,es);
memcpy(smallest,(const void*)c,es);
}
free(c);
}

void insertionSort(void *x,int cs,int es, int(*p2f)(void*,void*))
{
int i,j;
void *num,*a;
num=(void*)malloc(es);
for(i=1;i<cs;i++)
{
a=x+(es*i);
memcpy(num,(const void*)a,es);
j=i-1;
while(j>=0 && (p2f(num,x+(es*j))<0))
{
memcpy(x+(es*(j+1)),(const void*)(x+(es*j)),es);
j--;
}
memcpy(x+(es*(j+1)),(const void *)num,es);
}
free(num);
}

void quickSort(void *x,int cs,int es,int(*p2f)(void*,void*))
{
int i,top,lb,ub,e,f,pp;
int **stk;
void *a,*b,*c;

//Declaring stack with rows=cs and columns=2

stk=(int**)malloc(es*cs);
for(i=0;i<cs;i++)stk[i]=(int*)malloc(es*2);
c=(void*)malloc(es);
top=cs;
top--;
stk[top][0]=0;
stk[top][1]=cs-1;
while(top<cs)
{
lb=stk[top][0];
ub=stk[top][1];
top++;
e=lb;
f=ub;
while(e<f)
{
while(e<=ub && p2f(x+(e*es),x+(lb*es))<=0)
{
e++;
}
while(p2f(x+(f*es),x+(lb*es))>0)
{
f--;
}
if(e<f)
{
a=x+(e*es);
b=x+(f*es);
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
else
{
a=x+(f*es);
b=x+(lb*es);
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
pp=f;
break;
}
}
if(pp+1<ub)
{
top--;
stk[top][0]=pp+1;
stk[top][1]=ub;
}
if(lb<pp-1)
{
top--;
stk[top][0]=lb;
stk[top][1]=pp-1;
}
}
}

void mergeSort(void *x,int cs,int es,int(*p2f)(void*,void*))
{



}

void pancakeSort(void *x,int cs,int es,int (*p2f)(void*,void*))
{
int largest;
int i,w,size=cs;
while(size>1)
{
largest=0;
for(i=1;i<size;i++)
{
w=p2f((x+(es*largest)),(x+(es*i)));
if(w<0)largest=i;
}
flip(x,largest+1,es);
flip(x,size,es);
size--;
}
}

void brickSort(void *x,int cs,int es,int (*p2f)(void*,void*))
{
int swapCount,i,j,e,f,w;
void *a,*b,*c;
c=(void*)malloc(es);
while(1)
{
swapCount=0;
for(i=1;i<=cs-2;i+=2)
{
j=i+1;
a=x+(es*i);
b=x+(es*j);
w=p2f(a,b);
if(w>0)
{
swapCount++;
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
for(e=0;e<=cs-2;e=e+2)
{
f=e+1;
a=x+(es*e);
b=x+(es*f);
w=p2f(a,b);
if(w>0)
{
swapCount++;
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
if(swapCount==0)break;
}
}

void countingSort(void *x,int cs,int es,int(*keyExtractor)(void*))
{
//to do

}


void gnomeSort(void* x,int cs,int es,int(*p2f)(void*,void*))
{
int j=0,w;
void *a,*b,*c;
c=(void*)malloc(es);
while(j!=cs)
{
if(j==0)j=j+1;
a=x+(j*es);
b=x+((j-1)*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
j--;
}
else
{
j++;
}
}
free(c);
}

void shellSort(void *x,int cs,int es, int(*p2f)(void*,void*))
{
void *c;
int diff=cs/2;
int i,j;
c=(void*)malloc(es);
while(diff>=1)
{
i=diff;
while(i<=cs-1)
{
memcpy(c,(const void *)(x+(i*es)),es);
j=i-diff;
while(j>=0 && (p2f(x+(j*es),c)>0))
{
memcpy(x+((j+1)*es),(const void *)(x+(j*es)),es);
j=j+diff;
}
memcpy(x+((j+1)*es),c,es);
i=i+diff;
}
diff=diff/2;
}
}

void bidirectionalBubbleSort(void *x,int cs,int es,int(*p2f)(void*,void*))
{
int i,w;
void *a,*b,*c;
int lb,ub;
c=(void*)malloc(es);
lb=0;
ub=cs-1;
while(lb<ub)
{
for(i=lb;i<=ub-1;i++)
{
a=x+(es*i);
b=x+(es*(i+1));
w=p2f(a,b);
if(w>0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
}
ub--;
while(i>=lb+1)
{
a=x+(es*(i-1));
b=x+(es*i);
w=p2f(a,b);
if(w>0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
i--;
}
lb++;
}
free(c);
}

void binaryInsertionSort(void *x,int cs,int es,int(*p2f)(void*,void*))
{
int i,j,loc;
void *num;
num=(void*)malloc(es);
for(int i=1;i<cs;i++)
{
memcpy(num,(const void *)(x+(es*i)),es);
j=i-1;
loc=binary_search(x,num,i-1,0,es,p2f);
while(j>=loc)
{
memcpy((x+(es*(j+1))),(const void *)(x+(es*j)),es);
j--;
}
memcpy((x+(es*(j+1))),(const void *)num,es);
}
free(num);
}

void stoogeSort(void* x,int cs,int es,int(*p2f)(void*,void*))
{
int w,n;
void* j;
if(cs<=1)return;
j=(void*)malloc(es);
w=p2f(x,x+((cs-1)*es));
if(w>0)
{
memcpy(j,(const void*)x,es);
memcpy(x,(const void*)(x+(es*(cs-1))),es);
memcpy(x+(es*(cs-1)),(const void*)j,es);
}
if(cs>2)
{
n=cs*2/3;
stoogeSort(x,n,es,p2f);
stoogeSort(x+(es*(n-1)),n,es,p2f);
stoogeSort(x,n,es,p2f);
}
free(j);
}

void pigeonHoleSort(void* x,int cs,int es,int(*p2f)(void*,void*))
{
void *max,*min,*c;
void **y;
int w,range,i,j;
max=x;
min=x;
printf("going to find min max\n");
for(i=1;i<cs;i++)
{
w=p2f(max,x+(i*es));
printf("w1 : %d\n",w);
if(w<0)max=x+(i*es);
w=p2f(min,x+(i*es));
printf("w1 : %d\n",w);
if(w>0)min=x+(i*es);
}
w=p2f(max,min);
range=(*(int*)max-*(int*)min)+1;
printf("range : "+range);
y=(void**)malloc(sizeof(void*)*range);
for(i=0;i<range;i++)y[i]=NULL;
for(i=0;i<cs;i++)
{
w=p2f(x+(i*es),min);
memcpy(y+(w*es),(const void *)(x+(i*es)),es);
}
j=0;
for(i=0;i<range;i++)
{
if(*(y+(i*es))!=NULL)
{
memcpy(x+(j*es),(const void *)(y+(i*es)),es);
j++;
}
}
free(y);
}


#endif
