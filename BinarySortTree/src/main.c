#include "include\BinaryTreeSort.h"

int main()
{
    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;

    for( i = 0; i < 10; i++ )
        InsertBST(&T, a[i]);

    DeleteBST(&T, 88);

    system("PAUSE");
    return 0;
}