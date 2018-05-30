#include <bits/stdc++.h>
using namespace std;

void solve() {
    int floors, eggs;
    cin >> eggs >> floors;
    // dp[i][j] will represent the minimum number of eggs, that are needed in the worst case to find the least floor
    // that will break the egg.
    int dp[floors+1][eggs+1];

    // for a single floor answer is always 1.
    for(int i = 1; i <= eggs; ++i)
        dp[1][i] = 1;
    // for a single egg and i floor, answer is always i.
    for(int i = 1; i <= floors; ++i)
        dp[i][1] = i;
    // for 0(no floor) answer is obviously always 0.
    for(int i = 0; i <= eggs; ++i)
        dp[0][i] = 0;

    for(int i = 2; i <= floors; ++i) {
        for(int j = 2; j <= eggs; ++j) {
            dp[i][j] = INT_MAX;

            // check which floor is best in the worst case.
            for(int k = 1; k <= i; ++k)
                // if egg breaks, then try at the lower floor with 1 lesser egg else try on remaining upper floors,
                // with the same number of eggs.
                dp[i][j] = min(dp[i][j], max(dp[k-1][j-1], dp[i-k][j]) + 1);
        }
    }

    cout << dp[floors][eggs] << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
