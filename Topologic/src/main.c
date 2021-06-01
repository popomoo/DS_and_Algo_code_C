#include "include\Topologic.h"

int main()
{
    MGraph G;
    GraphAdjList GL;
    int result;

    CreateMGraph(&G);
    CreateALGraph( G, &GL );

    result = TopologicalSort( GL );
    printf("Result : %d\n", result );

    system("PAUSE");
    return 0;
}