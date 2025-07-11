/*
✅ Concept:
In-order traversal of a valid BST produces a strictly increasing sequence.
So, you can validate a BST by:

Doing an in-order traversal iteratively

Keeping track of the previous node’s value

If the current node’s value is less than or equal to the previous one → ❌ not a BST

*/


//initializing libraries
#include <iostream>
#include <stack>

//define the node structure
struct Node {
   int data;
   Node* left;
   Node* right;

   Node(int value) : data(value), left(nullptr) , right(nullptr) {} 
};



// Funtion to visit each not without recursion
bool TraversalSearchBST(Node* root);

int main(){
   
   Node* root = new Node(15);
   root->left = new Node(7);
   root->right = new Node(25);
   root->left->left = new Node(3);
   root->left->right = new Node(12);
   root->right->left = new Node(17);
   root->right->right = new Node(30);

   if(TraversalSearchBST(root)){
      std::cout<< "This tree is valid Binary Search Tree."<<std::endl;
   }else{
      std::cout<< "This tree is not valid binary Search Tree."<<std::endl;
   }

   return 0;
}
//
//         15
//        /  \
//       7    25
//      / \   / \
//     3  12 17 30
// 
// main idea is 
// Traverse Left Subtree
// Visit Current Node
// Traverse Right Subtree


bool TraversalSearchBST(Node* root)
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
         current = current->left;
      }  
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
   }
   return true;
}      
   
   // 4. If completed without issue → BST is valid