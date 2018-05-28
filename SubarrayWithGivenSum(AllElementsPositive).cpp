/* Given an array of integers and a number, find a sub-array with given sum(print starting and ending).
Array contains only positive elements and 1 <= ar[i] <= 200

Solution:
 The idea is very simple, since all elements are positive so start from 0th index and loop through next
 elements and accumulate the sum as you traverse the array. If required sum is found simply print the
 start pointer and the current index. But if sum exceeds the required sum then start renoving elements
 from starting of the subarray(that is from start+1, start+2, ..., i-1) till the current sum exceeds the
 required sum. If the entire array has been scanned and no subarray with required sum found, print -1.
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, num, sum = 0, start = 0; // start from 0.
    cin >> n >> num;
    int ar[n];
    bool flag = false;

    for(int i = 0; i < n; ++i)
        cin >> ar[i];

    for(int i = 0; i < n; ++i) {
        sum += ar[i];

        if(sum > num) {
            while(sum > num and start < i)
                sum -= ar[start++];
        }

        if(sum == num and !flag) {
            cout << start + 1 << " " << i + 1 << endl;
            flag = true;
        }
    }

    if(!flag)
        cout << -1 << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
    return 0;
}
