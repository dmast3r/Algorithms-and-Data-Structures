/*                                              Inversion Count in an Array
 * 
 *  Find the Inversion Count in an Array - That is given an find the minimum number of steps required to sort that array
 *  If for a number at the ith index say ar[i], there are k numbers greater than it and to the left of it then inversion count
 *  for that number will be k, we have to find the sum of inversion count fot all such 0 <= i < n.
 *  
 *  Solution :-
 *  First do coordinate compression and find the position of each element in non increasing order, ie, the smallest element
 *  will be at position n, second smallest will be at n-1 and so on...
 *  Now start iterating from the left, i.e. for i = 0 to N - 1 and use Binary Indexed Tree(Fenwick Tree) to find all the
 *  elements larger than current elements that have been encountered so far, and add this to the result, also update the
 *  result for the current element.
*/


#include<bits/stdc++.h>
using namespace std;

long long int getSum(long long int index, const long long int BITree[]) {
    long long int sum = 0;

    while(index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void update(long long int index, long long int val, int n, long long int BITTree[]) {
    while(index <= n) {
        BITTree[index] += val;
        index += index & (-index);
    }
}

long long int *constructBITree(int n) {
    auto *tree = new long long int[n+1];

    for(int i = 0; i <= n; ++i)
        tree[i] = 0;
    return tree;
}


void solve() {
    int n, res = 0;
    cin >> n;
    int ar[n], ars[n], pos[n];

    for(int i = 0; i < n; ++i) {
        cin >> ar[i];
        ars[i] = ar[i];
    }
    sort(ars, ars + n);

    // do co-ordinate compression here
    for(int i = 0; i < n; ++i) {
        int p = lower_bound(ars, ars + n, ar[i]) - ars;
        pos[i] = n - p;
    }


    long long int *bi_tree = constructBITree(n);
    for(int i = 0; i < n; ++i) {
        res += getSum(pos[i] - 1, bi_tree);
        update(pos[i], 1, n, bi_tree);
    }

    cout << res << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
