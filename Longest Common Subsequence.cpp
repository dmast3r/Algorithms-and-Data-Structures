#include<bits/stdc++.h>
using namespace std;

void solve() {
    int l1, l2;
    string str1, str2;
    cin >> l1 >> l2 >> str1 >> str2;
    int dp[l1 + 1][l2 + 1];
    
    for(int i = 0; i <= l1; ++i) {
        for(int j = 0; j <= l2; ++j) {
            if(i == 0 or j == 0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    cout << dp[l1][l2] << endl;
}

int main() {
	int test;
	cin >> test;
	
	while(test--)
	    solve();
	return 0;
}
