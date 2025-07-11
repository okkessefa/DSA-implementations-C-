#include <iostream>

// Define the node structure for the queue
struct Node {
    int data;       // Holds the data
    Node* next;     // Pointer to the next node
};

// Global pointers for the front and rear of the queue
Node* front = NULL;
Node* rear = NULL;

// Function to add an element at the rear of the queue
void enqueue(int x) {
    // Create a new node
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    // If the queue is empty, both front and rear point to the new node
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        std::cout << "Enqueued (first element): " << x << std::endl;
        return;
    }

    // Attach the new node at the end and move rear
    rear->next = temp;
    rear = temp;
    std::cout << "Enqueued: " << x << std::endl;
}

// Function to remove an element from the front of the queue
void dequeue() {
    // If the queue is empty, nothing to remove
    if (front == NULL) {
        std::cout << "Queue is empty! Nothing to dequeue.\n";
        return;
    }

    // Save the current front node
    Node* temp = front;

    // If there's only one node, reset both front and rear
    if (front == rear) {
        front = rear = NULL;
    } else {
        // Move front to the next node
        front = front->next;
    }
    std::cout << "Dequeued: " << temp->data << std::endl;
    delete temp; // Free the memory
}

// Function to show the element at the front of the queue
void showFront() {
    if (front == NULL) {
        std::cout << "Queue is empty!\n";
        return;
    }
    std::cout << "Front element: " << front->data << std::endl;
}

// Function to display all elements in the queue
void display() {
    if (front == NULL) {
        std::cout << "Queue is empty!\n";
        return;
    }
    Node* temp = front;
    std::cout << "Queue elements: ";
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Function to check if the queue is empty
bool isEmpty() {
    return (front == NULL);
}

// Example usage
int main() {
    enqueue(2);
    enqueue(4);
    enqueue(6);
    display();        // Queue: 2 4 6

    dequeue();        // Remove 2
    display();        // Queue: 4 6

    showFront();      // Should show 4

    dequeue();        // Remove 4
    dequeue();        // Remove 6
    dequeue();        // Try to remove from empty queue

    // Check if empty
    if (isEmpty())
        std::cout << "Queue is now empty.\n";

    return 0;
}
