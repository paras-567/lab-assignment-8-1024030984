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

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    cout << "Pre-order: ";
    printPreOrder(root);

    cout << "\nIn-order: ";
    printInOrder(root);

    cout << "\nPost-order: ";
    printPostOrder(root);

    return 0;
}