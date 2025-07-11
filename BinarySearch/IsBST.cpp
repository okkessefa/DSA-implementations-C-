#include <iostream>
#include <climits>

// Define the structure of a Node in the Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new node with a given value
Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}



// Recursive function to check whether the tree is a BST
// The node's value must lie strictly between minValue and maxValue
bool IsBstUtil(Node* root, int minValue, int maxValue) {
    if (root == NULL) return true; // An empty subtree is always valid

    // Check current node validity and recursively check left and right subtrees
    if (
        root->data > minValue 
        && root->data < maxValue 
        && IsBstUtil(root->left, minValue, root->data) 
        && IsBstUtil(root->right, root->data, maxValue)
    ) {
        return true;
    }
    return false; // If any node violates the condition, return false
}

// Wrapper function with default min/max bounds
bool IsBinarySearchTree(Node* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

// Driver code to test IsBstUtil
int main() {
    /*
        Construct the following BST:
                7
               / \
              4   9
             / \
            1   6
    */
    Node* root = GetNewNode(7);
    root->left = GetNewNode(4);
    root->right = GetNewNode(9);
    root->left->left = GetNewNode(1);
    root->left->right = GetNewNode(8);

    if (IsBinarySearchTree(root))
        std::cout << "This tree is a valid Binary Search Tree." << std::endl;
    else
        std::cout << "This tree is NOT a Binary Search Tree." << std::endl;

    return 0;
}
