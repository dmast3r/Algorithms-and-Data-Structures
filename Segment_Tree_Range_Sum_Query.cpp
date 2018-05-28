#include <bits/stdc++.h>
using namespace std;

// construct the segment Tree once it has been created. This function will be called by getSegTree.
// start and end are the starting and ending indices of the current range. pos is position inside the seg tree.
long long int constructSegTree(int start, int end, int pos, long long int ar[], long long int segTree[]) {
    if(start == end)
        segTree[pos] = ar[start];

    else {
        int mid = start + (end - start) / 2;
        segTree[pos] = constructSegTree(start, mid, 2*pos+1, ar, segTree) + constructSegTree(mid + 1, end, 2*pos+2, ar, segTree);
    }
    return segTree[pos];
}

// ar is the input array, n is the size of the array. Return the array representing the Segment Tree.
long long int *getSegTree(long long int ar[], int n) {
    // allocate memory for the segment tree, The memory to be allocated equals to 2*(2^(ceil(log2(n))) - 1
    // ceil(log2(n)) also equals to the height of the seg tree. Thus total memory allocated eqauls to 2 * 2 ^ height - 1.
    int height = int(ceil(log2(n)));
    long long int  size = 2 * (int)pow(2, height) - 1;
    long long int *segTree = new long long int[size];

    // construct the segTree once memory is allocated.
    constructSegTree(0, n-1, 0, ar, segTree);
    return segTree;
}

// qstart and qend => starting and ending indices of the query.
// start and end => starting and ending indices of the entire range, i.e. the input array.
// pos => position within the segTree.
long long int getRangeSum(int qstart, int qend, int start, int end, int pos, long long int segTree[]) {
    // if range query is totally outside the current range, nothing to return.
    if(qstart > end or qend < start)
        return 0;
    // if current range lies completly inside the query range, return the sum of the entire range, obviously this sum is stored at segTree[pos]
    if(qstart <= start and end <= qend)
        return segTree[pos];
    // else subdivide the range unless the entire sum is obtained.
    int mid = start + (end - start)/2;
    return getRangeSum(qstart, qend, start, mid, 2*pos+1, segTree) + getRangeSum(qstart, qend, mid+1, end, 2*pos+2, segTree);
}

// update the segment tree based on the difference in value
// index is index where update took place.
void updateSegTree(int start, int end, int index, int pos, long long int diff, long long int segTree[]) {
    // if index is outside the current range then move
    if(index < start or index > end)
        return;
    // else update the value
    segTree[pos] += diff;

    // subdivide if leaf node is not reached
    if(start != end) {
        int mid = start + (end - start)/2;
        updateSegTree(start, mid, index, 2*pos+1, diff, segTree);
        updateSegTree(mid + 1, end, index, 2*pos+2, diff, segTree);
    }
}

// update the value at index
void update(int index, long long int val, int n, long long int ar[], long long int segTree[]) {
    long long int diff = val - ar[index];
    ar[index] += diff;
    updateSegTree(0, n-1, index, 0, diff, segTree);
}

int main() {
    int n;
    cin >> n;
    long long int ar[n];

    for(auto &i : ar)
        cin >> i;
    long long int *segTree = getSegTree(ar, n);

    // perform range query operations here. To see the working, uncomment the three lines below, run the program and enter input 6 1 3 5 7 9 11.
    //cout << getRangeSum(1, 3, 0, n-1, 0, segTree) << endl; // output : 15
    //update(1, 10, n, ar, segTree);
    //cout << getRangeSum(1, 3, 0, n-1, 0, segTree) << endl; output : 22
}
