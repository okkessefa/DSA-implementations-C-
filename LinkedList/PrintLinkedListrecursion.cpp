#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
};

// Recursively print the linked list in reverse order
void ReversePrint(Node* p) {
    // Base case: if we've reached the end of the list
    if (p == nullptr) {
        return;
    }

    // Recursively move to the next node
    ReversePrint(p->next);

    // Print current node's data after all recursive calls
    std::cout << p->data << " ";
}

// Helper function to insert a node at the end
Node* Insert(Node* head, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr) {
        return temp;
    }

    Node* temp1 = head;
    while (temp1->next != nullptr) {
        temp1 = temp1->next;
    }

    temp1->next = temp;
    return head;
}

// Print list in normal order
void Print(Node* head) {
    std::cout << "Normal Print: ";
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function to test
int main() {
    Node* head = nullptr;

    head = Insert(head, 2);
    head = Insert(head, 6);
    head = Insert(head, 5);
    head = Insert(head, 4);

    Print(head);                 // Output: 2 6 5 4
    std::cout << "Reverse Print: ";
    ReversePrint(head);         // Output: 4 5 6 2
    std::cout << std::endl;

    return 0;
}
 