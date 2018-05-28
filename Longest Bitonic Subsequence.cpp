/* Longest Bitonic Subsequence :
 * Given an array find the length of the longest Bitonic Sequence. A Bitonic Sequence is one that first
 * increases and then decreases
 *
 * Solution:
 * Maintain two arrays lisf and lisr, i th index of which denotes the length of the Longest Increasing
 * Subsequence ending at i and in forward and reverse direction respectively.
 * LBS can now be given by the max(lisf[i] + lisr[i] - 1)
 *
 */

#include <bits/stdc++.h>
using namespace std;

// solve for each test case
void solve() {
    int n, resl = INT_MIN;
    cin >> n;
    int ar[n], lisf[n], lisr[n];

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        lisf[i] = lisr[i] = 1;
    }

    // construct LISF
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(ar[i] > ar[j])
                lisf[i] = max(lisf[i], lisf[j] + 1);
        }
    }

    // construct LISR
    for(int i = n-2; i >= 0; --i) {
        for(int j = n-1; j > i; --j) {
            if(ar[i] > ar[j])
                lisr[i] = max(lisr[i], lisr[j] + 1);
        }
    }

    // calculate the result
    for(int i = 0; i < n; ++i)
        resl = max(resl, lisf[i] + lisr[i] - 1);

    cout << resl << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
