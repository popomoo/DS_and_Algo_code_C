#include "include\Search.h"

int Sequential_Search( int *a, int n, int key )
{
    int i;
    for( i = 1; i <= n; i++ )
    {
        if( a[i] == key )
            return i;
    }
    return 0;
}

int Sequential_Search2( int *a, int n, int key )
{
    int i;
    a[0] = key;
    i = n;
    while( a[i] != key )
        i--;
    return i;
}

int Binary_Search( int *a, int n, int key )
{
    int low, high, mid;

    low = 1;
    high = n;

    while( low <= high )
    {
        mid = low + (high - low)/2;
        if( key < a[mid] )
            high = mid - 1;
        else if( key > a[mid] )
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

int Interpolation_Search( int *a, int n, int key )
{
    int low, high, mid;

    low = 1;
    high = n;

    while( low <= high )
    {
        mid = low + (high - low)*( (key - a[low])/(a[high] - a[low] ) );
        if( a[mid] < key )
            low = mid + 1;
        else if( a[mid] > key )
            high = mid - 1;
        else
            return mid;
    }
    return 0;
}

int F[100];

void Fibonacci()
{
    int i;
    F[0] = 0;
    F[1] = 1;
    for( i = 2;  i < 100; i++ )
        F[i] = F[i-1] + F[i-2];
}

int Fibonacci_Search( int *a, int n, int key )
{
    int low, high, mid;
    int i;
    int k = 0;

    low = 1;
    high = n;

    Fibonacci();
    
    while( n > F[k] - 1 )
        k++;
    
    for( i = n+1; i < F[k] - 1; i++ )
        a[i] = a[n];
 
    while( low <= high )
    {
        mid = low + F[k-1] - 1;
        if( key < a[mid] )
        {
            high = mid - 1;
            k = k - 1;
        }
        else if( key > a[mid] )
        {
            low = mid + 1;
            k = k - 2;
        }
        else
        {
            if( mid != n )
                return mid;
            else
                return n;
        }
    }
    return 0;
}