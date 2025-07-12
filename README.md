# 📂 Data Structures in C++: Queue, Linked List, Binary Search, and Graphs

This project is a collection of essential **data structures and algorithms implemented in C++**, designed to demonstrate their usage, performance, and common operations. It is intended as a reference and learning resource for students, developers, and enthusiasts studying **Data Structures and Algorithms (DSA)**.

---

## 📌 Contents

- [Overview](#overview)
- [Queue](#queue)
- [Linked List](#linked-list)
- [Binary Search](#binary-search)
- [Graphs](#graphs)
- [Setup & Compilation](#setup--compilation)
- [How to Contribute](#how-to-contribute)
- [License](#license)

---

## 🔍 Overview

This repository includes the following core topics in C++:

| Component       | Features Implemented                                       | File Name             |
|-----------------|-------------------------------------------------------------|------------------------|
| Queue           | Enqueue, Dequeue, Front, Rear, IsEmpty                      | `queue.cpp`            |
| Linked List     | Insertion, Deletion, Search, Reverse, Traverse              | `linked_list.cpp`      |
| Binary Search   | Recursive and Iterative Search in Sorted Arrays            | `binary_search.cpp`    |
| Graph           | Adjacency List & Matrix, DFS, BFS, Cycle Detection         | `graph.cpp`            |

All source files include **commented C++ code** for easy understanding and educational use.

---

## 📦 Queue

A **Queue** is a First-In-First-Out (FIFO) linear data structure used in scheduling, buffering, and real-time systems.

### ✅ Types Implemented:
- Static Queue using arrays
- Dynamic Queue using linked lists

### 🔧 Supported Operations:
- `enqueue(value)`: Add an element to the rear of the queue
- `dequeue()`: Remove an element from the front of the queue
- `front()`: Access the front element without removing it
- `rear()`: Access the last element
- `isEmpty()`: Check if the queue is empty

### 🧪 Sample Code:
```cpp
Queue q;
q.enqueue(10);
q.enqueue(20);
q.dequeue(); // removes 10


---

Let me know when you're ready to move to **Step 3: Linked List**, or if you'd like to revise this section.

---

## 🔗 Linked List

A **Linked List** is a linear data structure where each element (called a node) contains a value and a pointer to the next node. Unlike arrays, linked lists allow dynamic memory allocation and efficient insertion/deletion at arbitrary positions.

### ✅ Types Implemented:
- Singly Linked List (default)
- (Optional) Doubly or Circular Linked Lists

### 🔧 Supported Operations:
- `insertAtHead(value)`: Insert a node at the beginning
- `insertAtEnd(value)`: Insert a node at the end
- `deleteNode(value)`: Remove a node by value
- `search(value)`: Search for an element
- `reverseList()`: Reverse the entire list
- `traverseList()`: Display all elements in order

### 🧪 Sample Code:
```cpp
Node* head = NULL;
insertAtEnd(head, 5);
insertAtEnd(head, 15);
deleteNode(head, 5);
displayList(head); // Output: 15

---

---

## 🌲 Binary Search Tree (BST) – Recursive Search

This module includes a recursive search operation for a **Binary Search Tree (BST)**. A BST maintains the property:  
**Left subtree values < node < right subtree values**, which allows efficient search and insertion.

### ✅ Search Logic:
- Traverse to the left if the target is smaller
- Traverse to the right if the target is greater
- Return `true` if the node matches
- Return `false` if you hit a `NULL` pointer

### 🔧 Function:
```cpp
bool Search(BstNode* root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data < root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

---

## 🌐 Graphs

A **Graph** is a non-linear data structure consisting of **vertices (nodes)** connected by **edges**. It can be directed or undirected, weighted or unweighted.

### ✅ Representations:
- **Adjacency List**: Efficient for sparse graphs
- **Adjacency Matrix**: Efficient for dense graphs

### 🔧 Supported Algorithms:
- `addEdge(u, v)`: Add an edge between nodes `u` and `v`
- `DFS(start)`: Depth-First Search traversal
- `BFS(start)`: Breadth-First Search traversal
- (Optional) Cycle Detection (DFS-based or Union-Find)
- (Optional) Topological Sorting

### 🧪 Sample Code:
```cpp
Graph g(5);
g.addEdge(0, 1);
g.addEdge(0, 4);
g.addEdge(1, 2);
g.BFS(0); // Traverses starting from node 0


---

## ⚙️ Setup & Compilation

To run the programs in this repository, you need a C++ compiler installed on your system (e.g., `g++`, `clang++`, or MSVC).

### 🔧 Compilation Instructions

Use the terminal or command prompt to compile each `.cpp` file individually.

#### Linux / macOS / Windows with MinGW or MSYS2:
```bash
g++ queue.cpp -o queue
./queue

g++ linked_list.cpp -o linkedlist
./linkedlist

g++ bst_search.cpp -o bstsearch
./bstsearch

g++ graph.cpp -o graph
./graph
