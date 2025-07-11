#include <iostream>

// Node structure represents each element of the linked list
struct Node {
    int data;       // Value of the node
    Node* next;     // Pointer to the next node
};

// Insert a new node at the end of the list
Node* Insert(Node* head, int data) {
    // Create a new node dynamically
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    // If the list is empty, the new node becomes the head
    if (head == nullptr) {
        head = temp;
    } else {
        // Traverse to the last node
        Node* temp1 = head;
        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }
        // Link last node to the new node
        temp1->next = temp;
    }

    return head;
}

// Print all elements of the list 
void Print(Node* head) {
    std::cout << "Linked List: ";
    while (head != nullptr) {
        std::cout << head->data << " "; // Print current node's data
        head = head->next;              // Move to next node
    }
    std::cout << std::endl;
}

// Reverse the entire linked list
Node* Reverse(Node* head) {
    Node* current = head;   // Current node being processed
    Node* prev = nullptr;   // Previous node (starts as null)
    Node* next = nullptr;   // Will store the next node temporarily

    while (current != nullptr) {
        next = current->next;     // Store next node
        current->next = prev;     // Reverse the link
        prev = current;           // Move prev forward
        current = next;           // Move current forward
    }
 
    // After loop, prev is the new head
    head = prev;
    return head;
}

// Main function to demonstrate insert, print, and reverse
int main() {
    Node* head = nullptr; // Start with an empty list

    // Insert values
    head = Insert(head, 2);  // List: 2
    head = Insert(head, 4);  // List: 2 → 4
    head = Insert(head, 6);  // List: 2 → 4 → 6
    head = Insert(head, 8);  // List: 2 → 4 → 6 → 8

    // Print original list
    Print(head); // Output: Linked List: 2 4 6 8

    // Reverse the list
    head = Reverse(head);

    // Print reversed list
    Print(head); // Output: Linked List: 8 6 4 2

    return 0;
}
