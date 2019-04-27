/* 
  Print the reverse level order traversal, that is for the tree
                     
                      1
                    /   \
                   2     3
                  /       \
                 4         5
                 
  Print 4 5 2 3 1

  A tree Node has data, pointer to left child
     and a pointer to right child  
  struct Node
  {
      int data;
      Node* left;
      Node* right;
  }; 
*/

Solution - Use both stack and queue, queue for level order travesal and stack for printing the output in the reverse fashion.

void reversePrint(Node *root) {
    if(root == nullptr)
        return;

    queue<Node *> q;
    stack<Node *> st;
    q.push(root);
    
    while(!q.empty()) {
        Node *top = q.front();
        st.push(top);
        q.pop();
        
        if(top -> right)
            q.push(top -> right);
        if(top -> left)
            q.push(top -> left);
    }
    
    while(!st.empty()) {
        Node * top = st.top();
        st.pop();
        cout << top -> data << " ";
    }
}
