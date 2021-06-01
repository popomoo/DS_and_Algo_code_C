#include "include\Sort.h"

void swap( SqList *L, int i, int j )
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void print( SqList L )
{
    int i;
    for( i = 1; i <= L.length; i++ )
    {
        printf("%d ", L.r[i] );
        if( i != 0 && i%20 == 0 )
        printf("\n");
    }
    printf("\n");
}

void BubbleSort( SqList *L )
{
    int i, j;
    for( i = 1; i < L->length; i++ )
    {
        for( j = L->length-1; j >= i; j-- )
        {
            if( L->r[j] > L->r[j+1] )
                swap(L, j, j+1);
        }
    }
}

void BubbleSort2( SqList *L )
{
    int i, j;
    Status flag = TRUE;

    for( i = 1; i < L->length && flag == TRUE; i++ )
    {
        flag = FALSE;
        for( j = L->length-1; j >= i; j-- )
        {
            if( L->r[j] > L->r[j+1] )
            {
                swap( L, j, j+1 );
                flag = TRUE;
            }
        }
    }
}

void SelectionSort( SqList *L )
{
    int i, j;
    int min;

    for( i = 1; i < L->length; i++ )
    {
        min = i;
        for( j = i + 1; j <= L->length; j++ )
        {
            if( L->r[j] < L->r[min] )
                min = j;
        }
        if( i != min )
            swap( L, i, min );
    }
}

void InsertSort( SqList *L )
{
    int i, j;
    for( i = 2; i <= L->length; i++ )
    {
        if( L->r[i] < L->r[i-1] )
        {
            L->r[0] = L->r[i];
            for( j = i-1; j > 0 && L->r[j] >= L->r[0]; j-- )
                L->r[j+1] = L->r[j];
            L->r[j+1] = L->r[0];
        }
    }
}

void ShellSort( SqList *L )
{
    int i, j;
    int increment = L->length;

    do
    {
        increment = increment/3 + 1;
        for( i = 1+increment; i <= L->length; i += increment )
        {
            if( L->r[i] < L->r[i - increment] )
            {
                L->r[0] = L->r[i];
                for( j = i - increment; j > 0 && L->r[j] >= L->r[0]; j -= increment )
                {
                    L->r[j+increment] = L->r[j];
                }
                L->r[j+increment] = L->r[0];
            }
        }
    } while (increment > 1);
}

void HeapSort( SqList *L )
{
    int i;
    for( i = L->length/2; i > 0; i-- )
        HeapAdjust( L, i, L->length );
    
    for( i = L->length; i > 1; i-- )
    {
        swap( L, 1, i );
        HeapAdjust( L, 1, i-1 );
    }

}

void HeapAdjust( SqList *L, int summit, int end )
{
    int temp = L->r[summit];
    int j;

    for( j = 2*summit; j <= end; j *= 2 )
    {
        if( j < end && L->r[j] < L->r[j+1] )
            j++;

        if( L->r[j] <= temp )
            break;

        L->r[summit] = L->r[j];
        summit = j;
    }
    L->r[summit] = temp;
}

void MergeSort( SqList *L )
{
    int *TempA;
    TempA = (int*)malloc( (L->length+1)*sizeof(int) );
    if( TempA != NULL )
    {
        MSort( L->r, TempA, 1, L->length );
        free(TempA);
    }
    else
        printf("Malloc ERROR!\n");
}

void MSort( int A[], int TempA[], int L, int R )
{
    int Center;
    if( L < R )
    {
        Center = ( L + R )/2;
        MSort( A, TempA, L, Center);
        MSort( A, TempA, Center+1, R );
        Merge( A, TempA, L, Center+1, R );
    }
}

void Merge( int A[], int TempA[], int Left, int Right, int Right_End )
{
    int Left_End = Right - 1;
    int i = Left;
    int NumElem = Right_End - Left + 1;

    while( Left <= Left_End && Right <= Right_End )
    {
        if( A[Left] <= A[Right] )
            TempA[i++] = A[Left++];
        else
            TempA[i++] = A[Right++];
    }

    while( Left <= Left_End )
        TempA[i++] = A[Left++];
    while( Right <= Right_End )
        TempA[i++] = A[Right++];

    for( i = 0; i < NumElem; i++, Right_End-- )
        A[Right_End] = TempA[Right_End];
}

void MergeSort2( SqList *L )
{
    int k = 1;
    int *TempA;
    TempA = (int*)malloc( (L->length+1) * sizeof(int) );

    if( TempA != NULL )
    {
        while( k < L->length )
        {
            Merge_Pass( L->r, TempA, L->length, k );
            k *= 2;
            Merge_Pass( TempA, L->r, L->length, k );
            k *= 2;
        }
        free( TempA );
    }
    else
        printf("Malloc ERROR!\n");
}

void Merge_Pass( int A[], int TempA[], int length, int k )
{
    int i, j;
    for( i = 1; i <= length - 2*k; i += 2*k )
        Merge( A, TempA, i, i + k, i + 2*k - 1 );

    if( i + k < length )
        Merge( A, TempA, i, i + k, length );
    else
    {
        for( j = i; j <= length; j++ ) 
            TempA[j] = A[j];
    }
}

void QuickSort( SqList *L )
{
    QSort( L, 1, L->length );
}

void QSort( SqList *L, int low, int high )
{
    int pivot;

    if( (high - low) > MAX_LENGTH_INSERT_SORT )
    {
        pivot = Partition( L, low, high );
        QSort( L, low, pivot - 1 );
        QSort( L, pivot + 1, high );
    }
    else
        InsertSort(L);
}

void Median( SqList *L, int low, int mid, int high )
{
    if( L->r[low] > L->r[high] )
        swap(L, low, mid );
    if( L->r[mid] > L->r[high] )
        swap(L, mid, high );
    if( L->r[mid] > L->r[low] )
        swap(L, mid, low );
}

int Partition( SqList *L, int low, int high )
{
    int pivotkey;
    int mid = (low + high)/2;
    Median( L, low, mid, high );

    pivotkey = L->r[low];
    L->r[0] = pivotkey;

    while( low < high )
    {
        while( low < high && L->r[high] >= pivotkey )
            high--;
        L->r[low] = L->r[high];

        while( low < high && L->r[low] <= pivotkey )
            low++;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low;
}