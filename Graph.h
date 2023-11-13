#ifndef Graph_H
#define Graph_H

struct edgenode
{
    int y;
    int weight;
    struct edgenode *next;
} ;

#define MAXV 100 // MAX number of verticies (change as needed for implementation)

class Graph
{
    public:
        // variables
        edgenode *edgenodes[MAXV+1];
        int outDegree[MAXV+1];
        int nVerticies;
        int nEdges;
        bool directed;
        // methods
        Graph();
        Graph* init_Graph(Graph *g, int n, bool Directed);
        Graph* insert_edge(Graph *g, int x, int y, bool Directed);
        void print_Graph(Graph *g);
};
#endif
