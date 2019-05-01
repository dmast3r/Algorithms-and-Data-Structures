/*
  Given the post order traversal of a BST, create that tree and return reference to it's root. This file deals with the recursive
  solution. 
*/

struct Node {
	int data;
	Node *left, *right;
}

// A utility function to get a new node.
Node *getNewNode(int data) {
    Node *new_node = new Node();
    new_node -> data = data;
    new_node -> left = new_node -> right = nullptr;
    
    return new_node;
}

// Helper function for creating tree.
// post is the post order array, index is the index of the current integer being scanned
// min and max forms the range in which every nodes in the subtree must lie.
Node *constructTree(int post[], int &index, int min, int max) {
    // if there is no more integer to scan or if the integer violates the property of BST
    // then return null
    if(index < 0 or post[index] > max or post[index] < min)
        return nullptr;
    
    // construct a new node and it's left and right sub-trees by setting the range appropriately
    Node *new_node = getNewNode(post[index--]);
    new_node -> right = constructTree(post, index, new_node -> data, max);
    new_node -> left  = constructTree(post, index, min, new_node -> data);
    
    return new_node;
}

Node *constructTree (int post[], int size) {
    int index = size - 1;
    return constructTree(post, index, INT_MIN, INT_MAX);
}
