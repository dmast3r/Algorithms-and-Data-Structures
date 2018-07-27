/*
 *                      -------------------- Optimal Strategy For Game Pick - By Sourabh Khandelwal(themast3r) ---------------------
 *  Given an array of n coins, where you can either pick the first or the last coin, you and your opponent are playing this game. The task is to collect maximum
 *  amount of sum assuming that the opponent is equally smart and you play the first move.
 *  
 *  Solution:-
 *  We can pick either first or the last coin but since the opponent is equally smart he will leave us in a situation that our next move will get the minimum
 *  possible sum. That is suppose in the range [i...j] we pick the ith coin then opponent can select either i+1 or j th coin leaving us in next move either with
 *  [i+2...j] or [i+1..j-1] but since the opponent is smart he will pick the coin which leads to the next movie which has the minimum sum i.e.
 *  min(f[i+1...j-1], f[i+2...j]). Similarly if select the jth coin instead opponent will leave us in the situation min(f[i+1...j-1], f[i...j-2]). Clearly our 
 *  task is to select the configuration with max result that is max(ar[i] + min(f[i+1...j-1], f[i+2...j]), ar[j] + min(f[i+1...j-1], f[i...j-2])).
 *  
 *  It's apparent that it's a Dynamic Programming problem and solutions can be thus be saved.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    // ar holds the value of coins
    // dp[i][j] will store max amount that can be extracted from the range[i...j]
    int ar[n], dp[n][n];
    for(auto &i : ar)
        cin >> i;

    // iterate over ranges of length 1 to n
    for(int l = 1; l <= n; ++l) {
        // i is the start point
        for(int i = 0; i <= n - l; ++i) {
            // j is the end point
            int j = i + l - 1;
            
            // for length 1 answer is obviously the value itself since we get the chance to open the game
            if(l == 1)
                dp[i][j] = ar[i];

            // for the same reason as above, for length 2 answer is max of the two values    
            else if(l == 2)
                dp[i][j] = max(ar[i], ar[j]);

            // apply recurrence relation for the ranges with length greater than 2    
            else
                dp[i][j] = max(ar[i] + min(dp[i+2][j], dp[i+1][j-1]), ar[j] + min(dp[i+1][j-1], dp[i][j-2]));
        }
    }

    // print the answer for the entire range [0...n-1]
    cout << dp[0][n-1] << endl;
}

int main() {
	int test;
	cin >> test;

	while(test--)
		solve();
}
