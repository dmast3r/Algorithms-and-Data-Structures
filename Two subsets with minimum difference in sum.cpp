/*
Asked in - Amazon.
This problem is similar to the subset sum problem. The max possible sum can be equal to the sum of all the elements in the set, for every number lying in the range [0, sum(set)] find if it is possible to obtain, this is just the usual subset-sum problem. Now the minimum differnce will be when sum of one of the set is as close to sum(set)/2. So, start with set(sum)/2 and check if it is possible to obtain it, and jeep decrementing till
1. Also handle the case when n = 1, print the only element of the array.
*/

#include<bits/stdc++.h>
using namespace std;

bool dp[51][2501];

void solve() {
    int n, sum = 0;
    cin >> n;
    int ar[n];


    for(auto &i : ar) {
        cin >> i;
        sum += i;
    }

    if(n == 1) {
        cout << sum << endl;
        return;
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= sum; ++j) {
            if(j == 0)
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }

    sort(ar, ar + n);

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= 2500; ++j) {
            if(j < ar[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-ar[i-1]] | dp[i-1][j];
        }
    }

    for(int i = sum/2; i >= 1; --i) {
        if(dp[n][i])  {
            cout << sum - 2*i << endl;
            break;
        }
    }
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
    return 0;
}
