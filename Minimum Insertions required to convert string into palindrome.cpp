#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;
    int len = str.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));

    for(int l = 2; l <= len; ++l) {
        for(int i = 0; i <= len - l; ++i) {
            int j = i + l - 1;
            if(l == 2)
                dp[i][j] = (str[i] == str[j] ? 0 : 1);
            else if(str[i] == str[j])
                dp[i][j] = dp[i+1][j-1];
            else
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);

        }
    }
    cout << dp[0][str.length() - 1] << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
