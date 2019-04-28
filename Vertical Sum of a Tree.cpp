/*
  Print the sum of nodes in a Vertical Traversal of a Tree
  See this problem first(Vertical Traversal of a Tree)-
  
  https://github.com/dmast3r/Interview-Problems/blob/master/Vertical%20Traversal%20of%20a%20Tree.cpp
  
  Solution- We extend the idea of Vertical Traversal and take the sum of all the nodes at the same horizontal level.
*/

void preOrder(Node *root, int level, map<int, vector<int>> &mp) {
    if(root == nullptr)
        return;
        
    mp[level].push_back(root -> data);
    preOrder(root -> left, level - 1, mp);
    preOrder(root -> right, level + 1, mp);
}
void printVertical(Node *root)
{
    map<int, vector<int>> mp;
    preOrder(root, 0, mp);
    
    for(auto itr : mp) {
        cout << accumulate(itr.second.begin(), itr.second.end(), 0) << " ";
    }
}
