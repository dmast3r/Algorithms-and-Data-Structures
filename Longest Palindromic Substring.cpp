#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;
    int len = (int)str.length(), max_len = 0, start;
    bool dp[len][len];

    memset(dp, false, sizeof dp);

    for(int l = 1; l <= len; ++l) {
        for(int i = 0; i <= len - l; ++i) {
            int j = i + l - 1;
            if(l == 1) {
                dp[i][j] = true;
                if(l > max_len) {
                    max_len = l;
                    start = i;
                }
            }
            else if(l == 2 and str[i] == str[j]) {
                dp[i][j] = true;
                if(l > max_len) {
                    max_len = l;
                    start = i;
                }
            }

            else if(l > 2 and dp[i+1][j-1] and str[i] == str[j]) {
                dp[i][j] = true;
                if(l > max_len) {
                    max_len = l;
                    start = i;
                }
            }
        }
    }

    for(int i = start; i < start + max_len; ++i)
        cout << str[i];
    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
