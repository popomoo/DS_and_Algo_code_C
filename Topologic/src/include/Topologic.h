#ifndef TOPOLOGIC_H
#define TOPOLOGIC_H

#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 20
#define MAXVEX 14

typedef enum Status{ OK, ERROR }Status;

typedef struct MGraph
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
}MGraph;

typedef struct EdgeNode
{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    int in;
    int data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct GraphAdjList
{
    AdjList adjList;
    int numVertexes, numEdges;
}GraphAdjList;

void CreateMGraph( MGraph *G );
void CreateALGraph( MGraph G, GraphAdjList *GL );
Status TopologicalSort( GraphAdjList GL );

#endif