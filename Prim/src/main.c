#include "include\Prim.h"

int main()
{
    MGraph G;
    CreateMGraph( &G );
    MiniSpanTree_Prim(G);

    system("PAUSE");
    return 0;
}