/*
 *                                               ---- Detect Cycle in a Undirected Graph ---
 *  Apply Depth First Search. Initially mark all the nodes as unvisited, now choose a particular node which has not been visited and apply DFS through it, mark
 *  visited all the nodes that you visit in the process. Also keep track of the parent of the current node. If v is visited by applying DSF from u then u is a 
 *  parent of v. If a node v has already been visited but is not the parent of u, then there is a cycle in the Graph.
 *  
 *  Note:- This method won't work when there are parallel edges in the Garph.
 *  Note2:- This method won't work for directed graphs.
 */

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isCyclic();
};

bool isCyclicUtil(int u, bool visited[], list<int> *adj, int parent) {
    visited[u] = true;

    for(auto v : adj[u]) {
        if(!visited[v]) {
            if(isCyclicUtil(v, visited, adj, u))
                return true;
        }

        else if(v != parent)
            return true;
    }

    return false;
}

bool Graph :: isCyclic() {
    bool visited[V] = {false};

    for(int i = 0; i < V; ++i) {
        if(!visited[i]) {
            if(isCyclicUtil(i, visited, adj, -1))
                return true;
        }
    }
    return false;
}
