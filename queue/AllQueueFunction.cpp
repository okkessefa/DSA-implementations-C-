#include <iostream>

#define SIZE 10  // Maximum size of the queue

class CircularQueue {
    int arr[SIZE], front, rear;
 
public:
    // Constructor: Initialize front and rear as -1 (queue is empty)
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if the queue is full (circular condition)
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Insert an element at the rear of the queue
    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot enqueue " << x << std::endl;
            return;
        }

        // If queue is empty, set front and rear to 0
        if (isEmpty()) {
            front = rear = 0;
        } else {
            // Move rear to next position (circularly)
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = x;  // Insert the element
        std::cout << "Enqueued: " << x << std::endl;
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        std::cout << "Dequeued: " << arr[front] << std::endl;

        // If there was only one element, reset queue to empty state
        if (front == rear) {
            front = rear = -1;
        } else {
            // Move front to next position (circularly)
            front = (front + 1) % SIZE;
        }
    }

    // Get the element at the front of the queue (without removing it)
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    // Display all elements in the queue from front to rear
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty!\n";
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        std::cout << std::endl;
    }

    // Get the current size of the queue
    int size() {
        if (isEmpty()) return 0;
        if (rear >= front) return rear - front + 1;
        return SIZE - (front - rear - 1);
    }
};

int main() {
    CircularQueue q;

    // Enqueue some elements
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(7);

    q.display(); // Should print: 2 5 7

    // Dequeue one element
    q.dequeue();

    // Enqueue more elements
    q.enqueue(3);
    q.enqueue(1);

    q.display(); // Should print: 5 7 3 1

    // Show the element at the front
    std::cout << "Front element: " << q.getFront() << std::endl;

    // Show the current size of the queue
    std::cout << "Queue size: " << q.size() << std::endl;

    // Fill up the queue
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(2);

    // Try to enqueue into a full queue
    q.enqueue(8);

    q.display();

    // Dequeue all elements
    while (!q.isEmpty()) {
        q.dequeue();
    }

    // Try to dequeue from an empty queue
    q.dequeue();

    return 0;
}
