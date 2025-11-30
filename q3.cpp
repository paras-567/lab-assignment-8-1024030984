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

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* insert(Node* node, int data) {
    if (node == NULL)
        return newNode(data);
    
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    
    return node;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* node) {
    if (node == NULL)
        return 0;
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);

    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

int minDepth(Node* node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    
    if (node->left == NULL)
        return minDepth(node->right) + 1;
    
    if (node->right == NULL)
        return minDepth(node->left) + 1;
    
    int leftDepth = minDepth(node->left);
    int rightDepth = minDepth(node->right);

    if (leftDepth < rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
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
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);
    insert(root, 45);

    cout << "Tree (In-order): ";
    printInOrder(root);

    cout << "\nMax Depth: " << maxDepth(root);
    cout << "\nMin Depth: " << minDepth(root);
    
    cout << "\n\nSearching for 60:";
    Node* found = searchRecursive(root, 60);
    if (found) cout << "\nFound 60";
    
    cout << "\nDeleting 70:";
    root = deleteNode(root, 70);
    cout << "\nTree: ";
    printInOrder(root);
    
    cout << "\n\nDeleting 30 :";
    root = deleteNode(root, 30);
    cout << "\nTree: ";
    printInOrder(root);

    Node* maxNode = findMax(root);
    if (maxNode) cout << "\nMax element: " << maxNode->data;

    return 0;
}
