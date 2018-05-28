#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, negs = 0;
    cin >> n;
    int ar[n], dp[n];

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        if(ar[i] < 0)
            ++negs;
        dp[i] = ar[i];
    }

    if(negs == n) {
        cout << *max_element(ar, ar + n) << endl;
        return;
    }

    for(int i = 1; i < n; ++i)
        dp[i] = max(dp[i], dp[i-1] + ar[i]);

    cout << *max_element(dp, dp + n) << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

