#ifndef PRIM_H
#define PRIM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVEX 100
#define GRAPH_INFINITY 65535

typedef enum Status{ OK, ERROR }Status;

typedef struct MGraph
{
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

void CreateMGraph( MGraph *G );
void MiniSpanTree_Prim( MGraph G );

#endif