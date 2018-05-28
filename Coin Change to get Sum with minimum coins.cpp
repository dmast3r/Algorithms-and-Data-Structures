// find the minimum number of coins required to make a change. Print -1 if not possible.

#include <bits/stdc++.h>
using namespace std;

long long int dp[10001];

void solve() {
    int v, n;
    cin >> v >> n;
    long long int coins[n];

    for(auto &i : coins)
        cin >> i;
    sort(coins, coins + n);

    dp[0] = 0;
    for(int i = 1; i <= v; ++i)
        dp[i] = INT_MAX;

    for(int i = 0; i < n; ++i) {
        for(int j = coins[i]; j <= v; ++j) {
            dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
        }
    }

    cout << (dp[v] == INT_MAX ? -1 : dp[v]) << endl;
}


int main() {
    int test;
    cin >> test;

    while(test--)
        solve();


}

