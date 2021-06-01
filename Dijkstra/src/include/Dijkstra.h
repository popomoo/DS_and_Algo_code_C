#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 65535

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];

void CreateMGraph( MGraph *G );
void ShortestPath_Dijkstra( MGraph G, int v0, Patharc *P, ShortPathTable *D );

#endif