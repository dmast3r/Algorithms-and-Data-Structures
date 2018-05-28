/* Graph is represented using an Adjacency List. An Adjacency List, for each vertex consists of a List of vertex adjacent to it.
 * Graph is collection of all such Adjacency Lists.
 * Every Adjacency List is represented as vectors of ints. Each int representing the number/unique id of the node or in other words destination number.
 * The entire Graph is thus an Array of vectors, there are V(V = total number of vertices in the Graph) such vectors each vector represents an Adjacency List.
 * When a new edge has to be added, simply push a new value to the Adjacency Vector of both source and destination(as the Graph is undirected).
 *
 *  ----------------------------------------------------------------------------------------------------------------------------------------------------------
 *  Performing Breadth First Search(BFS)
 *  1. Create a Queue and enqueue source into it.
 *  2. Mark source as visited.
 *  3. While the Queue is not empty, do:-
 *      a. Dequeue a the top vertex(let it be f)
 *      b. Enqueue all the nodes not yet visited and adjacent to f.
 *      c. Mark the enqueued nodes as visited
 */


#include <bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an undirected Graph
void addEdge(vector<int> adjList[], int source, int destination) {
    adjList[source].push_back(destination);
    adjList[destination].push_back(source); // if graph is directed then comment this line.
}

// start BFS from the vertex u. This will happen if u is the node we started with or u is not connected to the nodes reached so far.
void bfsUtil(int u, vector<int> adjList[], vector<bool> &visited, queue<int> &que) {
    visited[u] = true; // first mark u as visited.
    que.push(u); // push it into the Queue.

    while(!que.empty()) {
        // pop and print the front element
        int front = que.front();
        cout << front << " ";
        que.pop();

        // push into the Queue every unvisited node adjacent to the current node
        for(int i = 0; i < adjList[front].size(); ++i) {
            if(!visited[adjList[front][i]]) {
                que.push(adjList[front][i]); // push this adjacent node the Queue.
                visited[adjList[front][i]] = true; // mark it as visited.
            }
        }
    }
}

// do BFS for every node as some of them may be isolated from the vertices visited so far and thus un-reachable from these vertices.
void bfs(vector<int> adjList[], int num_vertices) {
    vector<bool> visited(num_vertices, false); // initially all vertices were unvisited.
    queue<int> que;

    for(int i = 0; i < num_vertices; ++i) {
        if(!visited[i])
            bfsUtil(i, adjList, visited, que);
    }
}

// The driver function
int main() {
    int num_vertices, num_edges; // number of vertices and edges respectively.
    cin >> num_vertices >> num_edges;
    vector<int> adjList[num_vertices];

    // add edges to the graph
    for(int i = 0; i < num_edges; ++i) {
        int a, b; // there is vertex between a and b
        cin >> a >> b;
        addEdge(adjList, a, b);
    }

    // finally perform BFS
    bfs(adjList, num_vertices);
    return 0;
}
