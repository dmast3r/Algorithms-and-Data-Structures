/*
*	------------------------------------------------------ Activity Selection Problem --------------------------------------------------------------
*						------------------------------- By - Sourabh Khandelwal(themast3r) --------------------------------------
*
*	Given N activities with each having certain starting and ending time, the task is to find out the maximum number of activities that can be 
*	perfomed by a person, assuming he can only perform one activity at a time.
*
*	Solution:-
*	One obvious way is to assume that i th is to be performed and then select all the activities that can be performe with i. We can further
*	optimise this using Dynamic Programming the task is similar to finding longest increasing subsequence. 
*
*	Let's discuss the optimal solution using Greedy Algorithm in O(N*log(N)). Let us first sort all the activities by their starting time, the
*	reason for this will be clear in a moment. Next suppose we are at the i'th activity that is the decision to whether or not select any activity
*	between [1, i-1] has been done. So, if the current activity - the ith activity does not overlap with the last picked activity then we can safely
*	pick both the activities, but if the current activity overlaps with the previously picked activity then obviously we can choose only one of
*	the activity. The Greedy approach is to choose the activity which has the least finish time, this way we can ensure that the picked activity
*	overlaps the least with rest of the activities. We can maintain two variables res(to denote total activities choosen) initialised to 1(since
*	atleast one activity will always be choosen) and another variable last_picked initialised to 0(0 based indexing) indicating 0th activity has 
*	been choosen initially. Next if the last_picked activity does not overlap with the current activity then we can increment res by one since 
*	additional one activity has been choosen and set last_picked to the current activity. If the two activities overlap we select only one of the
*	activities as discussed, this time there is no increase in res and the picked activity is the activity with the least finish time so set
*	last_picked to it.  
*
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	// n denotes the total number of activites
	// res will hold the max amonut of activities choosen so far
	// last_pick stores the index of the last picked activity
    int n, res = 1, last_picked = 0;
    cin >> n;

	// pair.first = start_time
	// pair.second = finish time
    pair<int, int> ar[n];

	// scan start and finish time
    for(int i = 0; i < n; ++i)
        cin >> ar[i].first;
    for(int i = 0; i < n; ++i)
        cin >> ar[i].second;

	// sort by start time. If start times are equal sort by finish times
	// though you can skip the later part without lose of correctness
    sort(ar, ar + n, [](pair<int, int> x, pair<int, int> y){
        if(x.first != y.first)
            return x.first < y.first;
        return x.second < y.second;
    });

	// base case
    if(n == 1) {
        cout << 1 << endl;
        return;
    }


    for(int i = 1; i < n; ++i) {
		// if the activities do not overlap select both the activities
		// increment the count and set last_picked to index of the current
        if(ar[i].first >= ar[last_picked].second) {
            res += 1;
            last_picked = i;
        }

		// else set last_picked to index of the activity with the least finish time.
        else
            last_picked = (ar[last_picked].second < ar[i].second ? last_picked : i);
    }
    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}

