// This information is able to replace with addding 
//new book the library system

#include <iostream>

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }

};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head = nullptr;
    }

    void InsertAtBeginning(int value){
        Node* newnode = new Node(value);

        newnode->next = head;
        head = newnode;
    }

    void print() const {
        Node* temp = head;
        std::cout<<"List is: ";

        while (temp != nullptr){
            std::cout<< " "<< temp->data;
            temp = temp->next;
        }
        std::cout<< "\n";
    }

    ~LinkedList(){
        Node* current = head;
        while (current != nullptr) {
            Node* nextnode = current->next;
            delete current;
            current = nextnode;
        }
    }
};

int main() {
    LinkedList list;
    int n, x;

    std::cout<<"How many number do you want to add?: ";
    std::cin>>n;

    for(int i=0; i<n; i++){
        std::cout<<"Enter the number: ";
        std::cin>>x;
        list.InsertAtBeginning(x);
        list.print();
    }

    return 0;
}