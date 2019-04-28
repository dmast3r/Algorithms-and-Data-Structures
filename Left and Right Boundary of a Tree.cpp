/*
  The tree structure is given as-
  
  Node {
    int data;
    Node *left, *right;
  }
*/

// print left boundary only
void printLeftBoundary(Node *root) {
  if(root == nullptr)
    return;
  
  cout << root -> data << " ";
  
  if(root -> left)
    printLeftBoundary(root -> left);
  else
    printLeftBoundary(root -> right);
}



// print right boundary only
void printRightBoundary(Node *root) {
  if(root == nullptr)
    return;
  
  cout << root -> data << " ";
  
  if(root -> right)
    printRightBoundary(root -> right);
  else
    printRightBoundary(root -> left);
}

// print both the left as well as the right boundary
void printLeftRightBoundary(Node *root) {
  if(root == nullptr)
    return;
  
  cout << root -> data << " ";
  
  printLeftBoundary(root -> left);
  printRightBoundary(root -> right);
}
