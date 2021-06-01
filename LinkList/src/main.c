#include "include\TestLinkList.h"

int main()
{      
    LinkList list;

    int opt;

    printf( "Please select the operation : \n" );
    printf( "1. Create a List\n" );
    printf( "2. Get an element\n" );
    printf( "3. Locate an element\n" );
    printf( "4. Delete an element.\n");
    printf( "5. Get the length of the List.\n" );
    printf( "6. Create a list using the insertion from head.\n");
    printf( "7. Create a List using the insertion from Tail.\n");
    printf( "8. Quit the program.\n");
    scanf( "%d", &opt );

    switch(opt)
    {
        case 1 : Test_CreateList(&list); break;
        case 2 : Test_GetListElem(&list); break;
        case 3 : Test_Find(&list); break;
        case 4 : Test_Delete(&list); break;
        case 5 : Test_Length(&list); break;
        case 6 : Test_CreatHead(&list); break;
        case 7 : Test_CreatTail(&list); break;
        default : printf( "Quit\n"); break;
    }

    system("PAUSE");
    return 0;
}

    