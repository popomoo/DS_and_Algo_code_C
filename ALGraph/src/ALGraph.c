#include "include\ALGraph.h"

void CreateALGraph( GraphAdjList *G )
{
    int i, j, k;
    EdgeNode *e;
    printf("Please input the number of vex and the number of edge :\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    for( i = 0; i < G->numNodes; i++ )
    {
        printf("Please input the vex :\n");
        scanf(" %c", &G->adjList[i].data);
        G->adjList[i].firstedge = NULL;
    }
    for( k = 0; k < G->numEdges; k++ )
    {
        printf("Please input the index of the vexes of the edge(vi, vj) : \n");
        scanf("%d,%d", &i, &j);
    
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[i].firstedge = e;
    }
}

void DestroyALGraph( GraphAdjList *G )
{
    int i;
    for( i = 0; i < G->numNodes; i++ )
    {
        EdgeNode *p, *q;
        p = G->adjList[i].firstedge;
        while( p != NULL )
        {
            q = p;
            p = p->next;
            free(q);
        }
        G->adjList[i].firstedge = NULL;
        G->adjList[i].data = ' ';
    }
}

int LocateVex( GraphAdjList G, VertexType v )
{
    int i;
    for( i = 0; i < G.numNodes; i++ )
    {
        if( G.adjList[i].data == v )
            return i;
    }
    return -1;
}

VertexType GetVex( GraphAdjList G, int p )
{
    if( p < 0 || p >= G.numNodes)
        return ' ';
    return G.adjList[p].data;
}

Status PutVex( GraphAdjList *G, int p, VertexType v )
{
    if( p < 0 || p >= G->numNodes )
        return ERROR;

    G->adjList[p].data = v;
    return OK;
}

VertexType FirstAdjVex( GraphAdjList G, VertexType v )
{
    int i;
    for( i = 0; i < G.numNodes; i++ )
    {
        if( G.adjList[i].data == v )
            return G.adjList[G.adjList[i].firstedge->adjvex].data;
    }
    return ' ';
}

VertexType NextAdjVex( GraphAdjList G, VertexType v, VertexType w)
{
    int i;
    EdgeNode *p = NULL;
    for( i = 0; i < G.numNodes; i++ )
        if( G.adjList[i].data == v )
            break;
    if( i == G.numNodes-1 && G.adjList[i].data != v )
        return ' ';
    else
    {
        p = G.adjList[i].firstedge;
        while( p != NULL )
        {
            if( G.adjList[p->adjvex].data == w && p->next != NULL )
                return G.adjList[p->next->adjvex].data;
            p = p->next;
        }
        return ' ';
    }
}


Status InsertVex( GraphAdjList *G, VertexType v )
{
    if( G->numNodes >= MAXVEX )
        return ERROR;
    else
    {
        G->adjList[G->numNodes++].data = v;
        G->adjList[G->numNodes].firstedge = NULL;
        return OK;
    }
}

Status DeleteVex( GraphAdjList *G, VertexType v )
{
    int i, j;
    EdgeNode *p, *q = NULL;
    if( G->numNodes <= 0 )
        return ERROR;

    for( i = 0; i < G->numNodes; i++ )
        if( G->adjList[i].data == v )
            break;

    p = G->adjList[i].firstedge;
    while( p != NULL )
    {
        q = p;
        p = p->next;
        free(q);
    }
    G->adjList[i].firstedge = NULL;
    for( j = i; j < G->numNodes-1; j++ )
        G->adjList[j] = G->adjList[i+1];
    G->numNodes--;
    return OK;
}

Status DeleteArc( GraphAdjList *G, VertexType v, VertexType w )
{
    int i, j;
    EdgeNode *p, *q = NULL;
    for( i = 0; i < G->numNodes; i++ )
        if( G->adjList[i].data == v )
            break;
    for( j = 0; j < G->numNodes; j++ )
        if( G->adjList[j].data == w )
            break;

    if( G->adjList[i].firstedge != NULL &&  
        G->adjList[i].firstedge->adjvex == j )
    {
        p = G->adjList[i].firstedge;
        G->adjList[i].firstedge = G->adjList[i].firstedge->next;
        free(p);
    }
    else
    {
        p = G->adjList[i].firstedge;
        while( p != NULL && p->next != NULL )
        {
            if( p->next->adjvex == j )
            {
                q = p->next;
                p->next = p->next->next;
                free(q);
            }
            else
                p = p->next;
        }
    }

    if( G->adjList[j].firstedge != NULL &&  
        G->adjList[j].firstedge->adjvex == i )
    {
        p = G->adjList[j].firstedge;
        G->adjList[j].firstedge = G->adjList[j].firstedge->next;
        free(p);
        G->numEdges--;
        return OK;
    }
    else
    {
        p = G->adjList[j].firstedge;
        while( p != NULL && p->next != NULL )
        {
            if( p->next->adjvex == i )
            {
                q = p->next;
                p->next = p->next->next;
                free(q);
                G->numEdges--;
                return OK;
            }
            else
                p = p->next;
        }
    }

    return ERROR;
}

Status InsertArc( GraphAdjList *G, VertexType v, VertexType w )
{
    int i, j;
    EdgeNode *q = NULL;
    for( i = 0; i < G->numNodes; i++ )
        if( G->adjList[i].data == v )
            break;
    for( j = 0; j < G->numNodes; j++ )
        if( G->adjList[j].data == w )
            break;
    
    if( (i == G->numNodes-1 && G->adjList[i].data != v )
        ||( j == G->numNodes-1 && G->adjList[j].data != w ) )
        return ERROR;

    q = (EdgeNode*)malloc(sizeof(EdgeNode));
    q->adjvex = j;
    q->next = G->adjList[i].firstedge;
    G->adjList[i].firstedge = q;

    q = (EdgeNode*)malloc(sizeof(EdgeNode));
    q->adjvex = i;
    q->next = G->adjList[j].firstedge;
    G->adjList[j].firstedge = q;

    G->numEdges++;
    return OK;
}

void CreateMGraph( MGraph *G )
{
	int i, j;

	G->numEdges=15;
	G->numVertexes=9;

	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';


	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G->numVertexes; j++)
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

	
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}

}
 

void CreateALGraph_now( MGraph G, GraphAdjList *GL )
{
	int i,j;
	EdgeNode *e;

	GL->numNodes = G.numVertexes;
	GL->numEdges = G.numEdges;
	for(i = 0; i < G.numVertexes; i++ )
	{
		GL->adjList[i].data = G.vexs[i];
		GL->adjList[i].firstedge = NULL;
	}
	
	for(i = 0; i < G.numVertexes; i++) 
	{ 
		for(j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex = j;				                      
				e->next = GL->adjList[i].firstedge;	
				GL->adjList[i].firstedge = e;		
				
			}
		}
	}
	
}

Status InitQueue( Queue *Q )
{
    Q->front = Q->rear = 0;
    return OK;
}

Status QEmpty( Queue *Q )
{
    return (Q->front == Q->rear);
}

Status EnQueue( Queue *Q, int value )
{
    if( (Q->rear + 1)%MAXVEX == Q->front )
        return ERROR;
    Q->data[Q->rear] = value;
    Q->rear = (Q->rear + 1)%MAXVEX;
    return OK;
}

Status DeQueue( Queue *Q, int *value )
{
    if( QEmpty(Q) )
        return ERROR;
    *value = Q->data[Q->front];
    Q->front = (Q->front + 1)%MAXVEX;
    return OK;
}

Bool visited[MAXVEX];

void DFS( GraphAdjList GL, int i )
{
    EdgeNode *p;
    if( !visited[i] )
        visited[i] = TRUE;
    printf("%c ", GL.adjList[i].data);
    p = GL.adjList[i].firstedge;
    while( p != NULL )
    {
        if( !visited[p->adjvex] )
            DFS(GL, p->adjvex);
        p = p->next;
    }
}

void DFSTraverse( GraphAdjList GL )
{
    int i;
    for( i = 0; i < GL.numNodes; i++ )
        visited[i] = FALSE;
    for( i = 0; i < GL.numNodes; i++ )
        if( !visited[i] )
            DFS( GL, i );
}

void BFSTraverse( GraphAdjList GL )
{
    int i;
    Queue Q;
    EdgeNode *p;
    for( i = 0; i < GL.numNodes; i++ )
        visited[i] = FALSE;
    
    InitQueue(&Q);

    for( i = 0; i < GL.numNodes; i++ )
    {
        if( !visited[i] )
        {
            visited[i] = TRUE;
            printf("%c ", GL.adjList[i].data);
            EnQueue( &Q, i );
            while( !QEmpty(&Q) )
            {
                DeQueue( &Q, &i );
                p = GL.adjList[i].firstedge;
                while( p != NULL )
                {
                    if( !visited[p->adjvex] )
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", GL.adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}