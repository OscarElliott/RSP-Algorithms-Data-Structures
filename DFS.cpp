#include "DFS.h"
#include<iostream>

DFS::DFS(Graph* g)
{
    discovered = new bool[g->nVerticies];
    processed = new bool[g->nVerticies];
    parent = new int[g->nVerticies];
    finished = false;
    for (int i = 0; i < g->nVerticies; i++)
    {
        discovered[i] = false;
        processed[i] = false;
        parent[i] = -1; // implies no parent
    }
}

void DFS::dfs(Graph* g, int v)
{
    if (finished) return;
    discovered[v] = true;
    edgenode* current = g->edgenodes[v];
    while (current != nullptr)
    {
        int y = current->y;
        if (discovered[y] == false)
        {
            parent[y] = v;
            process_edge(v,y);
            dfs(g,y);
        }
        else if (!processed[y] || g->directed)
            process_edge(v,y);
        if (finished) return;
        current = current->next;
    }
    std::cout << v << " ";
    processed[v] = true;
}  

void DFS::process_edge(int x, int y)
{
    //std::cout << x << " to " << y << " processed" << std::endl;
    return;
}