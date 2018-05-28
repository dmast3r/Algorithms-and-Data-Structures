#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, sum = 1;
    cin >> n;
    int ar[n], dp[n];

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        dp[i] = 1;
    }

    for(int i = 1; i < n; ++i) {
        if(ar[i-1] <= ar[i])
            dp[i] = dp[i-1] + 1;
        sum += dp[i];
    }

    cout << sum << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
