/*
	Find the longest path in a Binary Tree, path is defined as the number of nodes encoutered while travelling from a source node to the 
	destination(both inclusive).

	Solution:- Apply Depth First Search, and for each node check if height_left_sub_tree + height_right_subtree > current_max, if yes update 
	current_max. return the greater of height_left_sub_tree and height_right_subtree.

	Note:- This solution can be extended to N-ary tree, instead of checking for max-height of left and right we check for all children pick the 	greatest two.

	Asked In: Microsoft, Amazon, Directi, Snapdeal, MakeMyTrip, Oracle, Oyo Rooms, PropTiger, VMWare.
*/

struct Node
 {
     int data;
     Node* left, *right;
};

int largestDistance(Node *node, int &max_distance) {
    if(node == nullptr)
        return 0;
        
    int left_distance = largestDistance(node -> left, max_distance);
    int right_distance = largestDistance(node -> right, max_distance);
    max_distance = max(max_distance, 1 + left_distance + right_distance);
    
    return 1 + max(left_distance, right_distance);
}

int diameter(Node* node) {
    if(node == nullptr or node -> left == nullptr and node -> right == nullptr)  
        return 0;
        
    int max_distance = INT_MIN;
    largestDistance(node, max_distance);
    return max_distance;
}
