/*
  Create a vector representation of a binary tree, so that it can be written to and read back from a file.
  
  The idea is to do a preorder traversal where null nodes are marked with some integer, here I have used -1, which is outside the 
  range of the data of the nodes.
*/

// Serialize the tree rooted at root in A.
void serialize(Node *root,vector<int> &A) {
    if(root == nullptr) {
        A.push_back(-1);
        return;
    }
    
    A.push_back(root -> data);
    serialize(root -> left, A);
    serialize(root -> right, A);
}

// helper function for de-serialization
Node *deSerialize(vector<int> &A, int &index) {
    if(index == A.size() or A[index] == -1) {
        ++index;
        return nullptr;
    }
        
    Node *new_node = new Node();
    
    new_node -> data = A[index++];
    new_node -> left = deSerialize(A, index);
    new_node -> right = deSerialize(A, index);
    
    return new_node;
}

// this function deserializesthe serialized vector A
Node *deSerialize(vector<int> &A) {
   int index = 0;
   return deSerialize(A, index);
}
