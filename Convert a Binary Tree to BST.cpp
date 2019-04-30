/*
  Convert a given Binary Tree to BST such that the structure of the tree is maintained(i.e. number of children for every node should
  remain same).

  Solution- The idea is based on exploiting the fact that the in-order traversal of a BST produces a sorted array. Hence we store
  the value of the nodes of the tree in some a temporary array by any traversal and then sort this array. Finally we perform 
  in-order traversal again but instead of printing the data of nodes we copy data from array to the nodes.
*/

// this function extracts data from the tree into the vector
void Inorder(Node *root, vector<int> &in_order) {
    if(root == nullptr)
        return;
        
    Inorder(root -> left, in_order);
    in_order.push_back(root -> data);
    Inorder(root -> right, in_order);
}

// copy data from the vector to nodes.
void Inorder(Node *root, vector<int> &in_order, int &index) {
    if(root == nullptr)
        return;
        
    Inorder(root -> left, in_order, index);
    root -> data = in_order[index++];
    Inorder(root -> right, in_order, index);
}

// function that converts BT to BST
Node *binaryTreeToBST (Node *root) {
    vector<int> in_order;
    int index = 0;
    Inorder(root, in_order);
    sort(in_order.begin(), in_order.end());
    Inorder(root, in_order, index);
    return root;
}
