bool isBST(Node *root, int min_range, int max_range) {
    if(root == nullptr)
        return true;
    bool flag = (min_range < root -> data and root -> data < max_range);
    return (flag and isBST(root -> left, min_range, root -> data) and isBST(root -> right, root -> data, max_range));
}

bool isBST(Node* root) {
    return isBST(root, -1000000001, 1000000001);
}
