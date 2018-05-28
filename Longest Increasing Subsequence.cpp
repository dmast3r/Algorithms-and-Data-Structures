/* Here is an idea:
Naive Approach:
Calculate all the longest Subsequence ending at index i for i in [1, n] (assume for a while index starts at 1 and length of the input
array is n) and then calculate max of it. This has an optimal substructure property. That is, to find max subsequence for a sequence
ending at i: max(i) = 1 + max(j), such that i <= j <= i-1 and ar[i] > ar[j].

Dynamic Programming:
If we draw a recursion tree we will that values are computed again and again, we can thus store computed values to use them in future
*/

#include <bits/stdc++.h>
using namespace std;

// solve for each test case
void solve() {
    int n, max_sub = 1;
    cin >> n;

    if(n == 0) {
        cout << 0 << endl;
        return;
    }

    int ar[n], dp[n]; // dp[i] will store value LIS for an array ending at i

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        dp[i] = 1;
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(ar[i] > ar[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for(int i = 0; i < n; ++i)
        max_sub = max(max_sub, dp[i]);

    cout << max_sub << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
