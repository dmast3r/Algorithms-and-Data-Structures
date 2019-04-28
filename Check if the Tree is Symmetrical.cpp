/*
Given a Binary Tree of size N, your task is to complete the function isSymettric(), that check whether a binary is Symmetric or not, i.e. the binary tree is Mirror image of itself or not.
For example:
The following binary tree is symmetric:

        1
      /   \
    2       2
  /   \   /   \
 3     4 4     3


But the following is not:

       1
     /   \
    2      2
     \      \
      3      3

*/

/*
  Solution - 
*/

// The helper function
bool isSymmetric(Node *a, Node *b) {
    if((a == nullptr and b != nullptr) or (a != nullptr and b == nullptr))
        return false;
    if(a == nullptr and b == nullptr)
        return true;
        
    return a -> key == b -> key and isSymmetric(a -> left, b -> right) and isSymmetric(a -> right, b -> left);
}

bool isSymmetric(struct Node* root) {
    // empty tree is trivially symmetrical
    if(root == nullptr)
        return true;
        
    return isSymmetric(root -> left, root -> right);    
}
