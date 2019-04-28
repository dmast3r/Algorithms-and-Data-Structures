/*
  Print the Vertical Traversal of a Tree.
  Example-
  Testcase1:
         1
       /     \
    2         3
              /
         5
As it is evident from the above diagram that during vertical traversal 2 will come first, then 1 and  5, and then 3. So output is 2 1 5 3
Testcase2:
         1
       /     \
     3       2
As it is evident from the above diagram that during vertical traversal 3 will come first, then 1 and then 2. So output is 3 1 2

Note - The output may differ whether the question asker wants traversal to be preorder or level order. Here we want preorder
traversal.

Solution - Use the same concept of Horizontal Distance as in Top and Bottom view of a Binary Tree. Maintain a map that maps 
horizontal distances to a vector of nodes on that distance. Update the map while performing a preorder traversal.
*/

void preOrder(Node *root, int level, map<int, vector<int>> &mp) {
    if(root == nullptr)
        return;
        
    mp[level].push_back(root -> data);
    preOrder(root -> left, level - 1, mp);
    preOrder(root -> right, level + 1, mp);
}

void verticalOrder(Node *root) {
    map<int, vector<int>> mp;
    preOrder(root, 0, mp);
    
    for(auto itr : mp) {
        for(auto data : itr.second)
            cout << data << " ";
    }
}
