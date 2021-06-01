#include "include\MGraph.h"

void CreateMGraph( MGraph *G )
{
    int i, j, k, w;
    printf("Input the number of the vertexes and the number of the edges :\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges );
    for( i = 0; i < G->numNodes; i++ )
        scanf(&G->vex[i]);
    for( i = 0; i < G->numNodes; i++ )
        for( j = 0; j < G->numNodes; j++ )
            G->arc[i][j] = GRAPH_INFINITY;
    for( k = 0; k < G->numEdges; k++ )
    {
        printf("Input the indexes i, j and the weight w of the edge(vi, vj) : \n");
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

void DestroyMGraph( MGraph *G )
{
    int i, j;
    for( i = 0; i < G->numNodes; i++ )
        G->vex[i] = ' ';
    for( i = 0; i < G->numNodes; i++ )
        for( j = 0; j < G->numNodes; j++ )
            G->arc[i][j] = GRAPH_INFINITY;
}

Status LocateVex( MGraph G, VertexType u, int *p )
{
    int i;
    for( i = 0; i < G.numNodes; i++ )
    {
        if( G.vex[i] == u )
        {
            *p = i;
            return OK;
        }
    }
    return ERROR;
}

Status GetVex( MGraph G, int v, VertexType *value )
{
    if( v < 0 || v >= G.numNodes )
        return ERROR;

    *value = G.vex[v];
    return OK;
}

Status PutVex( MGraph *G, int v, VertexType value )
{
    if( v < 0 || v >= G->numNodes )
        return ERROR;

    G->vex[v] = value;
    return OK;
}

VertexType FirstAdjVex( MGraph G, VertexType v )
{
    int i, j;
    for( i = 0; i < G.numNodes; i++ )
        if( G.vex[i]  == v )
            break;
    for( j = 0; j < G.numNodes; j++ )
        if( G.arc[i][j] != GRAPH_INFINITY )
            return G.vex[j];
    return ' ';
}

VertexType NextAdjVex( MGraph G, VertexType v, VertexType w )
{
    int i, j, k;
    for( i = 0; i < G.numNodes; i++ )
        if( G.vex[i] == v )
            break;
    for( j = 0; j < G.numNodes; j++ )
        if( G.vex[j] == w )
            break;
    for( k = j + 1; k < G.numNodes; k++ )
        if( G.arc[i][k] != GRAPH_INFINITY )
            return G.vex[k];
    
    return ' ';
}

Status InsertVex( MGraph *G, VertexType v )
{
    if( G->numNodes >= MAXVEX )
        return ERROR;
    G->vex[G->numNodes++] = v;
    return OK;
}

Status DeleteVex( MGraph *G, VertexType v )
{
    int i, j, k;
    if( G->numNodes == 0 )
        return ERROR;
    
    for( k = 0; k < G->numNodes; k++ )
        if( G->vex[k] == v )
            break;

    for( j = k; j < G->numNodes - 1; j++ )
        G->vex[j] = G->vex[j+1];
    G->numNodes--;

    for( i = 0; i < G->numNodes + 1; i++ )
    {
        for( j = k; j < G->numNodes; j++ )
        {
            if( G->arc[i][j] == 1 )
                G->numEdges--;
            G->arc[i][j] = G->arc[i][j+1];
        }
    }
    
    for( i = k; i < G->numNodes; i++ )
    {
        for( j = 0; j < G->numNodes; j++ )
        {
            if( G->arc[i][j] == 1 )
                G->numEdges--;
            G->arc[i][j] = G->arc[i+1][j];
        }
    }
    
    return OK;
}

Status InsertArc( MGraph *G, VertexType v, VertexType w )
{
    int i, j;
    for( i = 0; i < G->numNodes; i++ )
        if( G->vex[i] == v )
            break;
    for( j = 0; j < G->numNodes; j++ )
        if( G->vex[j] == w )
            break;
    if( (i == G->numNodes-1 && G->vex[i] != v)
         || (j == G->numNodes-1 && G->vex[j] != w) )
        return ERROR;
    G->arc[i][j] = 1;
    G->numEdges++;
    return OK;
}

Status DeleteArc( MGraph *G, VertexType v, VertexType w )
{
    int i, j;
    for( i = 0; i <= G->numNodes; i++ )
        if( G->vex[i] == v )
            break;
    for( j = 0; j <= G->numNodes; j++ )
        if( G->vex[j] == w )
            break;
    if( i >= G->numNodes || j >= G->numNodes )
        return ERROR;
    G->arc[i][j] = GRAPH_INFINITY;
    G->numEdges++;
    return OK;
}

Status InitQueue( Queue *Q )
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status QueueEmpty( Queue Q )
{
    return ( Q.front == Q.rear );
}

Status EnQueue( Queue *Q, int e )
{
    if( Q->front == (Q->rear + 1)%MAXVEX )
        return ERROR;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1)%MAXVEX;
    return OK;
}

Status DeQueue( Queue *Q, int *e )
{
    if( Q->front == Q->rear )
        return ERROR;
    *e = Q->front;
    Q->front = (Q->front + 1)%MAXVEX;
    return OK;
}

int visited[MAXVEX];

void DFS( MGraph G, int i )
{
    int j;
    visited[i] = 1;
    printf("%c ", G.vex[i] );
    for( j = 0; j < G.numNodes; j++ )
        if( G.arc[i][j] == 1 && !visited[j] )
            DFS(G, j);
}

void DFSTraverse( MGraph G )
{
    int i;
    for( i = 0; i < G.numNodes; i++ )
        visited[i] = 0;
    for( i = 0; i < G.numNodes; i++ )
        if( !visited[i] )
            DFS(G, i);
}

void BFSTraverse( MGraph G )
{
    int i, j;
    Queue Q;
    for( i = 0; i < G.numNodes; i++ )
        visited[i] = 0;
    
    InitQueue( &Q );

    for( i = 0; i < G.numNodes; i++ )
    {
        if( !visited[i] )
        {
            visited[i] = 1;
            printf("%c ", G.vex[i] );
            EnQueue( &Q, i);
            while( !QueueEmpty(Q) )
            {
                DeQueue( &Q, &i );
                for( j = 0; j < G.numNodes; j++ )
                {
                    if( G.arc[i][j] == 1 && !visited[j] )
                    {
                        visited[j] = 1;
                        printf("%c ", G.vex[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

void CreateMGraph_now( MGraph *G )
{
    int i, j;

    G->numEdges=15;
	G->numNodes=9;

	G->vex[0]='A';
	G->vex[1]='B';
	G->vex[2]='C';
	G->vex[3]='D';
	G->vex[4]='E';
	G->vex[5]='F';
	G->vex[6]='G';
	G->vex[7]='H';
	G->vex[8]='I';


	for ( i = 0; i < G->numNodes; i++ )
	{
		for ( j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j]=0;
		}
	}

	G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

	
	for(i = 0; i < G->numNodes; i++)
	{
		for(j = i; j < G->numNodes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
}