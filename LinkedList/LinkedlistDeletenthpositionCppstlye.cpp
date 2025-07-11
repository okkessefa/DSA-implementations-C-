#include <iostream>

// Node class represents each element in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with data
    Node(int data) : data(data), next(nullptr) {}
};

// LinkedList class manages the list operations
class LinkedList {
private:
    Node* head;     // Pointer to the first node in the list

public:
    // Constructor initializes an empty list
    LinkedList() : head(nullptr) {}

    // Function to insert a node with given data at the specified position
    void insert(int data, int position) {
        Node* newNode = new Node(data); // Create a new node
        if (position == 1) {
            // Insert at the beginning
            newNode->next = head;
            head = newNode;
            return;
        }

        // Traverse the list to find the (position - 1)th node
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        // If position is beyond the current length, print error
        if (temp == nullptr) {
            std::cerr << "Insert Error: Position out of bounds.\n";
            delete newNode; // Prevent memory leak
            return;
        }

        // Insert new node after the (position - 1)th node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node at the specified position
    void deleteAt(int position) {
        if (head == nullptr) {
            std::cerr << "Delete Error: List is empty.\n";
            return;
        }

        // Case 1: Deleting the head node
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Traverse to the (position - 1)th node
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        // Check if the position is valid
        if (temp == nullptr || temp->next == nullptr) {
            std::cerr << "Delete Error: Position out of bounds.\n";
            return;
        }

        // temp points to (position - 1)th node
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Function to print all elements in the list
    void print() const {
        Node* temp = head;
        std::cout << "Linked List: ";
        while (temp != nullptr) {
            std::cout << temp->data << " "; // Print current node's data
            temp = temp->next;              // Move to next node
        }
        std::cout << "\n";
    }

    // Destructor to clean up memory when the list is destroyed
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;       // Delete current node
            current = nextNode;   // Move to next node
        }
    }
};

// Main function to test the LinkedList class
int main() {
    LinkedList list;

    list.insert(2, 1); // List: 2
    list.insert(3, 2); // List: 2 → 3
    list.insert(4, 1); // List: 4 → 2 → 3
    list.insert(5, 2); // List: 4 → 5 → 2 → 3

    list.print(); // Output: Linked List: 4 5 2 3

    list.deleteAt(3); // Deletes value 2 → List becomes: 4 5 3
    list.print();     // Output: Linked List: 4 5 3

    list.deleteAt(1); // Deletes head (4) → List becomes: 5 3
    list.print();     // Output: Linked List: 5 3

    list.deleteAt(5); // Invalid position (out of bounds)
    list.print();     // Output: Linked List: 5 3

    return 0;
}
