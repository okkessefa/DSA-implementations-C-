#include <iostream>
#include <fstream>
#include <string>

// Node definition
struct BstNode 
{
    std::string data;
    BstNode* left;
    BstNode* right;
}; 
// Declaring the functions  
// Create a new node
BstNode* GetNewNode(std::string data);
// Insert a word into the BST
BstNode* Insert(BstNode* root, std::string data);
// Search for a word in the BST
bool Search(BstNode* root, std::string data);


int main() {
    BstNode* root = NULL;
    std::string dictWord;

    // Step 1: Build BST from dictionary file
    std::ifstream dictFile("word.txt");
    while (dictFile >> dictWord) {
        root = Insert(root, dictWord);
    }
    dictFile.close();
    // Step 2: Spell Check loop
    std::string userWord;
    std::cout << "Enter words to check spelling (type 'exit' to quit):\n";
    while(true){
        std::cout << "Word: ";
        std::cin>> userWord;
        if(userWord == "exit") break;
        if(Search(root, userWord)) std::cout<< "Correct Spelling!"<<std::endl;
        else std::cout<< "Misspelling!"<<std::endl; 
    }
    return 0;
}
//Creating the functions
// Create a new node
BstNode* GetNewNode(std::string data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Insert a word into the BST
BstNode* Insert(BstNode* root, std::string data)
{
    if (root == NULL) root = GetNewNode(data); 
    if (data < root->data) root->left = Insert(root->left , data);
    else if (data > root->data) root->right = Insert(root->right, data);
    // If the word is already present, do nothing
    return root;
}
// Search for a word in the BST
bool Search(BstNode* root, std::string data)
{
    // there are 4 option , tree can be empty
    // data can be equal 
    // data can be smaller 
    // data can be greather 
    if(root == NULL) return false;
    else if (data == root->data ) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}
