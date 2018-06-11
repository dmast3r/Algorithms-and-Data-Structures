#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int m, int n, const vector<vector<int>> matrix, vector<vector<bool>> visited) {
    return row < m and row >= 0 and col < n and col >= 0 and matrix[row][col] and !visited[row][col];
}

void DFS(int row, int col, int &count, int m, int n, const vector<vector<int>> matrix, vector<vector<bool>> &visited) {
    static int rows[] = {1, 1, 1, 0, -1, -1, -1, 0}, columns[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    visited[row][col] = true;

    for(int k = 0; k < 8; ++k) {
        int new_row = row + rows[k];
        int new_col = col + columns[k];

        if(isSafe(new_row, new_col, m, n, matrix, visited)) {
            ++count;
            DFS(new_row, new_col, count, m, n, matrix, visited);
        }
    }
}

void solve() {
    int m, n, res = 0;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // A M * N matrix to keep track of the visited cell.

    for(auto &i : matrix) {
        for(auto &j : i)
            cin >> j;
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] and !visited[i][j]) {
                int count = 1;
                DFS(i, j, count, m, n, matrix, visited);
                res = max(res, count);
            }
        }
    }

    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
