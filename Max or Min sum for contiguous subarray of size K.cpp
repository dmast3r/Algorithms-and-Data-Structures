#include<bits/stdc++.h>
using namespace std;

int maxKSum(const int ar[], int n, int k = 1) {
    int sum = 0, res;

    for(int i = 0; i < k; ++i)
        sum += ar[i];
    res = sum;
    for(int i = k; i < n; ++i) {
        sum += ar[i];
        sum -= ar[i-k];
        res = max(res, sum);
    }

    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ar[n];

    for(auto &i : ar)
        cin >> i;

    cout << maxKSum(ar, n, k) << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
