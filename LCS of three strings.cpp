#include<bits/stdc++.h>
using namespace std;

void solve() {
    int l1, l2, l3;
    string str1, str2, str3;
    cin >> l1 >> l2 >> l3 >> str1 >> str2 >> str3;
    int dp[l1 + 1][l2 + 1][l3 + 1];
    
    for(int i = 0; i <= l1; ++i) {
        for(int j = 0; j <= l2; ++j) {
            for(int k = 0; k <= l3; ++k) {
                if(i == 0 or j == 0 or k == 0)
                    dp[i][j][k] = 0;
                else if(str1[i-1] == str2[j-1] and str2[j-1] == str3[k-1])
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
        }
    }
    
    cout << dp[l1][l2][l3] << endl;
}

int main() {
	int test;
	cin >> test;
	
	while(test--)
	    solve();
	return 0;
}
