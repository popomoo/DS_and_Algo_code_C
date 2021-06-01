#ifndef MGRAPH_H
#define MGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVEX 100
#define GRAPH_INFINITY 65535

typedef enum Status{ OK, ERROR }Status;
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType vex[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numNodes, numEdges;
}MGraph;

typedef struct
{
    int data[MAXVEX];
    int front;
    int rear;
}Queue;


void CreateMGraph( MGraph *G );
void DestroyMGraph( MGraph *G );
Status LocateVex( MGraph G, VertexType u, int *p );
Status GetVex( MGraph G, int v, VertexType *value );
Status PutVex( MGraph *G, int v, VertexType value );
VertexType FirstAdjVex( MGraph G, VertexType v );
VertexType NextAdjVex( MGraph G, VertexType v, VertexType w );
Status InsertVex( MGraph *G, VertexType v );
Status DeleteVex( MGraph *G, VertexType v );
Status InsertArc( MGraph *G, VertexType v, VertexType w );
Status DeleteArc( MGraph *G, VertexType v, VertexType w );

Status InitQueue( Queue *Q );
Status QueueEmpty( Queue Q );
Status EnQueue( Queue *Q, int e);
Status DeQueue( Queue *Q, int *e);

void DFS( MGraph G, int i );

void DFSTraverse( MGraph G );
void BFSTraverse( MGraph G );

void CreateMGraph_now( MGraph *G );

#endif