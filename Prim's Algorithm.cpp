#include <bits/stdc++.h>
using namespace std;

int N;

int getMinKeyIndex(int key[], bool in_mst[]) {
    int min_key = INT_MAX, index;

    for(int i = 0; i < N; ++i) {
        if(!in_mst[i] and key[i] <= min_key) {
            min_key = key[i];
            index = i;
        }
    }

    return index;
}

void printMST(int **graph, int parent[]) {
    //cout << "Parent\t" << "Child\t" << "Weight\n";
    //for(int i = 1; i < N; ++i)
        //cout << parent[i] << "\t--->\t" << i << "\t" << graph[i][parent[i]] << endl;
    int sum_weight = 0;
    for(int i = 1; i < N; ++i)
        sum_weight += graph[i][parent[i]];
    cout << sum_weight << endl;
}

void primMST(int **graph) {
    int parent[N], key[N];
    bool  in_mst[N];

    for(int i = 0; i < N; ++i) {
        parent[i] = -1;
        in_mst[i] = false;
        key[i] = INT_MAX;
    }

    key[0] = 0;

    for(int count  = 0; count < N - 1; ++count) {
        int u = getMinKeyIndex(key, in_mst);
        in_mst[u] = true;

        //cout << endl << "u = " << u << endl;

        for(int v = 0; v < N; ++v) {
            if(graph[u][v] and !in_mst[v] and graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(graph, parent);
}

void solve() {
    int edges;
    cin >> N >> edges;
    int **graph = new int *[N];

    for(int i = 0; i < N; ++i)
        graph[i] = new int[N];


    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            graph[i][j] = 0;
    }

    for(int i = 0; i < edges; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1][b-1] = graph[b-1][a-1] = c;
    }

    primMST(graph);
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
