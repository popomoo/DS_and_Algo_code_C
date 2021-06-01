#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVEX 100
#define TRUE 1
#define FALSE 0

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int adjvex;
    EdgeType info;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    VertexType data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numNodes, numEdges;
}GraphAdjList;

typedef enum Status{ OK, ERROR }Status;

void CreateALGraph( GraphAdjList *G );
void DestroyALGraph( GraphAdjList *G );
int LocateVex( GraphAdjList G, VertexType v );
VertexType GetVex( GraphAdjList G, int p );
Status PutVex( GraphAdjList *G, int p, VertexType v );
VertexType FirstAdjVex( GraphAdjList G, VertexType v );
VertexType NextAdjVex( GraphAdjList G, VertexType v, VertexType w );

Status InsertVex( GraphAdjList *G, VertexType v );
Status DeleteVex( GraphAdjList *G, VertexType v );
Status InsertArc( GraphAdjList *G, VertexType v, VertexType w );
Status DeleteArc( GraphAdjList *G, VertexType v, VertexType w );

typedef struct MGraph
{
    int numVertexes, numEdges;
    char vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
}MGraph;

void CreateMGraph( MGraph *G );
void CreateALGraph_now( MGraph G, GraphAdjList *GL );

typedef struct Queue
{
    VertexType data[MAXVEX];
    int front;
    int rear;
}Queue;

Status InitQueue( Queue *Q );
Status QEmpty( Queue *Q );
Status EnQueue( Queue *Q, int value );
Status DeQueue( Queue *Q, int *value );

typedef int Bool;

void DFS( GraphAdjList GL, int i );
void DFSTraverse( GraphAdjList GL );
void BFSTraverse( GraphAdjList GL );

#endif