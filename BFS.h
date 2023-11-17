#ifndef BFS_H
#define BFS_H

#include "Graph.h"


class BFS
{
    public:
        bool* discovered;
        bool* processed;
        int* parent;
        //methods
        BFS();
        BFS(Graph* g);
        void bfs(Graph* g, int v);
        void process_edge(int x, int y);
};

#endif