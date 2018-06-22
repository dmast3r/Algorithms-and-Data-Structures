struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct NewNode {
    Node *root;
    int dist;

    NewNode(Node *root, int dist) : root(root), dist(dist) {}
};

void topView(struct Node *root) {
    if(root == nullptr)
        return;

    int max_dist = -1, min_dist = 0;
    queue<NewNode> q;
    q.push(NewNode(root, 0));

    while (!q.empty()) {
        NewNode newNode = q.front();

        if(newNode.dist > max_dist or newNode.dist < min_dist) {
            cout << newNode.root -> data << " ";
            max_dist = max(max_dist, newNode.dist);
            min_dist = min(min_dist, newNode.dist);

            if(newNode.root -> left != nullptr)
                q.push(NewNode(newNode.root->left, newNode.dist-1));
            if(newNode.root -> right != nullptr)
                q.push(NewNode(newNode.root->right, newNode.dist+1));
        }
    }
}
