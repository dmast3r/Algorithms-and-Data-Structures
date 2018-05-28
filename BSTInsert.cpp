#include <iostream>
using namespace std;

// this struct represents the tree
struct Node{
	
	Node *left, *right;
	int data;
};

void inOrder(Node *root) {
	
	if(!root)
		return;
	cout << root -> data << " ";
	inOrder(root -> left);
	inOrder(root -> right);
}

void preOrder(Node *root) {
	
	if(!root)
		return;
	preOrder(root -> left);
	cout << root -> data << " ";
	preOrder(root -> right);
}

void postOrder(Node *root) {
	
	if(!root)
		return;
	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> data << " ";
}

Node *insert(Node *root, int data) {
	
	if(!root) {
		Node *node =  new Node();
		node -> left = node -> right = nullptr;
		node -> data = data;
		return node;
	}

	if(root -> data >= data)
		root -> left = insert(root -> left, data);
	else
		root -> right = insert(root -> right, data);
	return root;
}

int main(int argc, char const *argv[]) {
	
	int ar[] = {6, 4, 5, 3, 2, 1, 9, 7, 8, 6, 11, 10, 12};
	Node *root = nullptr;
	
	for(auto i : ar)
		root = insert(root, i);

	cout << "In Order Traversal: " << endl;
	inOrder(root);

	cout << "\nPre Order Traversal: " << endl;
	preOrder(root);

	cout << "\nPost Order Traversal: " << endl;
	postOrder(root);

	return 0;
}