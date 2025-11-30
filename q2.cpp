#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printPreOrder(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printInOrder(Node* node) {
    if (node == NULL)
        return;
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

void printPostOrder(Node* node) {
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << " ";
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return searchRecursive(root->right, key);
    return searchRecursive(root->left, key);
}

Node* searchIterative(Node* root, int key) {
    while (root != NULL && root->data != key) {
        if (root->data < key)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

Node* findSuccessor(Node* root, Node* n) {
    if (n->right != NULL)
        return findMin(n->right);
    Node* succ = NULL;
    while (root != NULL) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

Node* findPredecessor(Node* root, Node* n) {
    if (n->left != NULL)
        return findMax(n->left);
    Node* pre = NULL;
    while (root != NULL) {
        if (n->data > root->data) {
            pre = root;
            root = root->right;
        } else if (n->data < root->data)
            root = root->left;
        else
            break;
    }
    return pre;
}

int main() {
    Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    cout << "Pre-order: ";
    printPreOrder(root);

    cout << "\nIn-order: ";
    printInOrder(root);

    cout << "\nPost-order: ";
    printPostOrder(root);

    Node* found = searchRecursive(root, 60);
    if (found) cout << "\nFound 60 (Recursive)";
    
    found = searchIterative(root, 60);
    if (found) cout << "\nFound 60 (Iterative)";

    Node* maxNode = findMax(root);
    if (maxNode) cout << "\nMax: " << maxNode->data;

    Node* minNode = findMin(root);
    if (minNode) cout << "\nMin: " << minNode->data;

    Node* target = root->left->right; 
    Node* succ = findSuccessor(root, target);
    if (succ) cout << "\nSuccessor of 40: " << succ->data;

    Node* pre = findPredecessor(root, target);
    if (pre) cout << "\nPredecessor of 40: " << pre->data;

    return 0;
}
