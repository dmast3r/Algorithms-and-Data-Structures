/*
*	------------------------------- Given two n-ary trees identify if the two trees are mirror of each other --------------------------------------
*	The idea is simple, represent both graph as adjacency list and the invert either of the graph. After inversion the two graphs must compare equal
*	to be mirror of each other. 
*	
*	For inversion apply BFS or DFS and reverse the order of children of the current vertex.
*/

#include <bits/stdc++.h>
using namespace std;

void invertTreeUtil(int i, bool visited[], vector<int> graph[]) {
    queue<int> q;

    visited[i] = true;
    q.push(i);

    while(!q.empty()) {
        int top_element = q.front();
        q.pop();

        // reverse the children of the current vertex
        reverse(graph[top_element].begin(), graph[top_element].end());
        for(auto v : graph[top_element]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void invertTree(int n, vector<int> graph[]) {
    bool visited[n] = {false};
    for(int i = 0; i < n; ++i) {
        if(!visited[i])
            invertTreeUtil(i, visited, graph);
    }
}

void addEdge(int e, vector<int> graph[]) {
    while(e--) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        graph[u].push_back(v);
    }
}


void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> graph1[15], graph2[15];

    addEdge(e, graph1);
    addEdge(e, graph2);

    invertTree(n, graph1);
    // compare graphs
    for(int i = 0; i < n; ++i) {
        if(graph1[i].size() != graph2[i].size()) {
            cout << 0 << endl;
            return;
        }

        for(int j = 0; j < graph1[i].size(); ++j) {
            if(graph1[i][j] != graph2[i][j]) {
                cout << 0 << endl;
                return;
            }
        }
    }

    cout << 1 << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
