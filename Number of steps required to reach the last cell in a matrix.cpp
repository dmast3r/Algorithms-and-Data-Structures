#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int dp[n][m];

    for(auto &i : dp) {
        for(auto &j : i)
            j = 0;
    }

    while(k--) {
        int r, c;
        cin >> r >> c;
        dp[--r][--c] = -1;
    }

    if(dp[0][0] == -1) {
        cout << 0 << endl;
        return;
    }

    // initialise the left-most column;
    for(int r = 1; r < n; ++r) {
        if(dp[r][0] == -1)
            break;
        dp[r][0] = 1;
    }

    // initialise the top-most row
    for(int c = 1; c < m; ++c) {
        if(dp[0][c] == -1)
            break;
        dp[0][c] = 1;
    }

    // compute for rest of the cells
    for(int r = 1; r < n; ++r) {
        for(int c = 1; c < m; ++c) {
            // if the cell is blocked then ignore it
            if(dp[r][c] == -1)
                continue;


            if(dp[r-1][c] != -1)
                dp[r][c] = (dp[r][c] % MOD + dp[r-1][c] % MOD) % MOD;
            if(dp[r][c-1] != -1)
                dp[r][c] = (dp[r][c] % MOD + dp[r][c-1] % MOD) % MOD;
        }
    }

    // if the last isn't blocked or there is atleast one way to reach there then print the result or 0 otherwise
    cout << (dp[n-1][m-1] > 0 ? dp[n-1][m-1] : 0) << endl;
}

int main() {
    int test;
    cin >> test;
    
    while(test--)
        solve();
}
