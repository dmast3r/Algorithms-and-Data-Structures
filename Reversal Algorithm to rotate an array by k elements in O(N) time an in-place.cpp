#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;

    int ar[n];
    for(auto &i : ar)
        cin >> i;
    cin >> k;

    reverse(ar, ar + k);
    reverse(ar + k, ar + n);
    reverse(ar, ar + n);

    for(auto i : ar)
        cout << i << " ";
    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
