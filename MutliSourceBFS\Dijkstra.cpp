/*
 *                         ---------------------------- MultiSource BFS/Dijkstra -----------------------------------------
 *  Given a 2-D matrix representing a BITMAP, matrix[i][j] is 1 if the value is white and 0 otherwise. The task is to find the minimum distance of each pixel 
 *  from  the nearest white pixel.
 *  
 *  Solution :- We can assume the BITMAP to be a adjacency graph representation. And Now apply Dijsktra with multiple source, initially, insert all the white
 *  pixels into the set used for extracting min and with the distance = 0(all white pixel are nearest to themselves with distance = 0). Now apply Dijkstra as
 *  you would do usually.
 *
 */

#include<bits/stdc++.h>
using namespace std;


// check if the next cell is valid(within the BITMAP)
bool isValid(int i, int j, int m, int n) {
    return i >= 0 and i < m and j >= 0 and j < n;
}

// a utility function for applying BFS
// dist[i][j] stores the minimum distance of the i,j th cell from the nearest white cell
// st is used for applying Dijkstra
void multiBFSUtil(const vector<vector<int>> &graph, vector<vector<int>> &dist, set<pair<int, pair<int, int>>> &st) {
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}; // used for checking adjacent nodes, to the current node. bottom, right, top, left.
    auto m = (int)graph.size(), n = (int)graph[0].size();

    // while there are still some nodes in the graph unvisited
    while (!st.empty()) {
        // grab the node with least distance
        // it will be the node in the front of the set, as set sorts the items with respect to keys(which is distance here)
        pair<int, pair<int, int>> top = *st.begin();
        int i = top.second.first, j = top.second.second;
        st.erase(st.begin()); // remove this node from the set as it has been visited

        // check for all the four adjacent nodes
        for(int k = 0; k < 4; ++k) {
            // if the adjacent node is valid and is a greater distance than it should be
            if(isValid(i+dx[k], j+dy[k], m, n) and dist[i+dx[k]][j+dy[k]] > dist[i][j] + 1) {
                // grab this node and erase it's current existence
                auto it = st.find({dist[i+dx[k]][j+dy[k]], {i+dx[k], j+dy[k]}}); 
                st.erase(it);
                
                // update the min-distance and re-insert the node
                dist[i+dx[k]][j+dy[k]] = dist[i][j]+1;
                st.insert({dist[i][j] + 1, {i+dx[k], j+dy[k]}});
            }
        }
    }
}

// Apply Multi-Source Dijsktra
void multiBFS(const vector<vector<int>> &graph) {
    int m, n; // graph is of the size mXn.
    // dist[i][j] stores the minimum distance of the i,j th cell from the nearest white cell
    vector<vector<int>> dist(m = graph.size(), vector<int>(n = graph[0].size(), 100000));
    set<pair<int, pair<int, int>>> st; // distance from source : i,j
    
    // if the value of a cell in the BITMAP is 1
    // then the closest distance to nearest white cell is 0
    // else assume the min distance to be a large value initially, it will later be updated.
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(graph[i][j] == 1)
                dist[i][j] = 0;
            st.insert({dist[i][j], {i, j}}); // insert into the set with their respective initial distance. 0 for white cells, large value for black cells
        }
    }

    multiBFSUtil(graph, dist, st);

    // print the distance of each cell from the white cell nearest to it.
    for(auto i : dist) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

// solve for each test case
void solve() {
    int m, n; // graph is of the size mXn.
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n, 0));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j)
            cin >> graph[i][j];
    }

    multiBFS(graph);
}

int main() {
    int test;
    cin >> test;

    while (test--)
        solve();
}
