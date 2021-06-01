#include "include\Dijkstra.h"

int main()
{
    int i, j;
    int v0;
    MGraph G;
    Patharc P;
    ShortPathTable D;
    v0 = 0;

    CreateMGraph(&G);

    ShortestPath_Dijkstra( G, v0, &P, &D );

    printf("The reverse order of the shortest path is :\n");

    for( i = 1; i < G.numVertexes; i++ )
    {
        printf("v%d - v%d : ", v0, i );
        j = i;
        while( P[j] != -1 )
        {
            printf("%d ", P[j] );
            j = P[j];
        }
        printf("\n");
    }
    printf("\nThe length of the path from the original vex to each other vexes :\n");
    for( i = 1; i < G.numVertexes; i++ )
        printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i] );


    system("PAUSE");
    return 0;
}