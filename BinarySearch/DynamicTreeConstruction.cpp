
// Write code to:

// Insert values from an array into a BST using an Insert() function.

// Then call TraversalSearchBST() to check if the constructed tree is a valid BST.

// 📥 Sample input array:

// int values[] = {15, 7, 25, 3, 12, 17, 30};
// Implement Node* Insert(Node* root, int data):

// Recursively insert the value in the correct BST position.

// In main(), iterate over the array to build the BST.

// Then call TraversalSearchBST(root).
#include <iostream>
#include <stack>
#include <vector> 
#include <cmath>

//Creating a structure for mew node
struct Node{
    int data;
    Node* left;
    Node* right;

    //No need to seperated get new node function, use this combined version
    Node(int value) : data(value), left(nullptr), right(nullptr) {}

};
//Function to insert new node to tree 
Node* InsertNode(Node* root, int data){
    if(root == nullptr) 
    {
        Node* newnode =  new Node(data);
        return newnode;
    }
    //Prevent the dublicated variable implamentation
    // if(root->data == data)
    // {
    //     std::cout<<"This is invalid implamentation and this tree is not valid"<<std::endl;
    //     return root;
    // }

    if(data < root->data)
    {
        root->left = InsertNode(root->left, data); 
    }
    else
    {
        root->right = InsertNode(root->right, data); 
    }   
    return root;
}

int FindHeightTree(Node* root) {
    if (root == nullptr) return -1; // Convention: height of empty tree is -1
    int leftHeight = FindHeightTree(root->left);
    int rightHeight = FindHeightTree(root->right);
    return std::max(leftHeight, rightHeight) + 1;
}

//Function to traverse all node starting from left then returning to right side using stack implamentation 
bool DynamicTraversalSearchBST(Node* root)
{
    //1. Initialize an empty stack
    std::stack<Node*> S;

    // 2. Set current = root
    Node* current = root;
    Node* prev = nullptr;

    // 3. While current is not null or stack is not empty:
    while(current!= NULL || !S.empty())
    {
        //a. Traverse left subtree: while current is not null → push current → move left
        while(current!= NULL)
        {
            S.push(current); 
            // std::cout<<current->data<<std::endl;
            current = current->left;
        }; 
        //b. Pop from stack → compare value to previous
        current = S.top(); S.pop();
        //c. If current value ≤ previous → not BST
        if(prev!=nullptr && current->data <= prev->data)
        {
            return false;
        } 
        
        //d. Update previous → move right
        prev = current;
        current = current->right;

    };
    return true;
}      

void ValidateMultipleTrees(std::vector<std::vector<int>> allTrees){
    for(int i = 0; i< allTrees.size(); i++)
    {
        std::vector<int>& values = allTrees[i];
        Node* root = nullptr;
        int h;
        //Inserting the nodes with function that getting the datas with for loop
        for(int val: values)
        {
            root = InsertNode(root,val);
            h = FindHeightTree(root);
        }
        // root->right->left = new Node(9); // 👈 9 is placed where 12 was before
    
        std::cout<<"Tree "<< i+1<< ": ";
        if (DynamicTraversalSearchBST(root)) {
            std::cout << "Tree " << i+1 << ": Valid BST";
            if ((h + 1) == log2(values.size() + 1)) std::cout << " (Perfect)\n";
            else std::cout << " (Not Perfect)\n";
        } 
        else 
        {
            std::cout << "Tree " << i+1 << ": Invalid BST\n";
        }

    }
    /*
    if a tree wants to be perfect  BST it have to set some requipments and one of them is perfect balance in my word:
        its height +1 must be equal to the value of the logarithm of the dimension in the base 2 function
        such as:
             | H | size(array or any list type)|
             | 1 |         3                   |
             | 2 |         7                   |
             | 3 |         15                  |
             | 4 |         31                  |
             | n |        ...                  |
    */
}
   
int main(){
    // 📥 Sample input array:
    // int values[] = {15, 7, 25, 3, 12, 17, 30};
    // int values[] = {15, 7, 25, 3, 12, 17, 30};
    // int values[] = {15, 7, 25, 3, 12, 17, 30, 12};
    // int sizeArray = sizeof(values) / sizeof(values[0]);

    // for handle multiple trees
    // {15, 7, 25, 3, 12, 17, 30};              // ✅ Valid
    // {10, 5, 15, 3, 8, 5};         // ❌ Duplicate 5 (if disallowed)
    // {20, 10, 30, 5, 15, 25, 9};      // ❌ 9 is invalid if placed under 30
    // {40, 20, 60, 10, 30, 50, 70};        // ✅ Valid

    std::vector<std::vector<int>> alltrees = {
        {15, 7, 25, 3, 12, 17, 30},
        {10, 5, 15, 3, 8, 5},  
        {20, 10, 30, 5, 15, 25, 9},
        {40, 20, 60, 10, 30, 50, 70}
    };
    ValidateMultipleTrees(alltrees);


    return 0;
}
