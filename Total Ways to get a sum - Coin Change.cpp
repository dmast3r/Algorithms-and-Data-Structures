// find the total number of coins to get required change
// author : themast3r

#include <bits/stdc++.h>
using namespace std;

long long int dp[100001];

void solve() {
    int v, n;
    cin >> n;
    long long int coins[n];

    for(auto &i : coins)
        cin >> i;
    sort(coins, coins + n);
    cin >> v;

    dp[0] = 1;
    for(int i = 1; i <= v; ++i)
        dp[i] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = coins[i]; j <= v; ++j) {
            dp[j] += dp[j-coins[i]];
        }
    }

    cout << dp[v] << endl;
}


int main() {
    int test;
    cin >> test;

    while(test--)
        solve();


}

