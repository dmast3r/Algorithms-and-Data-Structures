#include<bits/stdc++.h>
using namespace std;

long long int getSum(long long int index, long long int BITree[]) {
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

long long int *constructBITree(int n, long long int ar[]) {
    long long int *tree = new long long int[n+1];

    for(int i = 0; i <= n; ++i)
        tree[i] = 0;
    for(int i = 0; i < n; ++i)
        update(i+1, ar[i], n, tree);
    return tree;
}

int main() {
    long long int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    long long int *BITree = constructBITree(n, freq);
    cout << "Sum of elements in arr[1..6] is " << getSum(6, BITree);
    return 0;
}
