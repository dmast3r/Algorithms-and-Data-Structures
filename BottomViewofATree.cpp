/* Given a function that accepts the root node of a Tree as argument, complete the function to print it's 
 * bottom view. A node of tree is in bottom view if it is the bottom most node at that horizontal node. If
 * the horizontal level of parent is l then: Horizontal Level of left-child = l-1 and that of right child
 * is l+1. If there are more than one bottom node for the same level, print the one that comes later in the
 * level order traversal.
 * 
 * Solution:
 * Do ordinary level order traversal using a Queue but also maintain a map. This map stores an integer as
 * key and a pair as value. The key represents horizontal level and pair.first represent the data at that
 * horizontal level and pair.second is a boolean value indicating if the node was at that level was 
 * visited.
 * Traverse the tree with level-order traversal and for each level store appropriate data.
*/

#include <bits/stdc++.h>
using namespace std;

// Tree node class
struct Node {
    int data;
    Node *left, *right;
};

void bottomView(Node *root) {
    // queue stores a pair, pair.first is Node * and pair.second is it's horizontal level
    queue<pair<Node *, int>> traverse_queue; 
    // for each horizontal level maintain a map as mentioned at the top.
    map<int, pair<int, bool>> level_map;

    traverse_queue.push(make_pair(root, 0)); // push the root and assume it to be at level 0
    
    // perform ordinary level order traversal.
    while(!traverse_queue.empty()) {
        pair<Node*, int> temp = traverse_queue.front();

        if(temp.first != NULL) {
            level_map[temp.second].first = temp.first->data;
            level_map[temp.second].second = true;

            traverse_queue.push(make_pair(temp.first->left, temp.second-1));
            traverse_queue.push(make_pair(temp.first->right, temp.second+1));
        }
        traverse_queue.pop();
    }

    // finally print all the nodes marked as true.
    for(auto i : level_map) {
        if(i.second.second)
            cout << i.second.first << " ";
    }
}
