#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};
Node* root = NULL;

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node* r, Node* node) {
    if (root == NULL) {
        root = node;
    } else if (r->key < node->key) {
        if (r->right == NULL) r->right = node;
        else insert(r->right, node);
    } else if (r->key > node->key) {
        if (r->left == NULL) r->left = node;
        else insert(r->left, node);
    }
}

void postorder(Node* r) {
    if (r->left != NULL) postorder(r->left);
    if (r->right != NULL) postorder(r->right);
    cout << r->key << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int key;
    while (cin >> key) 
        insert(root, createNode(key));
    postorder(root);
    return 0;
}