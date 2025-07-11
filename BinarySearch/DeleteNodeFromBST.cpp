#include <iostream>
using namespace std;

// Define structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Helper function to create a new node
Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Helper function to find minimum value node in a subtree (used in Case 3)
Node* FindMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node from BST
Node* Delete(Node* root, int data) {
    if (root == NULL) return root;

    // Traverse to the correct node
    if (data < root->data) {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        // Found the node to delete

        // Case 1: No child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }

        // Case 2: One child (only right child)
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }

        // Case 2: One child (only left child)
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        // Case 3: Two children
        else {
            Node* temp = FindMin(root->right);  // You can also use FindMax(root->left)
            root->data = temp->data;  // Copy the in-order successor
            root->right = Delete(root->right, temp->data);  // Delete the duplicate
        }
    }

    return root;
}

// Inorder traversal to check correctness
void Inorder(Node* root) {
    if (root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = GetNewNode(12);
    root->left = GetNewNode(5);
    root->right = GetNewNode(17);
    root->left->left = GetNewNode(3);
    root->left->right = GetNewNode(7);
    root->left->left->left = GetNewNode(1);
    root->left->right->right = GetNewNode(9);
    root->left->right->right->left = GetNewNode(8);
    root->left->right->right->right = GetNewNode(11);
    root->right->left = GetNewNode(13);
    root->right->left->right = GetNewNode(14);
    root->right->right = GetNewNode(20);
    root->right->right->left = GetNewNode(18);

    cout << "Before Deletion (Inorder): ";
    Inorder(root); cout << endl;

    root = Delete(root, 17);  // Deleting node with 2 children

    cout << "After Deletion (Inorder): ";
    Inorder(root); cout << endl;

    return 0;
}
