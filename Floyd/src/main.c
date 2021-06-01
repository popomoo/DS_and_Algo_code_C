#include "include\Floyd.h"

int main()
{
    int v, w, k;
    MGraph G;

    Patharc P;
    ShortPathTable D;

    CreateMGraph(&G);

    ShortestPath_Floyd(G, &P, &D);

    printf("The shortest path for each vex :\n");

    for( v = 0; v < G.numVertexes; v++ )
    {
        for( w = v + 1; w < G.numVertexes; w++ )
        {
            printf("v%d - v%d weight : %d", v, w, D[v][w] );
            k = P[v][w];
            printf(" path : %d ", v);
            while( k != w )
            {
                printf(" -> %d", k );
                k = P[k][w];
            }
            printf(" -> %d\n", w );
        }
        printf("\n");
    }

    printf("The shortest path\n");
    for( v = 0; v < G.numVertexes; v++ )
    {
        for( w = 0; w < G.numVertexes; w++ )
        {
            printf(" %d ", P[v][w] );
        }
        printf("\n");
    }

    system("PAUSE");
    return 0;
}

