/*
  Question - Given a Tree, print it's boundary in this manner-
  First the nodes on the left boundary in top down manner, then print all the leaves and finally print the nodes on the right 
  boundary in bottom up manner.

  Solution- This question involves printing left boundary of a tree, it's leaves and it's right boundary and in this manner. We
  just have to modify the usual way to print them. We need to take care of the following-
  
  1. Avoid redundant prints of leaf nodes when printing the left and the right boundaries.
  2. Avoid redundant prints of nodes that are both on the left as well as the right boundary.
  3. Print the right boundary in bottom up fashion instead of top down.
  4. Avoid redundant print of the root node if it is a leaf.
*/

void printLeftBoundary(Node *root) {
    if(root == nullptr)
        return;
           
    // the below two checks, i.e. if and else if will print a node which is on the left boundary if and only if
    // it is not a leaf
    if(root -> left) {
        // printing before recursion - top down manner
        cout << root -> data << " ";
        printLeftBoundary(root -> left);
    }
    else if(root -> right) {
        cout << root -> data << " ";
        printLeftBoundary(root -> right);
    }
}

void printRightBoundary(Node *root) {
    if(root == nullptr)
        return;
    
    // the below two checks, i.e. if and else if will print a node which is on the right boundary if and only if
    // it is not a leaf    
    if(root -> right) {
        printRightBoundary(root -> right);
        // printing after recursion - bottom up manner
        cout << root -> data << " ";
    }
    else if(root -> left) {
        printRightBoundary(root -> left);
        cout << root -> data << " ";
    }
}

void printLeaves(Node *root) {
    if(root == nullptr)
        return;
        
    if(root -> left == nullptr and root -> right == nullptr)
        cout << root -> data << " ";
    
    printLeaves(root -> left);
    printLeaves(root -> right);
}

void printBoundary(Node *root) {
     if(root) {
         cout << root -> data << " ";
        
        /*
          calling printLeftBoundary with root -> left and printRightBoundary with root -> right will ensure that
          no redundant print of nodes which lie on both the boundaries.
        */
        
        printLeftBoundary(root -> left);
        
        // calling printLeaves ensures no redundant print of the root node when it is a leaf
        printLeaves(root -> left);
        printLeaves(root -> right);
        
        printRightBoundary(root -> right);
     }
}
