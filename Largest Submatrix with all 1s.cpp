#include<bits/stdc++.h>
using namespace std;


bool isMoveValid(int i, int j, int m, int n) {
    return i >= 0 and i < m and j >= 0 and j < n;
}

int getAnswer(const vector<vector<int>> &vec) {
    int m = vec.size(), n = vec[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(vec[i][j] != 0) {
                int up, left, up_left;
                up = (isMoveValid(i-1, j, m, n) ? dp[i-1][j] : 0);
                left = (isMoveValid(i, j-1, m, n) ? dp[i][j-1] : 0);
                up_left = (isMoveValid(i-1, j-1, m, n) ? dp[i-1][j-1] : 0);

                dp[i][j] = 1 + min(up_left, min(up, left));
            } else
                dp[i][j] = 0;
        }
    }

    int res = 0;
    for(auto i : dp) {
        for(auto j : i)
            res = max(res, j);
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n, 0));

    for(auto &i : vec) {
        for(auto &j : i)
            cin >> j;
    }

    cout << getAnswer(vec) << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--)
        solve();
}
