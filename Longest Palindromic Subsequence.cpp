/*
 *
 * The idea is quite simple, if starting and ending characters(say s[l] and s[r]) matches then query for s[l+1] and
 * s[r-1] (and add 2 to the answer) else the answer is max of s[l+1]...s[r] and s[l]...s[r-1]
 * 
 * For bottom up implementation, first find LPSubseq for all smaller lenghts then gradually move to larger length.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;
    int len = (int)str.length(), dp[len][len];

    for(int l = 1; l <= len; ++l) {
        for(int i = 0; i <= len - l; ++i) {
            int j = i + l - 1;
            if(l == 1)
                dp[i][j] = 1;
            else if(l == 2)
                dp[i][j] = (str[i] == str[j] ? 2 : 1);
            else
                dp[i][j] = (str[i] == str[j] ? 2 + dp[i+1][j-1] : max(dp[i][j-1], dp[i+1][j]));
        }
    }

    cout << dp[0][len-1] << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
