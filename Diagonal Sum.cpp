#include <bits/stdc++.h>
using namespace std;

long long int sum[100001], max_level;

struct Node{
    int data;
    Node *left,*right;
};

void addRecursive(long long int curr_level, Node *root) {
    if(root == nullptr)
        return;
    max_level = max(curr_level, max_level);
    sum[curr_level] += root -> data;
    addRecursive(curr_level, root -> right);
    addRecursive(curr_level + 1, root -> left);
}

void diagonalSum(Node* root) {
    fill(begin(sum), end(sum), 0);
    max_level = 0;
    addRecursive(0, root);

    for(int i = 0; i <= max_level; ++i)
        cout << sum[i] << " ";
}
