/*
  struct Node {
    int data;
    Node *next;
  }
*/

Node *removeDuplicates(Node *root) {
    if(root == nullptr or root -> next == nullptr)
        return root;
        
    Node *left, *right = root;
    
    while(right !=  nullptr) {
        left = right;
        right = right -> next;
        
        while(right != nullptr and left -> data == right -> data) {
            Node *temp = right -> next;
            delete right;
            right = left -> next = temp;
        }
    }
    
    return root;
}
