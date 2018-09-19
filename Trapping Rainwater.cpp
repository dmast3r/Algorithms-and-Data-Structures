/*
	------------------------------------------------------------- Trapping Rainwater --------------------------------------------------------------
	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after 
	raining.

	Examples:

	Input: arr[]   = {2, 0, 2}
	Output: 2
	Structure is like below
	| |
	|_|
	We can trap 2 units of water in the middle gap.

	Input: arr[]   = {3, 0, 0, 2, 0, 4}
	Output: 10
	Structure is like below
		 |
	|    |
	|  | |
	|__|_| 
	We can trap "3*2 units" of water between 3 an 2,
	"1 unit" on top of bar 2 and "3 units" between 2 
	and 4.  See below diagram also.

	Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
	Output: 6
		   | 
	   |   || |
	_|_||_||||||
	Trap "1 unit" between first 1 and 2, "4 units" between
	first 2 and 3 and "1 unit" between second last 1 and last 2 

	Asked in: Amazon, Microsoft, DE-Shaw

	------------------------------------------------------------------- Solution -------------------------------------------------------------------
	Use Divide and Conquer approach, let all the bars be in the range [L, R] then find the immediate right bar to L in [L, R] which is also higher 
	to the bar at L, let us call it next_big_L, similarly find the immediate next higher bar than the bar at R, in the range [L, R] and to the left
	of L, let us call it next_big_R. Then the total water accumulated water is given by the recursive formula-

	sum([l+1, next_big_L-1]) + sum([next_big_R+1, R-1]) + solveRecursive(next_big_L, next_big_R) 

	Time Complexity: O(N)
	Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// A utility function to recursively divide the problem and solve it
int solveRecursive(int l, int r, int ar[]) {
	// The base case. recur until l is smaller than r.    
	if(l >= r)
        return 0;

    int l_val = ar[l], r_val = ar[r]; // values at the extreme indices
	// next_big_l and next_big_r holds the value of next higher bar on the left and the right respectively
	// sum will hold the water accumulate between (l, next_big_l) and (next_big_r, r)   
	int next_big_l = l + 1, next_big_r = r - 1, sum = 0; 

	// find the position of next_big_l and next_big_r
    while(next_big_l < r and ar[next_big_l] <= l_val)
        ++next_big_l;
    while(next_big_r > l and ar[next_big_r] <= r_val)
        --next_big_r;

	// these are the two sepcial cases:-
	// 1. l is the highest bar in [l, r], so, set next_big_l to it
	// 2. r is the highest bar in [l, r], so, set next_big_r to it
    if(next_big_l == r and l_val >= r_val)
        next_big_l = l;
    else if(next_big_r == l and r_val >= l_val)
        next_big_r = r;

	// sum up the accumulated water between the bars
    for(int i = l + 1; i < next_big_l; ++i)
        sum += (l_val - ar[i]);
    for(int i = r - 1; i > next_big_r; --i)
        sum += (r_val - ar[i]);

	// recur for the remaining bars lying between (next_big_l, next_big_r)
    return sum + solveRecursive(next_big_l, next_big_r, ar);
}

// solve for multiple test cases
void solve() {
    int n;
    cin >> n;
    int ar[n];

    for(auto &i : ar)
        cin >> i;
    cout << solveRecursive(0, n-1, ar) << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
