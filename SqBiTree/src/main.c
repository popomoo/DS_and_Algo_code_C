#include "include\SqBiTree.h"

int main()
{
    Status i;
    Position p;
    TElemType e;
    SqBiTree T;

    i = InitBiTree( T );
    if( i == ERROR )
        exit( EXIT_FAILURE );
    
    i = CreateBiTree( T );
    if( i == ERROR )
        exit( EXIT_FAILURE );

    printf("After create the BiTree, is the tree empty or not ? %d( 1. Empty  0. Not Empty) the depth of the tree : %d.\n", BiTreeEmpty(T), BiTreeDepth(T));

    i = Root( T, &e );
    if(i)
        printf("The root of the BiTree: %d\n", e );
    else
        printf("The tree is empty, no root.\n");

    Print(T);

    printf("Traverse the BiTree according to the level order: \n");
    LevelOrderTraverse(T);

    printf("PreOrderTraverse the BiTree :\n");
    PreOrderTraverse(T);

    printf("InOrderTraverse the BiTree :\n");
    InOrderTraverse(T);

    printf("PostOrderTraverse the BiTree :\n");
    PostOrderTraverse(T);

    printf("Modify the node 2 in level 3.\n");
    p.level = 3;
    p.order = 2;
    e = Value(T, p);
    printf("The value of the node is %d, the new node is 50.\n", e );

    e = 50;
    Assign( T, p, e);
    printf("PreOrderTraverse the BiTree : \n");
    PreOrderTraverse(T);

    printf("The node is %d, the parent of the node is %d, the left child is %d and the right child %d.\n", e, Parent(T, e), LeftChild(T, e), RightChild(T, e ) );
    printf("Left sibling is %d, Right Sibling is %d.\n", LeftSibling(T, e), RightSibling(T, e) );
    
    ClearBiTree(T);
    printf("After clearing the BiTree, is the Tree empty or not? %d(1. Empty 0. Not Empty) The depth of the tree = %d\n", BiTreeEmpty(T), BiTreeDepth(T) );

    i = Root(T, &e);
    if( i == OK )
        printf("The root of the BiTree is %d\n", e);
    else
        printf("The tree don't have the root\n");

    system("PAUSE");
    return 0;
}