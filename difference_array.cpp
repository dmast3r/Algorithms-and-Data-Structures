#include <bits/stdc++.h>
using namespace std;

// answer query for any number between [1, 1000000]
int diff_ar[(int)1e6+1];

int main() {
    // n is the number of elements in the array q is the number of search queries
    int n, q;
    cin >> n;

    for(auto &i : diff_ar)
        i = 0;

    // handle all update queries queries, assumed to be n here
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;

        ++diff_ar[l];
        --diff_ar[r+1];
    }

    // generate the result after all updates are finished.
    for(int i = 1; i <= (int)2e5; ++i)
        diff_ar[i] += diff_ar[i-1];
    cin >> q;

    // answer q seacrh queries
    while(q--) {
        int p;
        cin >> p;

        cout << diff_ar[p] << endl;
    }
}
