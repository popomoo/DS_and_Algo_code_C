#include "include\TestSqList.h"

void Test_CreateList( SqListPtr L )
{
    Status s = InitList(L);
    int size, i, e;
    if( s == ERROR )
        printf(" List Init ERROR !\n");
    else
    {
        printf( "Please input the size of the List : \n" );
        scanf( "%d", &size);
        
        printf( "Please input the elements of the List : \n");
        for( i = 0; i < size; i++ )
        {   
            scanf( "%d", &e);
            s = ListInsert( L, i+1, e);
            if( s == ERROR )
            {
                printf( "Element insert ERROR !\n");
                break;
            }
        }

        ListPrint(*L);
        
        s = ClearList(L);
        if( s == ERROR )
            printf( "Clear List ERROR !\n" );
    }
}

void Test_GetListElem( SqListPtr L )
{
    Status s;
    s = InitList(L);
    int size, i, e, pos;
    if( s == ERROR )
        printf(" List Init ERROR !\n");
    else
    {
        printf( "Please input the size of the List : \n" );
        scanf( "%d", &size);
        
        printf( "Please input the elements of the List : \n");
        for( i = 0; i < size; i++ )
        {   
            scanf( "%d", &e);
            s = ListInsert( L, i+1, e);
            if( s == ERROR )
            {
                printf( "Element insert ERROR !\n");
                break;
            }
        }

        ListPrint(*L);

        printf( "Please Input the position of the element : \n" );
        scanf( "%d", &pos );
        s = GetElem( *L, pos, &e );
        if( s == ERROR )
            printf( "Get Element ERROR !\n" );
        else
            printf( "The element in position %d is %d.\n", pos, e );
        
        s = ClearList(L);
        if( s == ERROR )
            printf( "Clear List ERROR !\n" );
    }
}

void Test_Find( SqListPtr L )
{
    Status s;
    s = InitList(L);
    int size, i, e, pos;
    if( s == ERROR )
        printf(" List Init ERROR !\n");
    else
    {
        printf( "Please input the size of the List : \n" );
        scanf( "%d", &size);
        
        printf( "Please input the elements of the List : \n");
        for( i = 0; i < size; i++ )
        {   
            scanf( "%d", &e);
            s = ListInsert( L, i+1, e);
            if( s == ERROR )
            {
                printf( "Element insert ERROR !\n");
                break;
            }
        }

        ListPrint(*L);

        printf( "Please Input the element to find : \n" );
        scanf( "%d", &e );
        s = ElemLocate( *L, e, &pos );
        if( s == ERROR )
            printf( "Failed to locate the element !\n" );
        else
            printf( "The element %d locates in position %d.\n", e, pos );
        
        s = ClearList(L);
        if( s == ERROR )
            printf( "Clear List ERROR !\n" );
    }
}

void Test_Delete( SqListPtr L )
{
    Status s;
    s = InitList(L);
    int size, i, e, pos;
    if( s == ERROR )
        printf(" List Init ERROR !\n");
    else
    {
        printf( "Please input the size of the List : \n" );
        scanf( "%d", &size);
        
        printf( "Please input the elements of the List : \n");
        for( i = 0; i < size; i++ )
        {   
            scanf( "%d", &e);
            s = ListInsert( L, i+1, e);
            if( s == ERROR )
            {
                printf( "Element insert ERROR !\n");
                break;
            }
        }

        ListPrint(*L);

        printf( "Please Input the position of the element to delete : \n" );
        scanf( "%d", &pos );
        s = ListDelete( L, pos, &e );
        if( s == ERROR )
            printf( "Failed to delete the element !\n" );
        
        ListPrint(*L);
        
        s = ClearList(L);
        if( s == ERROR )
            printf( "Clear List ERROR !\n" );
    }
}

void Test_Length( SqListPtr L )
{
    Status s;
    s = InitList(L);
    int size, i, e;
    if( s == ERROR )
        printf(" List Init ERROR !\n");
    else
    {
        printf( "Please input the size of the List : \n" );
        scanf( "%d", &size);
        
        printf( "Please input the elements of the List : \n");
        for( i = 0; i < size; i++ )
        {   
            scanf( "%d", &e);
            s = ListInsert( L, i+1, e);
            if( s == ERROR )
            {
                printf( "Element insert ERROR !\n");
                break;
            }
        }

        ListPrint(*L);

        printf("The length of the List is : %d.\n", ListLength(*L));
        s = ClearList(L);
        if( s == ERROR )
            printf( "Clear List ERROR !\n" );
    }
}