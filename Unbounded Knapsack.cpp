/*
 *                                                          *** Unbounded Knapsack ***
 *  This problem is similar to the 0-1 Knapsack problem but their is no constraint on the quantity of each item, that is there is an infinite supply of item of
 *  each type. The Brute-Force approach is to try all possible combinations of items for a given weight. This solution has overlapping subproblems and optimal
 *  subsrtucture, so we can use memoization to save some answers. Alternatively we can build the answer in bottom-up fashion. For a given weight we start by try
 *  picking all possible weights and find the best result that we can pick using that(this is the Dynamic Programming part). We will need only an 1-D array for
 *  the purpose.
*/

#include <bits/stdc++.h>
using namespace std;

long long int dp[1000001];

void solve() {
    int n, w; // n is the total number of items and w is the total weight capacity of the knapsack
    cin >> n >> w;
    pair<int, int> items[n];

    // scan values
    for(int i = 0;  i < n; ++i)
        cin >> items[i].first;
    // scan weights
    for(int i = 0; i < n; ++i)
        cin >> items[i].second;
    // initialise the array used for storing results
    fill(begin(dp), end(dp), 0);

    for(int i = 0; i <= w; ++i) { // compute answer for all weights starting from 0
        for(int j = 0; j < n; ++j) { // check if current item can be selected, if yes find the best answer that we can get by choosing it
            if(items[j].second <= i)  // if weight of current item is smaller than computation weight
                dp[i] = max(dp[i], dp[i-items[j].second] + items[j].first); // find the best answer for computation_weight-current_item_weight and add to it the value of current item.
        }
    }

    cout << dp[w] << endl;

}

// solve for each test case
int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
