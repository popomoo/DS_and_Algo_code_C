#include "include\Kruskal.h"

int main()
{
    MGraph G;
    CreateMGraph(&G);
    MiniSpanTree_Kruskal(G);

    system("PAUSE");
    return 0;
}