/*
  A sum tree is that in which every node is replace by the sum of all the nodes in subtress rooted at it's children. The sum of an
  empty sub-tree(the root of which is null) is assumed to be zero.
*/

int toSumTreeUtil(Node *node) {
    if(!node)
        return 0;
    
    int temp = node -> data;
    node -> data = toSumTreeUtil(node -> left) + toSumTreeUtil(node -> right);
    
    return temp + node -> data;
}

void toSumTree(Node *node) {
    toSumTreeUtil(node);
}
