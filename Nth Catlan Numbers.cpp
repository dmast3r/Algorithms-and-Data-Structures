/*
	Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

See this for more applications.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ........

Dynamic Programming solution:-
dp[0] = 1;
dp[i] = sum(dp[j] * dp[i-1-j]), 0 <= j < i

Note - As Catlan Numbers grow very rapidly, many times the problem setter may ask you print the answer modulo 1e9+7, hence modify
this implementation accordingly.
*/

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long int dp[n+1] = {0};
    dp[1] = 1;
    
    for(int i = 2; i <= n; ++i) {
        long long int sum = 0;
        for(int j = 0; j < i; ++j)
            sum += dp[i] * dp[i-1-j];
        dp[i] = sum;
    }
    
    cout << dp[n] << endl;
}

int main() {
	int test;
	cin >> test;
	
	while(test--)
	    solve();
	return 0;
}
