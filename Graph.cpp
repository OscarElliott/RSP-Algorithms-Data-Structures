#include "Graph.h"
#include <iostream>

/* Implementation for Graph */

using namespace std;


Graph::Graph()
{
    this->directed = false;
    this->nVerticies = 0;
    this->nEdges = 0;
}

Graph* Graph::init_Graph(Graph *g, int n, bool Directed)
{
    g->directed = Directed;
    g->nVerticies = n;
    g->nEdges = 0;
    for(int i=1; i<=MAXV; i++)
    {
        g->outDegree[i] = 0;
        g->edgenodes[i] = NULL;
    }
    
    return g;
}

Graph* Graph::insert_edge(Graph *g, int x, int y, bool Directed)
{
    edgenode* edge = new edgenode;
    edge->y = y;
    edge->weight = 0;
    edge->next = g->edgenodes[x];

    g->edgenodes[x] = edge;
    g->outDegree[x]++;

    if(!Directed)
        g->insert_edge(g,y,x,true);
    else
        g->nEdges++;
    
    return g;
}


void Graph::print_Graph(Graph *g)
{
    for (int i = 0; i <= min(g->nVerticies, MAXV); i++)
    {
        cout << i << " -> ";
        edgenode *edge = g->edgenodes[i];
        while (edge != NULL)
        {
            cout << edge->y << " | ";
            edge = edge->next;
        }
        cout << endl;
    }
}