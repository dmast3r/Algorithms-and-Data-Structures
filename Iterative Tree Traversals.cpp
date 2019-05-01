/*
  Iterative versions of Pre, In and Post Order Traversal. Assume the structure of Node as
  
  struct Node {
    int data;
    Node *left, *right;
  }
*/

// In order traversal
void inOrder(Node *root) {
    if(root == nullptr)
        return;
    
    Node *curr = root;
    stack<Node *> st;
    
    while(curr != nullptr or !st.empty()) {
        if(curr != nullptr) {
            st.push(curr);
            curr = curr -> left;
        }
        
        else {
            Node *top = st.top();
            st.pop();
            cout << top -> data << " ";
            curr = top -> right;
        }
    }
}

// post-order traversal
void postOrder(Node* root) {
  if(root == nullptr)
    return;
  
  stack<Node *> temp; 
  stack<int> output;
  temp.push(root);
  
  while(!temp.empty()) {
        Node *top = temp.top();
        temp.pop();
        output.push(top -> data);
      
        if(top -> left)
            temp.push(top -> left);
        if(top -> right)
            temp.push(top -> right);
  }
  
  while(!output.empty()) {
      cout << output.top() << " ";
      output.pop();
  }
}

void preOrder(Node* root) {
  if(root == nullptr)
    return;
    
  Node *curr = root;  
  stack<Node *> st;
  st.push(root);
  
  while(!st.empty()) {
    if(curr != nullptr) {
      cout << curr -> data << " ";
      
      if(curr -> right)
        st.push(curr -> right);
      
      curr = curr -> left;
    }
    
    else {
      curr = st.top();
      st.pop();
    }
  }
}
