/*
	Following is an example of foldable binary tree - 
													1
												   / \
												  2   3
												  \   /
												   4 5
	
	Following is an example of a binary tree which is not foldable
													1
												   / \
												  2   NULL
	
	Solution :-
	First if the tree is empty(root == NULL) the tree is trivially foldable. If not, take the mirror image of either of the left or right subtree 
	and compare it with the other subtree. Both of them should have the same structure, they will have the same structure if either both of them 
	are NULL or both of them are non-NULL and their left-children and right-children have the same structure. Remember to re-mirror the subtree 
	you mirrored to get back the original tree. This is neccessary because the checker code of the Online Judge may need original tree to 
	verify the answer.     	  			 	
*/

struct node {
	node *left, *right;
	int data;
};

bool isStructureSame(node *a, node *b) {
    if(a == nullptr and b == nullptr)
        return true;
    if(a != nullptr and b != nullptr and isStructureSame(a->left,b->left) and
    isStructureSame(a->right, b->right))
        return true;
    return false;
}

bool isFoldable(struct node *root){
    if(root==nullptr)
        return true;
    mirror(root->left);
    bool res = isStructureSame(root->left, root->right);
    mirror(root->left);
    return res;
}
