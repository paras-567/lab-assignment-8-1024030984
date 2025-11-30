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

bool isBSTUtil(Node* node, Node* minN, Node* maxN) {
    if(node==NULL)
        return true;

    if(minN!=NULL&&node->data<=minN->data)
        return false;

    if(maxN!=NULL&&node->data>=maxN->data)
        return false;

    if(!isBSTUtil(node->left, minN, node))
        return false;

    if(!isBSTUtil(node->right, node, maxN))
        return false;

    return true;
}

bool isBST(Node* node) {
    return isBSTUtil(node, NULL, NULL);
}

int main() {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    cout<<"BST Check 1: ";
    if(isBST(root))cout<<"Is a BST\n";
    else cout<<"Is NOT a BST\n";
    
    Node* invalidRoot = newNode(3);
    invalidRoot->left = newNode(2);
    invalidRoot->right = newNode(5);
    invalidRoot->left->right = newNode(10); 
    
    cout<<"BST Check 2: ";
    if(isBST(invalidRoot))cout<<"Is a BST\n";
    else cout<<"Is NOT a BST\n";

    return 0;
}