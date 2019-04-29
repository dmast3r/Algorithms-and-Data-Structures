/*
  Two trees are said to be isomorphic if we can obtain the other tree by applying any number of 'swap left and right children' on
  the nodes of one tree.

  Solution-
  To check if trees are isomorphic-
  1. The roots have same value. Which means either both of them are empty or if one of them is non empty then the other should also
  be non empty and the roots must have the same value.
  2. Either (the left subtree of first equal to the left subtree of the second and the right subtree of the first equal to the right
  subtree of the second) or (the left subtree of the first equal to the right subtree of the second and the right subtree of the 
  first equal to the left subtree of the second).
*/

// Functions that returns boolean value indicating if trees are isomorphic.
bool isIsomorphic(Node *root1,Node *root2) {
    if(root1 == root2)
        return true;
        
    return (root1 and root2) and (root1 -> data == root2 -> data) and ((isIsomorphic(root1 -> left, root2 -> left) and 
    isIsomorphic(root1 -> right, root2 -> right)) or (isIsomorphic(root1 -> left, root2 -> right) and 
    isIsomorphic(root1 -> right, root2 -> left))); 
}
