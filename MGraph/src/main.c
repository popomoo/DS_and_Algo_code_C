#include "include\MGraph.h"

int main()
{
    MGraph G;
    Status s;
    VertexType v = 'D';
    int i;
    CreateMGraph_now(&G);
    /*CreateMGraph(&G);*/

    printf("Depth First Search : \n");
    DFSTraverse(G);
    printf("\n");

    s = LocateVex(G, v, &i);
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("The position of vex D is %d.\n", i);

    s = GetVex( G, i, &v );
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("The vex in the position %d is %c.\n", i, v);

    s = InsertVex( &G, 'K');
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("Breadth First Search :\n");
    BFSTraverse(G);
    printf("\n");

    s = PutVex( &G, 9, 'J');
    if( s == ERROR )
        exit( EXIT_FAILURE );

    v = FirstAdjVex( G, 'B');
    printf("The vex %c is an adjacent vex of vex B.\n", v);

    v = NextAdjVex( G, 'B', 'C');
    printf("The adjacent vex of vex B and next to the vex C is %c.\n", v);

    s = InsertVex( &G, 'L');
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("Breadth First Search :\n");
    BFSTraverse(G);
    printf("\n");

    s = DeleteVex( &G, 'L' );
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("Breadth First Search :\n");
    BFSTraverse(G);
    printf("\n");

    s = InsertArc( &G, 'A', 'J' );
    if( s == ERROR )
        exit(EXIT_FAILURE);
    printf("Breadth First Search :\n");
    BFSTraverse(G);
    printf("\n");

    s = DeleteArc( &G, 'A', 'J' );
    if( s == ERROR )
        exit( EXIT_FAILURE );
    printf("Breadth First Search :\n");
    BFSTraverse(G);
    printf("\n");

    DestroyMGraph(&G);
    
    system("PAUSE");
    return 0;
}