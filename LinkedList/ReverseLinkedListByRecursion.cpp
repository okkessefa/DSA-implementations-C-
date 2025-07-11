#include <iostream>

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Global pointer to the head of the list
Node* head = nullptr;

// Reverse the linked list starting from node p
// and set the global 'head' pointer to the new head.
void Reverse(Node* p) {
    // 🎯 Base case: if p is the last node in the list
    if (p->next == nullptr) {
        head = p;  // Make the last node into the new head of the reversed list
        return;    // Stop going deeper
    }

    // 🎯 Recursively go to the next node
    Reverse(p->next);

    // 🎯 Let's do the "link reversal" after recursion:
    // Save the next node so we can access it
    Node* q = p->next;

    // 🎯 Make the next node's next point back to this node
    q->next = p;

    // 🎯 Make this node's next NULL because it'll become the last node
    p->next = nullptr;
}

// This function inserts a new node containing `data` at the end of the list.
Node* Insert(Node* head, int data) {
    // 1️⃣ Create a new node and put our data inside it
    Node* temp = new Node();  // allocate new node
    temp->data = data;        // store the data
    temp->next = nullptr;     // new node's next is NULL because it's the last node

    // 2️⃣ Special case: if the list is empty (no nodes at all)
    if (head == nullptr) {
        return temp;  // the new node becomes the head of the list
    }

    // 3️⃣ Otherwise, traverse the list to find the last node
    Node* temp1 = head;            // temp1 is our "pointer" that we move along the list
    while (temp1->next != nullptr) { // repeat until we reach the last node
        temp1 = temp1->next;
    }

    // 4️⃣ Connect the last node's "next" to our new node
    temp1->next = temp;

    // 5️⃣ Finally, return the head of the list (no change to the first node)
    return head;
}


// Function to print the list
void Print(Node* head) {
    std::cout << "Linked List: ";
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Main function to demonstrate the recursive reverse
int main() {
    head = Insert(head, 2);
    head = Insert(head, 6);
    head = Insert(head, 5);
    head = Insert(head, 4);

    Print(head);     // Before reverse: 2 6 5 4

    Reverse(head);   // Recursive reverse

    Print(head);     // After reverse: 4 5 6 2

    return 0;
}
