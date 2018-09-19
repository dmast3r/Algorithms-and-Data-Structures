/*
	Given a Binary Tree, print the diagnol traversal of the binary tree.
	For example:-
	for the Binary Tree

											8
										   / \
										  3   10
										 / \   \
										1   6   14
										   / \
										  4   7

	Diagonal Traversal will be:-
	8 10 14 3 6 7 13 1 4

	Asked in: Amazon

	------------------------------------------------------------------------------------------------------------------------------------------------

	Solution:-
	
	1. If the root node is null, then return.
	2. Push the root node into queue.
	3. Repeat steps 4-6 while the queue is not empty.
		4. Save the value of the front element(node) of the queue in a variable say current_node.
		5. Pop the front element from the queue.
		6. Recursively follow steps 7-10 while the value of current_node is not null-:
			7. If the value of current_node is null, then return(terminate the recursion).
			8. Print the value of the node.
			9. If the left child is not null, then push it into the queue.
			10. Update the value of current_node equal to the right child of the current node, and make a recursive call.   

	Time Complexity: O(N)
	Space Complexity: O(N)
*/

struct Node {
    int data;
    Node* left, * right;
};

void solveRecurUtil(Node *node, queue<Node *> &q) {
    if(node == nullptr)
        return;
    
    cout << node -> data << " ";
    if(node -> left != nullptr)
        q.push(node -> left);
        
    solveRecurUtil(node -> right, q);    
}

void solveRecur(Node *node) {
    queue<Node *> q;
    q.push(node);
    
    while(!q.empty()) {
        Node *top = q.front();
        q.pop();
        
        solveRecurUtil(top, q);
    }
}

void diagonalPrint(Node *root) {
    if(root == nullptr)
        return;
    solveRecur(root); 
}
