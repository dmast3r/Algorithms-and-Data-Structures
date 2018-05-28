#include<bits/stdc++.h>
using namespace std;

bool dp[101][100001];

void solve() {
    int n, sum = 0;
    cin >> n;
    int ar[n];
    
    
    for(auto &i : ar) {
        cin >> i;
        sum += i;
    }
    
    if(sum % 2) {
        cout << "NO" << endl;
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
        for(int j = 0; j <= 100000; ++j) {
            if(j < ar[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-ar[i-1]] | dp[i-1][j];
        }
    }

    cout << (dp[n][sum/2] ? "YES" : "NO") << endl;
}

int main() {
	int test;
	cin >> test;
	
	while(test--)
	    solve();
	return 0;
}
