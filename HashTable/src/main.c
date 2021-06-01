#include "include\HashTable.h"

int main()
{
    int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    int i, p, key, result;

    HashTable H;

    key = 39;

    InitHashTable(&H);
    for( i = 0; i < HASHSIZE; i++ )
        InsertHash(&H, arr[i]);

    result = SearchHash( H, key, &p );
    if( result )
        printf("Find out the address of %d is %d.\n", key, p );
    else
        printf("Unsuccessful search.\n", key );

    for( i = 0; i < HASHSIZE; i++ )
    {
        key = arr[i];
        SearchHash(H, key, &p);
        printf("Find out the address of %d is %d.\n", key, p );
    }

    system("PAUSE");
    return 0;
}
