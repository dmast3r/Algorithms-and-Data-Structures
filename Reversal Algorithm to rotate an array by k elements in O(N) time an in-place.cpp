#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;

    int ar[n];
    for(auto &i : ar)
        cin >> i;
    cin >> k;
    
    // take mod to handle the case when k >= n, mod is written in this way to handle the cases when k < 0
    k = (k % n + n) % n
        
    /* 
        This algorithm is for rotating array to the left, for rotating array to the right, do replace lines 26-28 with the
        below code:
       
        reverse(ar + n - k, ar + n);
        reverse(ar, ar + n - k);
        reverse(ar, ar + n);
    
    */
        
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
