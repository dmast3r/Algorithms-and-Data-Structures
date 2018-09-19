/*
Google interview question:

Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An]. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Input:
The first line consists of a single integer T, the number of test cases. For each test case, the first line contains an integer k denoting the number of painters and integer n denoting the number of boards. Next line contains n- space separated integers denoting the size of boards.

Output:
For each test case, the output is an integer displaying the minimum time for painting that house.

Constraints:
1<=T<=100
1<=k<=30
1<=n<=50
1<=A[i]<=500

Example:
Input:
2
2 4
10 10 10 10
2 4
10 20 30 40
Output:
20
60

Explanation:
1. Here we can divide the boards into 2 equal sized partitions, so each painter gets 20 units of the board and the total time taken is 20.
2. Here we can divide first 3 boards for one painter and the last board for the second painter.
Link:  https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0


Solution:- Assume each worker does atmost x unit of work, then we want to find if there exist an assignment of workers, such that no worker does
work greater than x unit and all the work is still completed. If the case is true for x, then, we can say with surety that such a case holds for
all y >= x, while it may or may not hold for some y < x. This gives us the montonic condition required for Binary Search.   

For a more detailed descritpion, see: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/
*/


#include<bits/stdc++.h>
using namespace std;

// Function that checks if an assignment of workers that can complete the work exist for max_work - the amount of work a worker can do at max.
bool predicate(int total_boards, int max_work, int max_workers, const int ar[]) {
	// atleast one worker will be assigned the job    
	// total_work is the total_work assigned to the current worker so far	
	int total_workers = 1, total_work = 0;

    for(int i = 0; i < total_boards; ++i) {
		// while the current worker can be assigned more work without exceeding the limit, assign him more work.
        if(total_work + ar[i] <= max_work)
            total_work += ar[i];

		// else assign work to next worker and set his assigned work so far to work to be done to paint the current board
        else {
            ++total_workers;
            total_work = ar[i];
        }
    }

	// are total workers required to complete all the work under given constraints less than or equal to the availaible? 
    return total_workers <= max_workers;
}

void solve() {
    int k, n;
    cin >> k >> n;
    int ar[n];

    for(auto &i : ar)
        cin >> i;

	// least-amount under all conditions can not be lesser than the amount of worker needed to be done to paint the largest board.
	// highest work will be when a single worker paints all the boards. The work will be sum total of the work done to paint each board. 
    int lo = *max_element(ar, ar + n), hi  = accumulate(ar, ar + n, 0);
    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(predicate(n, mid, k, ar))
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
