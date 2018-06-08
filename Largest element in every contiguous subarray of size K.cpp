/*
  Given an array and integer K, find the largest element in every contiguous subarray of size K.
  Solution :- Question can be solved using sliding window, use a dequeue to maintain the window, remove every element from
  the front and the back that is either out of the Window or is smaller than or equal to the current element. Then finally 
  push the current element on the rear side of the queue, the maximum element can then be obtained by printing the element at the
  front of the queue.
*/

#include<bits/stdc++.h>
using namespace std;

// n is the size of the input ar, ar is the input array itself and k is the size of the window.
void printMaxInEveryWindowOfSizeK(const int n, const int ar[], int k = 1) {
    deque<int> dq;
    for(int i = 0; i < n; ++i) {
        while (!dq.empty() and (ar[dq.front()] <= ar[i] or dq.front() <= i - k))
            dq.pop_front();
        while (!dq.empty() and (ar[dq.back()] <= ar[i] or dq.back() <= i - k))
            dq.pop_back();
        dq.push_back(i);

        // start printing only when the pointer has crossed the k-1th(in 0 based indexing) mark.
        if(i >= k - 1)
            cout << ar[dq.front()] << " ";
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int ar[n];
    
    for(auto &i : ar)
        cin >> i;

    printMaxInEveryWindowOfSizeK(n, ar, k);
    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
