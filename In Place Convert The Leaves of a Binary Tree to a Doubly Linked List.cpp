/*
  Assume that the Tree and Doubly Linked List have the same structure, that is left of Tree is previous of DLL and right of Tree
  is next of DLL.
*/

// This is the helper function
void convertToDLL(Node *root, Node **head_ref, Node *&prev) {
    if(root == nullptr)
        return;
        
    if(!(root -> left) and !(root -> right)) {
        root -> left = prev;
        if(prev == nullptr)
            *head_ref = root;
        else
            prev -> right = root;
        prev = root;
    }
    
    else {
        convertToDLL(root -> left, head_ref, ref);
        convertToDLL(root -> right, head_ref, ref);
    }
}

// write your code in this function
// return pointer to the head of the list.
Node *convertToDLL(Node *root,Node **head_ref) {
    Node *prev = nullptr; 
    convertToDLL(root, head_ref, prev);
    if(prev)
        prev -> right = nullptr;
    return *head_ref;    
}
