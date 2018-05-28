#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

int findHeight(Node *node) {
    if(node == nullptr)
        return 0;
    return max(findHeight(node -> left), findHeight(node -> right)) + 1;
}

void printNodeAtLevel(Node *root, int level) {
    if(root == nullptr)
        return;
    if(level == 1)
        cout << root -> data << " ";
    printNodeAtLevel(root -> left, level - 1);
    printNodeAtLevel(root -> right, level - 1);

}

void levelOrder(Node* node) {
    if(node == nullptr)
        return;
    int height = findHeight(node);

    for(int level = 1; level <= height; ++level)
        printNodeAtLevel(node, level);
}
