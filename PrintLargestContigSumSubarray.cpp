#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, negs = 0, ans, temp, r, l;
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

    temp = ans = *max_element(dp, dp + n);
    for(int i = n - 1; i >=0; --i) {
        if(dp[i] == ans) {
            l = r = i;
            break;
        }
    }

    while(true) {
        temp = temp - ar[l];
        if(temp == 0)
            break;
        --l;
    }

    cout << "left end = " << l << " and right end = "  << r << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
