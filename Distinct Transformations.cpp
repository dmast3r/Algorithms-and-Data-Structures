/*
 *                          ------------------------------ Distinct Transformations ---------------------------------
 *  Given two strings A and B, such that |A| >= |B|, where |S| denotes the length of the string S. Then find the number of sub-sequences in A that are equal to B.
 *  
 *  Solution :- Suppose we are matching the ith character in B with that of the jth character in A, if the character matches then we will add to the answer the
 *  number of possible sub-sequences in A[0...j-1] that are equal to B[0...i-1]. But if the characters do not match then we want to recur for A[0...j-1] and 
 *  B[0..i]. Further since |A| >= |B| we should look for all potential matches of B[i] in A and build up a cumulative answer. Clearly this solution can optimised
 *  using Dynamic Programming. Let DP[i][j] denotes all the possible sub-sequences in A[0...j-1] that equals to B[0...i-1], first DP[i][j] should also contain all
 *  possibilities of A[0...j-2] and B[0...i-1] i.e. value of DP[i][j-1] so initialise DP[i][j] to it, next if B[j-1] matches A[i-1] then add to DP[i][j] all 
 *  possible values of A[0...j-2] and B[0...i-2] i.e. DP[i-1][j-1].
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a, b;
	int la, lb;
	cin >> a >> b;

	la = a.length(), lb = b.length();
	int dp[lb+1][la+1]; // dp[i][j] will represent all possible sub-sequences of A[0...j-1] that are equal to B[0...i-1] 

	for(int i = 0; i <= lb; ++i) {
		for(int j = 0; j <= la; ++j) {
			// initialise first row to 0. this done for getting correct answer if first char in B matches to any char in A
            if(i == 0)
				dp[i][j] = 1;
            
            // nothing to the left in an empty string    
			else if(j == 0)
				dp[i][j] = 0;
			
            else {
                // first add the cumulative answer for A[0...j-2] and B[0...i-1]
				dp[i][j] = dp[i][j-1];
                // if there is a match in A[j-1] and B[i-1] then add all possibilities of A[0...i-2] and B[0...j-2]
				if(a[j-1] == b[i-1])
					dp[i][j] += dp[i-1][j-1];
			}
		}
	}
    
	cout << dp[b.length()][a.length()] << endl;
}

int main() {
	int test;
	cin >> test;

	while(test--)
		solve();
}
