#include "include\Search.h"

int main()
{
    int a[MAXSIZE+1];
    int i;
    int result;
    int arr[MAXSIZE] = {0, 1, 16, 24, 35, 47, 59, 62, 73, 88, 99};

    for( i = 0; i <= MAXSIZE; i++ )
        a[i] = i;

    result = Sequential_Search( a, MAXSIZE, MAXSIZE );
    printf("Sequential Search : %d\n", result );

    result = Sequential_Search2( a, MAXSIZE, 1);
    printf("Sequential_Search2 : %d\n", result );

    result = Binary_Search(arr, 10, 62);
    printf("Binary_Search : %d\n", result );

    result = Fibonacci_Search( arr, 10, 62 );
    printf("Fibonnacci_Search : %d\n", result );

    system("PAUSE");
    return 0;
}