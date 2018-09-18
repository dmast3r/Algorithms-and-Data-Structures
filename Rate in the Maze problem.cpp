#include <bits/stdc++.h>
using namespace std;

bool isMoveValid(int i, int j, int n) {
    return i >= 0 and i < n and j >= 0 and j < n;
}

void moveRecurse(int i, int j, int n, string moves, const vector<vector<int>> &matrix, vector<vector<bool>> &visited, set<string> &st) {
    if(i == n - 1 and j == n - 1) {
        st.insert(moves);
        return;
    }

    if(matrix[i][j] == 0 or visited[i][j])
        return;

    int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
    char move[] = {'D', 'R', 'U', 'L'};
    visited[i][j] = true;

    for(int k = 0; k < 4; ++k) {
        int next_i = i + di[k], next_j = j + dj[k];

        if(isMoveValid(next_i, next_j, n))
            moveRecurse(next_i, next_j, n, moves + move[k], matrix, visited, st);
    }

    visited[i][j] = false;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    set<string> st;

    for(auto &i : matrix) {
        for(auto &j : i)
            cin >> j;
    }


    moveRecurse(0, 0, n, "", matrix, visited, st);
    for(const auto i : st)
        cout << i << " ";
    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

