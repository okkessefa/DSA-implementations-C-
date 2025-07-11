#include <iostream>

// 1. Node definition
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// 2. Function to create a new node
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 3. Insert function (recursive)
BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data); // Insert in left subtree
    } else {
        root->right = Insert(root->right, data); // Insert in right subtree
    }
    return root;
}

// 4. Search function (recursive)
bool Search(BstNode* root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data < root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

// 5. Inorder Traversal (prints values in sorted order)
void Inorder(BstNode* root) {
    if (root == NULL) return;
    Inorder(root->left);
    std::cout << root->data << " ";
    Inorder(root->right);
}

int main() {
    BstNode* root = NULL; // Empty tree

    // Insert values
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    // Print BST in order
    std::cout << "Inorder Traversal: ";
    Inorder(root); // 8 10 12 15 20 25
    std::cout << std::endl;

    // Search
    int num;
    std::cout << "Enter number to search: ";
    std::cin >> num;
    if (Search(root, num)) std::cout << "Found\n";
    else std::cout << "Not Found\n";
    return 0;
}
 
