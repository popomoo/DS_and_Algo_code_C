#include "include\LinkBiTree.h"

int main()
{
    Status s;
    BiTree T;
    TElemType e;

    s = InitBiTree(&T);
    
    StrAssign( str, "ABDH#K###E##CFI###G#J##");

    CreateBiTree(&T);

    printf("After creating the BiTree, the BiTree is empty or not? %d(1.Empty 0.Not Empty), the depth of the tree is %d.\n", BiTreeEmpty(T), BiTreeDepth(T));
    Root(T, &e);
    printf("The root of the Binary Tree is : %c\n", e );

    printf("\nPreOrder Traverse : \n");
    PreOrderTraverse(T);

    printf("\nInOrder Traverse : \n");
    InOrderTraverse(T);

    printf("\nPostOrder Traverse : \n");
    PostOrderTraverse(T);

    DestroyBiTree(&T);

    printf("\nAfter clearing the Binary Tree, is the tree empty? %d(1.Empty 0.Not Empty), the depth of the tree is %d .\n", BiTreeEmpty(T), BiTreeDepth(T) );

    s = Root(T, &e);
    if( s == ERROR )
        printf("The tree don't have a root.\n");

    system("PAUSE");
    return 0;
}