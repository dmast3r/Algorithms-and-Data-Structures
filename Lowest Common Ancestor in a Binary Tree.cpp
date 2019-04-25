/**
 * Definition for a node.
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node(int val): val(val), left(NULL), right(NULL) {}
 * };
 */

/*
  Problem - The lowest common ancestor (LCA) for 2 nodes, N1 and N2, is defined as the the lowest node in the tree, 
  where N1 and N2 are both its decendants.

  Solution - Consider the cases-
  1. Root is either of the two nodes, ie either N1 or N2 is the root, then root is the LCA.
  2. If case first does not hold we can check for any particular node that if left and right subtrees contains atleast one of the 
  two nodes. If both of the subtrees contais one of the two nodes, then the current node is the LCA.
  3. The final case will be when only one of the two subtrees contains both the nodes. In such a case, we recursively apply the 
  above cases on that subtree.
*/

// Returns the node that is the lowest common ancestor of first and second.
Node* findLowestCommonAncestor(Node* root, Node* first, Node* second) {
	if(root == nullptr)
    return nullptr;
  
  if(root -> val == first -> val or root -> val == second -> val)
    return root;
  
  Node *left_lca = findLowestCommonAncestor(root -> left, first, second);
  Node *right_lca = findLowestCommonAncestor(root -> right, first, second);
  
  if(left_lca and right_lca)
    return root;
  
  return (left_lca ? left_lca : right_lca);
}
