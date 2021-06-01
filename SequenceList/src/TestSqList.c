#include <stdio.h>
#include <stdlib.h>
#include "../include/TestSqList.h"

Status Test_CreateList( SqListPtr list, ElemType data[], int n )
{
    Status s = fail;
    int i;

    s = List_Init( list );
    if( s == success )
    {
        for( i = 1; i <= n; i++ ){

            s = List_Insert( list, i, data[i] );
            if( s != success )
                break;
        }
        List_Print( list );
    }
    return s;
}

Status Test_ClearList( SqListPtr list )
{  
    Status s = fail;
    if( !List_Empty( list ) )
    {
        List_Clear( list );
        if( List_Empty( list ) )
            s = success;
    }

    return s;
}

Status Test_RetrivalPriorNext( SqListPtr list, int pos )
{
    Status s = range_error;
    ElemType e;
    s = List_Retrival( list, pos, &e );
    if( s == success )
    {
        printf( "The element in the position %d of the list is %d\n", pos, e );
        s = List_Prior( list, pos, &e );
        if( s == success )
            printf( "The prior element of the element in position %d is %d\n", pos, e );
        else    
            printf( "No prior element!\n" );

        s = List_Next( list, pos, &e );
        if( s == success )
            printf( "The next element of the element in position %d is %d\n", pos, e );
        else    
            printf( "No next element!\n" );
    }
    else    printf( " Illegal position!\n " );

    return s;
}

Status Test_Locate( SqListPtr list, ElemType e )
{
    Status s;
    int pos;

    s = List_Locate( list, e, &pos );
    if( s == success ){
        printf( " The position of %d is %d\n", e, pos );
    }
    else printf(" Search Failure!\n" );

    return s;
}

void Test_Size( SqListPtr list ){

    int len;
    len = List_Size( list );

    printf( "The length of the List is %d\n", len );
}