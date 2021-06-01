#include "include\Sort.h"

#define N 10

int main()
{
    clock_t start;
    clock_t stop;
    double span;
    int i;
    SqList L;
    
    srand(time(NULL));
    for( i = 0; i < N; i++ )
        L.r[i+1] = rand()%1000;
    L.length = N;

    print(L);

    start = clock();
    //BubbleSort( &L );
    //BubbleSort2( &L );
    //SelectionSort( &L );
    //ShellSort( &L );
    //HeapSort( &L );
    //MergeSort( &L );
    //MergeSort2( &L );
    QuickSort( &L );
    stop = clock();
    span = (double)((stop-start)/CLOCKS_PER_SEC);

    print(L);
    //printf("Time used by Bubble Sort : %lf.\n", span);
    //printf("Time used by Bubble Sort2 : %lf.\n", span);
    //printf("Time used by Selection Sort : %lf.\n", span);
    //printf("Time used by Shell Sort : %lf.\n", span);
    //printf("Time used by Heap Sort : %lf.\n", span);
    //printf("Time used by Merge Sort : %lf.\n", span);
    //printf("Time used by Merge Sort 2 : %lf.\n", span);
    printf("Time used by Quick Sort : %lf.\n", span);

    system("PAUSE");
    return 0;
}