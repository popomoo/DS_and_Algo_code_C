#include "include\Topologic.h"

void CreateMGraph( MGraph *G )
{
    int i, j;

    G->numEdges = MAXEDGE;
    G->numVertexes = MAXVEX;

    for( i = 0; i < G->numVertexes; i++ )
        G->vexs[i] = i;

    for( i = 0; i < G->numVertexes; i++ )
    {
        for( j = 0; j < G->numVertexes; j++ )
        {
            G->arc[i][j] = 0;
        }
    }
    
    G->arc[0][4] = 1;
    G->arc[0][5] = 1;
    G->arc[0][11] = 1;
    G->arc[1][2] = 1;
    G->arc[1][4] = 1;
    G->arc[1][8] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    G->arc[2][9] = 1;
    G->arc[3][2] = 1;
    G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][8] = 1;
    G->arc[5][12] = 1;
    G->arc[6][5] = 1;
    G->arc[8][7] = 1;
    G->arc[9][10] = 1;
    G->arc[9][11] = 1;
    G->arc[10][13] = 1;
    G->arc[12][9] = 1;
}

void CreateALGraph( MGraph G, GraphAdjList *GL )
{
    int i, j;
    EdgeNode *e;

    GL->numVertexes = G.numVertexes;
    GL->numEdges = G.numEdges;
    for( i = 0; i < G.numVertexes; i++ )
    {
        GL->adjList[i].in = 0;
        GL->adjList[i].data = G.vexs[i];
        GL->adjList[i].firstedge = NULL;
    }

    for( i = 0; i < G.numVertexes; i++ )
    {
        for( j = 0; j < G.numVertexes; j++ )
        {
            if( G.arc[i][j] == 1 )
            {
                e = (EdgeNode*)malloc(sizeof(EdgeNode));
                e->adjvex = j;
                e->next = GL->adjList[i].firstedge;
                GL->adjList[i].firstedge = e;
                GL->adjList[j].in++;
            }
        }
    }
}

Status TopologicalSort( GraphAdjList GL )
{
    EdgeNode *e;
    int i;
    int k;
    int gettop;
    int top = 0;
    int count = 0;

    int *stack;
    stack =(int*)malloc(GL.numVertexes*sizeof(int));

    for( i = 0; i < GL.numVertexes; i++ )
        if( GL.adjList[i].in == 0 )
            stack[++top] = i;

    while( top != 0 )
    {
        gettop = stack[top--];
        printf("%d -> ", GL.adjList[gettop].data );
        count++;

        for( e = GL.adjList[gettop].firstedge; e; e = e->next )
        {
            k = e->adjvex;
            if( !(--GL.adjList[k].in) )
                stack[++top] = k;
        }
    }

    printf("\n");

    if( count < GL.numVertexes )
        return ERROR;
    else
        return OK;
}