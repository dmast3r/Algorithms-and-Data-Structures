/*
  Given an expression tree, where internal nodes are operantors and leaves are operands. Evaluate the value of the expression 
  represented by the tree.
  
  Return zero if a node is null and return the value of the node if it is a leaf. If it is not a leaf or null then it is an internal
  node, which is represnting some operator. Apply this operator in this fashion - 
  (fetch value from the left subtree) op (fetch value from the right subtree)
*/

int getValue(int a, int b, char op) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

int evalTree(node* root) {
    if(root == nullptr)
        return 0;
        
    if(!root -> left and !root -> right)
        return stoi(root -> data);
        
    int val_from_left = evalTree(root -> left);
    int val_from_right = evalTree(root -> right);
    
    return getValue(val_from_left, val_from_right, (root -> data)[0]);
}
