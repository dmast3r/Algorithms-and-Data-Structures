/*
	Given two strings, if you can only perfor either of three operations:-
	1. Replace one character
	2. Remove one character
	3. Insert one character
	If each of the operation has a unit cost then find the minimum cost required to make both the strings equal to each other.

	Solution:-
	This is a Dynamic Programming problem. 

	What are the subproblems in this case?
	The idea is process all characters one by one staring from either from left or right sides of both strings.
	Lets suppose we traverse from right corner, there are two possibilities for every pair of character being traversed.

	m: Length of str1 (first string)
	n: Length of str2 (second string)

    If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for 		lengths m-1 and n-1.
    	Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first 			string, recursively compute minimum cost for all three operations and take minimum of three values.
        Insert: Recur for m and n-1
        Remove: Recur for m-1 and n
        Replace: Recur for m-1 and n-1


		So, DP states will be-
		DP[len1+1][len2+1]
		DP[i][j] = i, if j = 0
		DP[i][j] = j, if i = 0
		DP[i][j] = DP[i-1][j-1] if str1[i-1] = str[j-1]
		DP[i][j] = 1 + min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1])), otherwise.
*/


#include<bits/stdc++.h>
using namespace std;

void solve() {
    int len1, len2;
    string str1, str2;
    cin >> len1 >> len2 >> str1 >> str2;

    int dp[len1 + 1][len2 + 1];
    for(int i = 0; i <= len1; ++i) {
        for(int j = 0; j <= len2; ++j) {
            if(i == 0 or j == 0)
                dp[i][j] = 1;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    cout << dp[len1][len2] << endl;
}

int main() {
    int test;
    cin >> test;
    while(test--)
        solve();
}
