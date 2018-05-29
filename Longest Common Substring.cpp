/* The idea is to store the length of the longest common suffix for every pair of substring str1[0...m] and str2[0...n]. And then
find the largest value among all the stored values. Obviously for this, if last characters of str1[i...j] and str[k...l] do not match
then there is no common suffix hence the value 0, else it will be 1 + suffix between str1[i...j-1] and str2[k...l-1]
*/

#include <bits/stdc++.h>
using namespace std;

// solve for each test case
void solve() {
    string str1, str2;
    int m, n, resl = 0; // m and n are the sizes of the strings str1 and str2 respectively

    cin >> m >> n;
    cin >> str1 >> str2;
    int dp[m+1][n+1]; // create a two dimensional array of size (m + 1)*(n + 1). All the rows and columns will be filled with zeros

    // do the initialization -  pad all the rows as well columns with 0s
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= n; ++j)
            dp[i][j] = 0;
    }

    // dp[i][j] will store length of the maximum commong substring of str1[0...i-1] and str2[0...j-1]
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i][j] = (str1[i-1] == str2[j-1] ? dp[i-1][j-1] + 1 : 0);
        }
    }

    // search for the element with max value;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(dp[i][j] > resl)
                resl = dp[i][j];
        }
    }

    cout << resl << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
