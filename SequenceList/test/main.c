#include <stdio.h>
#include <stdlib.h>
#include "../include/TestSqList.h"

int main()
{
    Ptr list = NULL;
    int pos, size, i;
    ElemType e, *data;
    Status s;
    
    int opt = 1;

    while( opt != 6 )
    {
        printf( "Please select the option.\n" );    
        printf( "1. Test the creation of a list.\n" );
        printf( "2. Test to clear the list created.\n" );
        printf( "3. Test to retrieve an element, its prior element and its next element.\n" );
        printf( "4. Test to find the position of a specific element.\n" );
        printf( "5. Test the length of the list.\n" );
        printf( "6. End.\n");
        
        scanf( "%d", &opt );

        switch(opt)
        {
            case 1 : 
                printf( " Length of the List : \n " );
                scanf( "%d", &size );
                data = (ElemType *)malloc( (size + 1) * sizeof(ElemType) );
                if( data == NULL ) break;

                printf( " Elements of the List : \n" );
                for( i = 1; i <= size; i++ )
                    scanf( "%d", &data[i] );
                s = Test_CreateList( &list, data, size );
                if( s != success )
                    printf( "Failed to create the list !\n" );
                free(data);
                List_Destroy(&list);
                break;
            case 2 :
                printf( " Length of the List : \n " );
                scanf( "%d", &size );
                data = (ElemType *)malloc( (size + 1) * sizeof(ElemType) );
                if( data == NULL ) break;

                printf( " Elements of the List : \n" );
                for( i = 1; i <= size; i++ )
                    scanf( "%d", &data[i] );
                s = Test_CreateList( &list, data, size );
                if( s == success ){
                    if( !List_Empty(&list) ){
                        List_Clear(&list);
                        if( List_Empty(&list) )
                            printf( " Cleared the list!\n" );
                    }
                }
                free(data);
                List_Destroy(&list);
                break;
            case 3 : 
                printf( " Length of the List : \n " );
                scanf( "%d", &size );
                data = (ElemType *)malloc( (size + 1) * sizeof(ElemType) );
                if( data == NULL ) break;

                printf( " Elements of the List : \n" );
                for( i = 1; i <= size; i++ )
                    scanf( "%d", &data[i] );
                s = Test_CreateList( &list, data, size );
                if( s == success )
                {
                    printf( " Please input the position of the element : \n" );
                    scanf( "%d", &pos );
                    Test_RetrivalPriorNext( &list, pos );
                }
                free(data);
                List_Destroy(&list);
                break;
            case 4 :
                printf( " Length of the List : \n " );
                scanf( "%d", &size );
                data = (ElemType *)malloc( (size + 1) * sizeof(ElemType) );
                if( data == NULL ) break;

                printf( " Elements of the List : \n" );
                for( i = 1; i <= size; i++ )
                    scanf( "%d", &data[i] );
                s = Test_CreateList( &list, data, size );
                if( s == success )
                {
                    printf( " Please intput the value of the element : \n" );
                    scanf( "%d", &e );
                    Test_Locate( &list, e );
                }
                free(data);
                List_Destroy(&list);
                break;
            case 5 : 
                printf( " Length of the List : \n " );
                scanf( "%d", &size );
                data = (ElemType *)malloc( (size + 1) * sizeof(ElemType) );
                if( data == NULL ) break;

                printf( " Elements of the List : \n" );
                for( i = 1; i <= size; i++ )
                    scanf( "%d", &data[i] );
                s = Test_CreateList( &list, data, size );
                if( s == success )
                {
                    Test_Size( &list );
                }
                free(data);
                List_Destroy(&list);
                break;
            case 6 : printf("Quit the program.\n"); break;
            default : printf( " Input Error !\n" ); break;
        }
    }

    return 0;
}