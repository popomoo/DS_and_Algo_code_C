#ifndef CRITICAL_PATH_H
#define CRITICAL_PATH_H

#include <stdio.h>
#include <stdlib.h>

#define MAXEDGE 30
#define MAXVEX 30
#define GRAPH_INFINITY 65535

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
Status TopologicalSort( GraphAdjList *GL );
void CriticalPath( GraphAdjList *GL );

#endif