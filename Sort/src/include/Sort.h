#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Status{ FALSE, TRUE }Status;

#define MAX_LENGTH_INSERT_SORT 7


#define MAXSIZE 10000

typedef struct SqList
{
    int r[MAXSIZE+1];
    int length;
}SqList;

void swap( SqList *L, int i, int j );

void print( SqList L );

void BubbleSort( SqList *L );
void BubbleSort2( SqList *L );

void SelectionSort( SqList *L );
void ShellSort( SqList *L );

void HeapSort( SqList *L );
void HeapAdjust( SqList *L, int summit, int end );

void MergeSort( SqList *L );
void MSort( int A[], int TempA[], int L, int R );
void Merge( int A[], int TempA[], int Left, int Mid, int Right );

void MergeSort2( SqList *L );
void Merge_Pass( int A[], int TempA[], int length, int k );

void QuickSort( SqList *L );
void QSort( SqList *L, int low, int high );

void Median( SqList *L, int low, int mid, int high );
int Partition( SqList *L, int low, int high );

#endif