#ifndef FLOYD_H
#define FLOYD_H

#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 20
#define MAXVEX 20
#define GRAPH_INFINITY 65535

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void CreateMGraph( MGraph *G );
void ShortestPath_Floyd( MGraph G, Patharc *P, ShortPathTable *D );

#endif