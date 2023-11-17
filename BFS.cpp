#include "BFS.h"
#include<iostream>
#include <queue>

using namespace std;

BFS::BFS(Graph* g)
{
    discovered = new bool[g->nVerticies];
    processed = new bool[g->nVerticies];
    parent = new int[g->nVerticies];
    for (int i = 0; i < g->nVerticies; i++)
    {
        discovered[i] = false;
        processed[i] = false;
        parent[i] = -1; // implies no parent
    }
}

void BFS::bfs(Graph* g, int v)
{
    queue<int> Queue;
    Queue.push(v);
    discovered[v] = true;
    int current = v;
    edgenode* p;
    int y;

    while(!Queue.empty())
    {
        current = Queue.front();
        Queue.pop();
        cout << current << " ";
        processed[current] = true;
        p = g->edgenodes[current];
        while (p != nullptr)
        {
            y = p->y;
            if (processed[y] == false || g->directed)
                process_edge(v,y);
            if (discovered[y] == false)
            {
                Queue.push(y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
    }
}

void BFS::process_edge(int x, int y)
{
    //cout << x << " to " << y << " processed" << endl;
    return;
}