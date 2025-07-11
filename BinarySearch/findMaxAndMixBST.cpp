// Title: Compute Height and Minimum of a Binary Search Tree
#include <iostream>
#include <algorithm> // for std::max

// Define the structure of a node in the binary search tree
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// Function to create a new node with given data
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert data into the BST (recursive insertion)
BstNode* Insert(BstNode* root, int data) {
    if (root == nullptr) root = GetNewNode(data);
    else if (data <= root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}

// Function to compute the height of the tree
int FindHeight(BstNode* root) {
    if (root == nullptr) return -1; // Convention: height of empty tree is -1
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

// Function to find the minimum value in the BST
int FindMin(BstNode* root) {
    if (root == nullptr) std::cout << "Error: Tree is empty\n"; return -1;
    if (root->left == nullptr) return root->data; // Leftmost node found
    return FindMin(root->left); // Recurse to the left subtree
}

int main() {
    BstNode* root = nullptr; // Initially the tree is empty

    // Insert elements into the BST
    root = Insert(root, 15); root = Insert(root, 10);
    root = Insert(root, 20); root = Insert(root, 8);
    root = Insert(root, 12); root = Insert(root, 17);
    root = Insert(root, 25);

    // Compute and display the height of the tree
    std::cout << "Height of the tree: " << FindHeight(root) << "\n";

    // Find and display the minimum value in the tree
    std::cout << "Minimum value in the tree: " << FindMin(root) << "\n";

    return 0;
}

/*
Educational Notes:
- Height: Number of edges on the longest path from root to any leaf.
  An empty tree has height -1, a single-node tree has height 0.

- Depth: Number of edges from the root node to a given node.
  (Not computed explicitly here, but implied by traversal depth)

- Time Complexity:
  Insert: O(log n) on average, O(n) in worst case (unbalanced tree)
  Height: O(n), must visit all nodes in worst case
  FindMin: O(h), where h is the height of the tree
*/

