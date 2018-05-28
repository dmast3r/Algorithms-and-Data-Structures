/* Pritn LIS:
 * Print the Longest Increasing Subsequence.
 *
 * Solution:
 *  Maintain two arrays, first one that store the length of LIS ending at that index and second that stores
 *  the index of the second last integer for an LIS.
 */

#include <bits/stdc++.h>
using namespace std;

// solve for each test case
void solve() {
    int n, resl = INT_MIN, index;
    cin >> n;
    int ar[n], lis[n], lis_index[n];
    vector<int> lis_ints;

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        lis[i] = 1;
        lis_index[i] = -1; // -1 indicates the end of the LIS. Initially assume for every index the length
        // of lis ending there is one and thus LIS does not extend beyond that index.
    }

    // construct LIS
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(ar[i] > ar[j]) {
                if (lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                    lis_index[i] = j;
                }
            }
        }
    }

    // find the index where global LIS ends
    for(int i = 0; i < n; ++i) {
        if(resl < lis[i]) {
            resl = lis[i];
            index = i;
        }
    }

    // start from the ending index of global LIS, push numbers and backtrack
    for(int i  = index; i != -1;)  {
        lis_ints.push_back(ar[i]);
        i = lis_index[i];
    }

    // print using backward iterator....
    for(vector<int> :: reverse_iterator rit = lis_ints.rbegin(); rit != lis_ints.rend(); ++rit)
        cout << *rit << " ";
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
