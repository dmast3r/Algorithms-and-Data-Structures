int nodes[100001], max_level;

struct NewNode {
    Node *root;
    int level;

    NewNode(Node *root, int level) : root(root), level(level) {}
};

void leftView(struct Node *root) {
    if(root == nullptr)
        return;

    queue<NewNode> q;
    fill(begin(nodes), end(nodes), -1);
    max_level = 0;
    q.push(NewNode(root, 0));

    while(!q.empty()) {
        NewNode newNode = q.front();
        max_level = max(max_level, newNode.level);
        if(nodes[newNode.level] == -1) 
            nodes[newNode.level] = newNode.root -> data;

        if(newNode.root -> left != nullptr)
            q.push(NewNode(newNode.root -> left, newNode.level+1));
        if(newNode.root -> right != nullptr)
            q.push(NewNode(newNode.root -> right, newNode.level+1));
        q.pop();
    }

    for(int i = 0; i <= max_level; ++i)
        cout << nodes[i] << " ";
}
