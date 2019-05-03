/*
Given a binary tree, connect the nodes that are at same level.
Structure of the given Binary Tree node is like following.
struct Node
{
      int data;
      Node* left;
      Node* right;
      Node* nextRight;
}

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for 
each node.
       10                        10 ------> NULL
      / \                      /      \
     3   5       =>           3 ------> 5 --------> NULL
    / \     \               /  \         \
   4   1   2               4 --> 1 -----> 2 -------> NULL

  Solution - Modify the level order traversal
*/

void connect(Node *p) {
    if(p == nullptr)
        return;
    
    // this variable is for keeping the last visited node in the current level
    // if we are at a new level then this variable will be set to NULL
    // since we are about to start at level zero, set this variable to NULL
    Node *last_node = nullptr;
    queue<Node *> q;
    q.push(p);
    
    while(!q.empty()) {
        // the number of nodes at the current level
        int num_nodes = q.size();
        
        // scan all the nodes at the current level
        while(num_nodes--) {
            Node *front = q.front();
            q.pop();
            
            // if last_node of this level is NULL, meaning we have just started scanning this level
            // in such case front contains reference to the first node of this level
            // otherwise connect nextRight of the last_node to front
            if(last_node != nullptr)
                last_node -> nextRight = front;
            
            // front is now the last visited node of this level
            last_node = front;
            
            // enqueue left and right children if exist
            if(front -> left != nullptr)
                q.push(front -> left);
            if(front -> right != nullptr)
                q.push(front -> right);
        }
        
        // last_node will refer to the last_node of the just scanned level
        // make it's nextRight point to NULL and then last_node to NULL 
        last_node -> nextRight = nullptr;
        last_node = nullptr;
    }
}
