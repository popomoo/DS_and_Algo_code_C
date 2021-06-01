#include "include\CriticalPath.h"

int main()
{
    MGraph G;
    GraphAdjList GL;

    CreateMGraph(&G);
    CreateALGraph(G, &GL);

    CriticalPath(&GL);

    system("PAUSE");
    return 0;
}