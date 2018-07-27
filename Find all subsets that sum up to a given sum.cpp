/*
 *      Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.
 *      
 *      Solution - The problem is a variation of the subset sum problem. In the DP state instead of maintaining wheather dp[i][sum] is possible using first 
 *      i elements maintain the count.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;

    int ar[n];
    for(auto &i : ar)
        cin >> i;
    cin >> k;

    long long int dp[n][k+1];
    for(auto &i : dp) {
        for(auto &j : i)
            j = 0;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= k; ++j) {
            if(i == 0)
                dp[i][j] = (j == ar[i] ? 1 : 0);

            else if(j < ar[i])
                dp[i][j] = dp[i-1][j];

            else if(j == ar[i])
                dp[i][j] = 1 + dp[i-1][j];

            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-ar[i]];
        }
    }

    cout << dp[n-1][k] << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

