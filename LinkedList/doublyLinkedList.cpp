#include <iostream>

class DoublyLinkedList {
private:
    //Nested Node Structure
    struct Node{
        int data;
        Node* next;
        Node* prev;
        Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    };
    Node* head;    // Pointer to the first node in the list

    //Private recursive helper to reverse the list
    Node* RecursiveReverseHelper(Node* curr){
        if(curr == nullptr) return nullptr;

        // Base case: if we reach the last node, make it the new head
        if(curr->next == nullptr){
            head = curr;
        } else {
            //Recursively reverse the rest of the list
            RecursiveReverseHelper(curr->next);
        }

        // Reverse the links
        // curr->next->next = return back point
        Node* q = curr->next;
        if(q) q->next = curr; // Make q's next point back to curr
        
        curr->prev = q;  //Make curr's prev point to q
        curr->next = nullptr; // curr's next becomes null because it's now last
        return head;
    }
public:
    // Constructor: initialize list as empty
    DoublyLinkedList() : head(nullptr) {}

    // Insert node at the beginning of the list
    void InsertAtHead(int x) {
        Node* newNode = new Node(x); //Allocate new node
        if(!head) {
            // If list is empty, new node becomes head
            head = newNode;
        } else {
            //Otherwise, insert at the front
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert node at any given 1-based position
    //  Example: position=1 means insert at the head
    void InsertAtPosition(int data, int position) {
        //  Allocate a new node with the given data
        Node* newNode = new Node(data);

        //  If list is empty OR position is 1, just insert at head
        if (position <= 1 || !head) {
            InsertAtHead(data); // Uses existing helper
            return;             // Exit after inserting
        }

        //  Otherwise, traverse the list up to the (position-1)-th node
        Node* temp = head;   // Start traversal from head
        int index = 1;       // Keep track of current index

        //  Traverse until temp is the node before the desired position
        while (temp->next != nullptr && index < position - 1) {
            temp = temp->next; // Move to next node
            index++;           // Increment index counter
        }

        //  temp is now at (position-1)-th node
        //  Save pointer to the next node
        Node* nextNode = temp->next;

        //  Insert newNode between temp and nextNode:
        newNode->prev = temp;     // Set new node's prev to temp
        newNode->next = nextNode; // Set new node's next to nextNode

        temp->next = newNode;     // temp's next now points to new node

        //  If nextNode exists (not inserting at the end),
        //  set nextNode's prev to new node
        if (nextNode) {
            nextNode->prev = newNode;
        }
    }


    // Print list in forword order
        void Print() const {
            std::cout << "Forword: ";
            Node* temp = head;
            while(temp){
                std::cout<< temp->data << " "; // Output node data
                temp = temp->next;
            }
            std::cout<< std::endl;
        }

    // Print list in reverse order
    void ReversePrint() const {
        if(!head) return;

        // Traverse to last node
        Node* temp = head;
        while (temp->next) temp = temp->next;

        std::cout<<"Reverse: ";
        //Traverse backward using pre pointers
        while (temp) {
            std::cout<< temp->data<< " ";
            temp = temp->prev;
        }
        std::cout<<std::endl;
    }

    // Public method to reverse list using recursion
    void RecursiveREverse() {
        if(!head) return;
        RecursiveReverseHelper(head); // call helper with current head
    } 
};

int main() {
    DoublyLinkedList list;

    // Insert some data at head;
    list.InsertAtHead(2); list.Print(); list.ReversePrint();
    list.InsertAtHead(4); list.Print(); list.ReversePrint();
    list.InsertAtHead(6); list.Print(); list.ReversePrint();
    list.InsertAtHead(8); list.Print(); list.ReversePrint();
    
    std::cout<< "\n Reversing list using recursion...\n";
    list.RecursiveREverse();
    list.Print();
    list.ReversePrint();

    list.InsertAtPosition(10, 2); // list: 2 10 4 6
    list.Print();
    list.ReversePrint(); // 6 4 10 2
    
    list.InsertAtPosition(7,3); // list: 2 7 10 4 6
    list.Print();
    list.ReversePrint(); // 6 4 10 7 2

    return 0;
}