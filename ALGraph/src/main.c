#include "include\ALGraph.h"

int main()
{
    GraphAdjList GL;
    MGraph G;

    int e;
    VertexType v;
    Status s;
    //CreateALGraph(&G);
    CreateMGraph(&G);
    
    CreateALGraph_now(G, &GL);
    
    printf("Depth First Traverse :\n");
    DFSTraverse(GL);
    printf("\n");

    e = LocateVex( GL, 'C' );
    printf("The position of A is %d.\n", e);

    v = GetVex( GL, 4 );
    printf("The vex in the position 4 is %c.\n", v);

    s = PutVex( &GL, 2, 'J');
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("After replacing C by J, depth First Traverse the graph list :\n");
    DFSTraverse(GL);
    printf("\n");

    s = PutVex( &GL, 2, 'C');
    printf("After replacing B by J, depth First Traverse the graph list :\n");
    DFSTraverse(GL);
    printf("\n");

    v = FirstAdjVex( GL, 'D' );
    printf("The first adjacent vex of D is %c.\n", v);

    v = NextAdjVex( GL, 'D', 'E' );
    printf("The adjacent vex of vex D next to the vex E is %c.\n", v);

    s = InsertVex( &GL, 'J' );
    if( s == ERROR )
        exit( EXIT_FAILURE );

    printf("Breadth First Traverse : \n");
    BFSTraverse(GL);
    printf("\n");

    s = DeleteVex( &GL, 'J' );
    if( s == ERROR )
        exit( EXIT_FAILURE );

    printf("Breadth First Traverse : \n");
    BFSTraverse(GL);
    printf("\n");

    s = InsertArc( &GL, 'A', 'G' );
    if( s == ERROR )
        exit(EXIT_FAILURE);

    printf("Breadth First Traverse : \n");
    BFSTraverse(GL);
    printf("\n");

    s = DeleteArc( &GL, 'A', 'G' );
    if( s == ERROR )
        exit( EXIT_FAILURE );
    
    printf("Breadth First Traverse : \n");
    BFSTraverse(GL);
    printf("\n");

    DestroyALGraph(&GL);

    system("PAUSE");
    return 0;
}