#include <bits/stdc++.h>
using namespace std;

const int MAX = int(1e6);

int segTree[4 * MAX + 1], lazy[4 * MAX + 1];


// idx - index into the segment tree
// ts and te -  defines the starting and ending points for the range of segment tree
// qs and qe - defines the starting and ending points for the range of query
// diff - to be added to the seg tree
void updateRange(int idx, int ts, int te, int qs, int qe, int diff) {
	// first check for any pending updates	
	if(lazy[idx] != 0) {
		segTree[idx] += (te - ts + 1) * lazy[idx];
		
		// if not a leaf node then push the updates to children
		if(ts != te) {
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
		}

		lazy[idx] = 0; 	
	}

	// next chek if tree range falls within(partially or fully) the query range
	// if so, do the needful.
	if(qs > qe || ts > qe || te < qs)
		return;

	// fully falls
	if(qs <= ts && te <= qe) {
		segTree[idx] += (te - ts + 1) * diff;
		
		// if not a leaf node, push updates to the children
		if(ts != te) {
			lazy[idx << 1] += diff;
			lazy[idx << 1 | 1] += diff;
		}
	}

	// for partial overlap, recur
	else {	
		int mid = ts + (te - ts) / 2;
		updateRange(idx << 1, ts, mid, qs, qe, diff);
		updateRange(idx << 1 | 1, mid + 1, te, qs, qe, diff);

		segTree[idx] = segTree[idx << 1] + segTree[idx << 1 | 1];	
	}
}

int getSum(int idx, int ts, int te, int qs, int qe) {
	// first check for any pending updates	
	if(lazy[idx] != 0) {
		segTree[idx] += (te - ts + 1) * lazy[idx];
		
		// if not a leaf node then push the updates to children
		if(ts != te) {
			lazy[idx << 1] += lazy[idx];
			lazy[idx << 1 | 1] += lazy[idx];
		}

		lazy[idx] = 0; 	
	}

	// next chek if tree range falls within(partially or fully) the query range
	// if so, do the needful.
	if(qs > qe || ts > qe || te < qs)
		return 0;

	// fully falls
	if(qs <= ts && te <= qe)
		return segTree[idx];

	// partial fall;
	else {
		int mid = ts + (te - ts) / 2;
		return getSum(idx << 1, ts, mid, qs, qe) + getSum(idx << 1 | 1, mid + 1, te, qs, qe);
	}
}

void buildSegTree(int idx, int start, int end, int ar[]) {
	if(start == end) {
		segTree[idx] = ar[start];
		return;		
	}

	int mid = start + (end - start) / 2;
	buildSegTree(idx << 1, start, mid, ar);
	buildSegTree(idx << 1 | 1, mid + 1, end, ar);

	segTree[idx] = segTree[idx << 1] + segTree[idx << 1 | 1];
}

int main() {
	int ar[] = {1, 3, 5, 7, 9, 11};
	int n = 6; 

	memset(lazy, 0, sizeof lazy);
	memset(segTree, 0, sizeof segTree);	
	buildSegTree(1, 0, n - 1, ar);

	cout << getSum(1, 0, n - 1, 1, 3) << endl;
	updateRange(1, 0, n - 1, 1, 5, 10);
	cout << getSum(1, 0, n - 1, 1, 3) << endl;	
}
