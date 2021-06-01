#include "include\AVLTree.h"

int main()
{
    int i;
    int a[10] = {3, 2, 1, 4, 5, 6, 7, 10, 9, 8};

    BiTree T = NULL;
    Status taller;

    for( i = 0; i < 10; i++ )
    {
        InsertAVL(&T, a[i], &taller);
    }

    system("PAUSE");
    return 0;
}