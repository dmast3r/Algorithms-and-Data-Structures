#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq, Node *left, Node *right) : ch(ch), freq(freq), left(left), right(right) {}
};

struct Compare {
    bool operator()(Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

void printRecursive(Node *root, string code) {
    if(root == nullptr)
        return;
    if(root -> left == nullptr and root -> right == nullptr) {
        cout << code << " ";
        return;
    }
    printRecursive(root -> left, code + "0");
    printRecursive(root -> right, code + "1");
}

void solve() {
    string str;
    cin >> str;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(int i = 0; i < str.length(); ++i) {
        int freq;
        cin >> freq;
        pq.push(new Node(str[i], freq, nullptr, nullptr));
    }


    while (pq.size() > 1) {
        Node *a = pq.top();
        pq.pop();
        Node *b = pq.top();
        pq.pop();

        pq.push(new Node('!', a -> freq + b -> freq, a, b));
    }

    printRecursive(pq.top(), "");
    cout << endl;
}

int main() {
    int test;
    cin >> test;

    while (test--)
        solve();
}

