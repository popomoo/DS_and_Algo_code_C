#include "include\BTree.h"

int main()
{
    int r[N] = {22, 16, 41, 58, 8, 11, 12, 16, 17, 22, 23, 31, 41, 52, 58, 59, 61};
    BTree T = NULL;
    Result s;

    int i;
    for( i = 0; i < N; i++ )
    {
        s = SearchBTree(T, r[i]);
        if( s.tag == 0 )
            InsertBTree( &T, r[i], s.pt, s.i );
    }

    printf("\nPlease input the key to search : ");
    scanf("%d", &i);
    s = SearchBTree( T, i );

    if( s.tag )
        print( *(s.pt), s.i );
    else
        printf("Have not searched.");
    printf("\n");

    system("PAUSE");
    return 0;
}

