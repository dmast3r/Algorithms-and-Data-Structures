/* Print Spiral Level Order Traversal:
 *
 *                                  1
 *                                /   \
 *                               2     3
 *                              / \   / \
 *                             4   5 6   7
 *
 *  Should be printed as 1 2 3 7 6 5 4
 */

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

void printNodeAtLevel(Node *root, int level, bool invert_print_order) {
    if(root == nullptr)
        return;
    if(level == 1)
        cout << root -> data << " ";

    if(invert_print_order) {
        printNodeAtLevel(root->right, level - 1, invert_print_order);
        printNodeAtLevel(root->left, level - 1, invert_print_order);
    }
    else {
        printNodeAtLevel(root->left, level - 1, invert_print_order);
        printNodeAtLevel(root->right, level - 1, invert_print_order);
    }

}

void printSpiral(Node* node) {
    if(node == nullptr)
        return;
    int height = findHeight(node);
    bool invert_print_order = false;
    cout << node -> data << " ";

    for(int level = 2; level <= height; ++level) {
        printNodeAtLevel(node, level, invert_print_order);
        invert_print_order = !invert_print_order;
    }
}



