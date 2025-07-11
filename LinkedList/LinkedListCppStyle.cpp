#include <iostream> // For input and output (cin and cout)

// Node class: represents each element in the linked list
class Node {
public:
    int data;     // Stores the value
    Node* next;   // Pointer to the next node in the list

    // Constructor: initializes a node with a value
    Node(int value) {
        data = value;
        next = nullptr; // Initially, next points to nothing
    }
};

// LinkedList class: manages operations on the list
class LinkedList {
private:
    Node* head; // Pointer to the first node in the list

public:
    // Constructor: initializes the list as empty
    LinkedList() {
        head = nullptr;
    }

    // Inserts a new node at the beginning of the list
    void insertAtBeginning(int value) {
        // Create a new node with the given value
        Node* newNode = new Node(value);

        // New node's next points to current head
        newNode->next = head;

        // Head is now updated to the new node
        head = newNode;
    }

    // Displays the current list contents
    void print() const {
        Node* temp = head; // Start from the head node
        std::cout << "List is:";

        // Traverse through the list until end (nullptr)
        while (temp != nullptr) {
            std::cout << " " << temp->data; // Print current node's data
            temp = temp->next;              // Move to the next node
        }
        std::cout << "\n";
    }

    // Destructor: called when LinkedList object is deleted
    // Frees all dynamically allocated memory to prevent memory leaks
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next; // Save pointer to next node
            delete current;                 // Free current node
            current = nextNode;             // Move to next
        }
    }
};

// Main function: handles user input and runs the program
int main() {
    LinkedList list;  // Create a linked list object
    int n, x;

    // Ask user how many numbers to insert
    std::cout << "How many numbers do you want to add?: ";
    std::cin >> n;

    // Input loop: ask user for values, insert each into the list
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the number: ";
        std::cin >> x;
        list.insertAtBeginning(x); // Insert at beginning
        list.print();              // Show updated list
    }

    return 0; // Program ends, destructor will clean up the list
}
   