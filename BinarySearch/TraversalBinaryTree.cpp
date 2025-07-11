#include <iostream>
#include <queue>

// Define the node structure
struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Preorder Traversal (Root -> Left -> Right)
void Preorder(Node* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
    //F D B A C E J G I H K 
}

// Inorder Traversal (Left -> Root -> Right)
void Inorder(Node* root) {
    if (root == nullptr) return;
    Inorder(root->left);
    std::cout << root->data << " ";
    Inorder(root->right);
    // A B C D E F G H I J K
}

// Postorder Traversal (Left -> Right -> Root)
void Postorder(Node* root) {
    if (root == nullptr) return;
    Postorder(root->left);
    Postorder(root->right);
    std::cout << root->data << " ";
    //A C B E D H I G K J F 
} 
    
// Level-order Traversal (Breadth-first using queue)
void LevelOrder(Node* root) {
    if (root == nullptr) return;
    std::queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        std::cout << current->data << " ";
        
        if (current->left)  q.push(current->left);
        if (current->right) q.push(current->right);
    }
    //F D J B E G K A C I H
}

int main() {
    // Constructing the binary tree manually based on the diagrams:
    Node* root = new Node('F');
    root->left = new Node('D');
    root->right = new Node('J');
    
    root->left->left = new Node('B');
    root->left->right = new Node('E');
    root->right->left = new Node('G');
    root->right->right = new Node('K');
    
    root->left->left->left = new Node('A');
    root->left->left->right = new Node('C');
    root->right->left->right = new Node('I');
    root->right->left->right->left = new Node('H');

    std::cout << "Preorder:   "; Preorder(root);   std::cout << "\n";
    std::cout << "Inorder:    "; Inorder(root);    std::cout << "\n";
    std::cout << "Postorder:  "; Postorder(root);  std::cout << "\n";
    std::cout << "LevelOrder: "; LevelOrder(root); std::cout << "\n";

    return 0;
}
