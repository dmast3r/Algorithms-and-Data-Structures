/*
  Solution-
  The idea is simple - post-order traversal of an expression tree yields the postfix expression where as it's inorder traversal
  yields the infix expression. Next we exploit the property of an expression tree that leaves are always the operands. With this
  in mind and the property of post-order traversal that root is always printed last and it's right subtree just before it, 
  we can now construct the tree easliy. We create a node till with it's value being the current character in the expression and 
  then recursively construct first the right subtree and then the left subtree if the current character is an operator.
*/

// node of the tree
struct et {
    char value;
    et *left, *right;
}

et *getNewNode(char value) {
    et *new_node = new et();
    new_node -> value = value;
    new_node -> left = new_node -> right = nullptr;
    return new_node;
}

// Helper function for construction of tree
// postfix is the expression array. index is the index of the current character being scanned
et *constructTree(char postfix[], int &index) {
    // if all the characters have been scanned, return null as there is no subtree to construct any further.
    if(index < 0)
        return nullptr;
    
    // construct a node with it's value being the current character
    et *new_node = getNewNode(postfix[index--]);
    
    // if the value is not an alphabat, that is not an operand than it is an operator
    // which means it is an internal node, so construct it's right and left subtrees.
    if(!isalpha(new_node -> value)) {
        // we construct the right subtree first as right subtree is printed immediately before the root
        // and we are scanning from end of the expression to the begining(r to l)
        // so, we will encounter the right subtree first.
        new_node -> right = constructTree(postfix, index);
        new_node -> left = constructTree(postfix, index);
    }
    
    return new_node;
}

et *constructTree(char postfix[]) {
    // index is the index of the current character in the expression which is being scanned
    // we start scanning from the last character since it is where the root is located
    // we then move towards the left scanning all the chars.
    int index = strlen(postfix) - 1;
    return constructTree(postfix, index);
}
