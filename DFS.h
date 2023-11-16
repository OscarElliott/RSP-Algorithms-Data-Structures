#ifndef DFS_H
#define DFS_H

#include "Graph.h"


class DFS
{
    public:
        bool finished;
        bool* discovered;
        bool* processed;
        int* parent;
        //methods
        DFS();
        DFS(Graph* g);
        void dfs(Graph* g, int v);
        void process_edge(int x, int y);
};

#endif