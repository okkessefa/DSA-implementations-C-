#include <iostream>
#include <stack>
 
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* head = nullptr; // Global head pointer for the list

// ✅ Reverse the linked list using a stack
void Reverse() {
    if (head == nullptr) return;  // 🔍 If list is empty, just return
    
    std::stack<Node*> S;         // 🔍 Stack to store node pointers
    Node* temp = head;      // 🔍 Temp pointer to traverse the list

    // 🔄 Push all nodes onto the stack
    while (temp != nullptr) {
        S.push(temp);       // Push the node's address into stack
        temp = temp->next;  // Move to next node
    }

    // 🔄 Pop the top node as the new head
    temp = S.top();
    head = temp;
    S.pop();

    // 🔄 Reconnect nodes in reversed order
    while (!S.empty()) {
        temp->next = S.top(); // Connect the last node's next to top node
        S.pop();              // Remove the top node
        temp = temp->next;    // Move temp to the node just connected
    }

    temp->next = nullptr;     // 🔍 Last node's next must be NULL
}

// ✅ Helper function to insert at head
void InsertAtHead(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// ✅ Helper function to print the list
void PrintList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// 🧪 Test in main
int main() {
    InsertAtHead(5);
    InsertAtHead(10);
    InsertAtHead(15);
    InsertAtHead(20);  // list = 20 -> 15 -> 10 -> 5
    std::cout << "Original list: ";
    PrintList();

    Reverse();
    std::cout << "Reversed list: ";
    PrintList();

    return 0;
}
