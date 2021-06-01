#ifndef KRUSCAL_H
#define KRUSCAL_H

#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 20
#define MAXVEX 100
#define GRAPH_INFINITY 65535

typedef enum Status{ OK, ERROR }Status;

typedef struct MGraph
{
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

typedef struct Edge
{
    int begin;
    int end;
    int weight;
}Edge;


void CreateMGraph( MGraph *G );
void Swapn( Edge *edges, int i, int j );
void sort( Edge edges[], MGraph *G );
int Find( int *parent, int f );
void MiniSpanTree_Kruskal( MGraph G );


#endif