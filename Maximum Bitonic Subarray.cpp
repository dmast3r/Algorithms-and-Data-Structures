/*
	Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] ... = A[k + 1] >= .. A[j – 1] > = A[j]. Write a function that takes an array as argument and returns the length of the maximum length bitonic subarray.

*/


#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ar[n], dpf[n], dpr[n], res = 0;
    for(auto &i : ar)
        cin >> i;
    dpf[0] = 1;
    for(int i = 1; i < n; ++i) {
        dpf[i] = (ar[i] > ar[i-1] ? 1 + dpf[i-1] : 1);
    }
    dpr[n-1] = 1;
    for(int i = n - 2; i >= 0; --i) {
        dpr[i] = (ar[i] > ar[i+1] ? 1 + dpr[i+1] : 1);
    }

    for(int i = 0; i < n; ++i) {
        res = max(res, dpf[i] + dpr[i] - 1);
    }

    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
