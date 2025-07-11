#include <iostream>
#include <climits>

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
};
// Write code to:
Node* GetNewNodes(int data);

// Function to check if a binary tree is a BST  
bool IsBSTutil(Node* root, int minValue, int maxValue);

// Wrapper function with default min/max bounds
bool CheckBinarySearchTree(Node* root);

int main(){
    Node* root = GetNewNodes(8);
    root->left = GetNewNodes(4);
    root->right = GetNewNodes(10);
    root->left->left = GetNewNodes(2);
    root->left->right = GetNewNodes(9);
    root->right->right = GetNewNodes(20);

    if(CheckBinarySearchTree(root)){
        std::cout<< "This tree is valid Binary Search Tree."<<std::endl;
    }else{
        std::cout<< "This tree is not valid binary Search Tree."<<std::endl;
    }

    return 0;
}



// 3. Output whether it's a valid BST.


Node* GetNewNodes(int data){
    Node* newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}


// Function to check if a binary tree is a BST  
bool IsBSTutil(Node* root, int minValue, int maxValue){
    if(root == NULL) return true;
    if
    (
        root->data > minValue
        && root->data < maxValue
        && IsBSTutil(root->left, minValue , root->data)
        && IsBSTutil(root->right, root->data, maxValue)
    ){
        return true;
    }
    return false;
}

// Wrapper function with default min/max bounds
bool CheckBinarySearchTree(Node* root){
    return IsBSTutil(root, INT_MIN, INT_MAX);
}


/*
        8
       / \
      4   10
     / \    \
    2   6    20

Call: IsBSTUtil(8, -∞, ∞) → 8 ∈ (-∞, ∞) → ✅  
├─ Call: IsBSTUtil(4, -∞, 8) → 4 ∈ (-∞, 8) → ✅  
│  ├─ Call: IsBSTUtil(2, -∞, 4) → 2 ∈ (-∞, 4) → ✅  
│  │  ├─ Call: IsBSTUtil(NULL, -∞, 2) → ✅  
│  │  └─ Call: IsBSTUtil(NULL, 2, 4) → ✅  
│  └─ Call: IsBSTUtil(6, 4, 8) → 6 ∈ (4, 8) → ✅  
│     ├─ Call: IsBSTUtil(NULL, 4, 6) → ✅  
│     └─ Call: IsBSTUtil(NULL, 6, 8) → ✅  
└─ Call: IsBSTUtil(10, 8, ∞) → 10 ∈ (8, ∞) → ✅  
   ├─ Call: IsBSTUtil(NULL, 8, 10) → ✅  
   └─ Call: IsBSTUtil(20, 10, ∞) → 20 ∈ (10, ∞) → ✅  
      ├─ Call: IsBSTUtil(NULL, 10, 20) → ✅  
      └─ Call: IsBSTUtil(NULL, 20, ∞) → ✅  


*/