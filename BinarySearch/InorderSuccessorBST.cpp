#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node with given data
Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new value into the BST
Node* Insert(Node* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

// Function to find a node with a given value
Node* Find(Node* root, int data) {
    if (root == NULL) return NULL;
    else if (data == root->data) return root;
    else if (data < root->data) return Find(root->left, data);
    else return Find(root->right, data);
}

// Function to find the node with minimum value in a subtree
Node* FindMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find the inorder successor of a given node
Node* GetSuccessor(Node* root, int data) {
    // Step 1: Search for the node with value `data`
    Node* current = Find(root, data);
    if (current == NULL) return NULL;

    // Case 1: Node has a right subtree
    if (current->right != NULL) {
        return FindMin(current->right);
    }

    // Case 2: No right subtree – move upward to find the successor
    Node* successor = NULL;
    Node* ancestor = root;

    while (ancestor != current) {
        if (current->data < ancestor->data) {
            // So far, this is the deepest node for which current is in left subtree
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// Main function to demonstrate the usage
int main() {
    Node* root = NULL;

    // Build the tree
    // Tree:         15
    //             /    \
    //           10      20
    //          /  \    /  \
    //         8   12  17  25
    //        /   /      \    \
    //       6   11      16   27

    int values[] = {15, 10, 20, 8, 12, 17, 25, 6, 11, 16, 27};
    for (int i = 0; i < 11; ++i) {
        root = Insert(root, values[i]);
    }

    // Test: Find successor of a node
    int testValue = 12;
    Node* successor = GetSuccessor(root, testValue);

    if (successor != NULL) {
        cout << "Inorder successor of " << testValue << " is " << successor->data << endl;
    }
    else {
        cout << "No inorder successor exists for " << testValue << endl;
    }

    return 0;
}
