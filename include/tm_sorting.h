#ifndef __tm_sorting__h
#define __tm_sorting__h
#include<tm_common.h>

void linearSort(void *x,int cs,int es,int (*p2f)(void*,void*));
void bubbleSort(void *x,int cs,int es,int (*p2f)(void*,void*));
void selectionSort(void *x,int cs,int es, int(*p2f)(void*,void*));
void insertionSort(void *x,int cs,int es,int(*p2f)(void*,void*));
void quickSort(void *x, int cs,int es, int(*p2f)(void*,void*));
void mergeSort(void *x,int cs,int es,int(*p2f)(void*,void*));
void pancakeSort(void *x,int cs,int es,int (*p2f)(void*,void*));
void brickSort(void *x,int cs,int es,int (*p2f)(void*,void*));
void countingSort(void *x,int cs,int es,int(*keyExtractor)(void*));
void gnomeSort(void* x,int cs,int es,int(*p2f)(void*,void*));
void shellSort(void *x,int cs,int es, int(*p2f)(void*,void*));
void bidirectionalBubbleSort(void *x,int cs,int es,int(*p2f)(void*,void*));
void binaryInsertionSort(void *x,int cs,int es,int(*p2f)(void*,void*));
void stoogeSort(void* x,int cs,int es,int(*p2f)(void*,void*));
void pigeonHoleSort(void* x,int cs,int es,int(*p2f)(void*,void*));
void radixSort(void *x,int cs,int es,int(*p2f)(void*,void*));
void externalSort(void *x,int cs,int es,int(*p2f)(void*,void*));
void timSort(void *x,int cs,int es,int(*p2f)(void*,void*));

#endif