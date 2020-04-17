/*
    Longest Increasing Subsequence using BIT
*/

#include <bits/stdc++.h>
using namespace std;

// map actual values in [1, N]
void coordinateCompression(int ar[], const int &n) {
    set<int> st;
    map<int, int> mp;
    int idx = 0;

    for(int i = 0; i < n; ++i)
        st.insert(ar[i]);
    
    for(const auto &num : st)
        mp[num] = ++idx;

    for(int i = 0; i < n; ++i)
        ar[i] = mp[ar[i]];
}

// find LIS till idx. Simply find the max that we can get in the prefix idx.
// caller will pass idx - 1 as param. So, idx = idx - 1
int query(int bit[], int idx) {
    int ans = 0;

    while(idx) {
        ans = max(ans, bit[idx]);
        idx -= idx & (-idx);
    }

    return ans;
}

// update LIS.
void update(int bit[], int idx, int n) {
    // get current LIS at the previous index
    int res = query(bit, idx - 1);

    // new LIS will be idx_previous_index + 1
    while(idx <= n) {
        bit[idx]  = max(res + 1, bit[idx]);
        idx += idx & (-idx);
    }
}

int main() {
    int n;
    cin >> n;
    int ar[n];

    for(auto &num : ar)
        cin >> num;

    coordinateCompression(ar, n);
    int bit[n + 1] = {0};

    for(int i = 0; i < n; ++i)
        update(bit, ar[i], n);
    
    cout << query(bit, n) << endl;
}
