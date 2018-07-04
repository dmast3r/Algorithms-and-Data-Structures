/*
 *  --------------------------------------------------- Floyd Warshall - Sourabh Khandelwal(themast3r) -------------------------------------------------------
 *  The Floyd Warshall Algorithm proceeds by assuming vertex k as the intermediate vertex between i and j. So, minimum distance between any pair i and j
 *  can be found by taking the min of existing distance between them and the distance between them through the vertex k. Starting from the vertex 1, all
 *  the vertices till n are assumed intermediate and the distance between all source-destination pairs are updated. Therefore, all vertex in [1, k-1] were
 *  selected as intermediate before k was selected as one.
 * */

#include <bits/stdc++.h>
using namespace std;

void floydWarshall(const vector<vector<int>> &graph) {
    vector<vector<int>> dp(graph); // initialise the floyd-warshall matrix same as that of the input matrix
    auto n = (int) graph.size();

    // choose k as an intermediate vertex
    for(int k = 0; k < n; ++k) {
        // choose source
        for(int i = 0; i < n; ++i) {
            // choose destination
            for(int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    // print the shortest distances between all pairs
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j)
            cout << dp[i][j] << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    for(auto &i : graph) {
        for(auto &j : i)
            cin >> j;
    }

    floydWarshall(graph);
}

int main() {
    int test;
    cin >> test;

    while (test--)
        solve();
}

