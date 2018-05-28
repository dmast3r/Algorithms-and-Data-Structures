/* Graph is represented using an Adjacency List. An Adjacency List, for each vertex consists of a List of vertex adjacent to it.
 * Graph is collection of all such Adjacency Lists.
 * Every Adjacency List is represented as vectors of ints. Each int representing the number/unique id of the node or in other words destination number.
 * The entire Graph is thus an Array of vectors, there are V(V = total number of vertices in the Graph) such vectors each vector represents an Adjacency List.
 * When a new edge has to be added, simply push a new value to the Adjacency Vector of both source and destination(as the Graph is undirected).
 */

#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an undirected Graph
void addEdge(vector<int> adjList[], int source, int destination) {
    adjList[source].push_back(destination);
    adjList[destination].push_back(source);
}

// A utility function to DFS of the Graph, starting from a given vertex u.
// visited is a boolean vertex that stores, if a particular node has been visited.
void dfsUtil(int u, vector<int> adjList[], vector<bool> &visited) {
    visited[u] = true; // first mark this node as visited
    cout << u << " "; // and print the vertex you just visited
    for(int i = 0; i < adjList[u].size(); ++i) {
        if(!visited[adjList[u][i]])
            dfsUtil(adjList[u][i], adjList, visited);
    }
}

// A utility function to perform DFS for all vertices(as some vertices may be isolated and not visited from other vertices)
void dfs(vector<int> adjList[], int num_vertices) {
    vector<bool> visited(num_vertices, false); // initially all nodes are unvisited.
    for(int i = 0; i < num_vertices; ++i) {
        if(!visited[i])
            dfsUtil(i, adjList, visited);
    }
}

// Driver code
int main() {
    int vertices = 5;
    vector<int> adj[vertices];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    dfs(adj, vertices);
    return 0;
}
