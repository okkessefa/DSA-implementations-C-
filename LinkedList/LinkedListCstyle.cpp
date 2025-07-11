#include <iostream>
// Linked List: Interting a node at the beginning
struct Node {
    int data;
    struct Node* next;
};

struct Node* head; // global varible, can be accessed anywhere

void Insert(int x);
void Print();

int main(){
    head = NULL; // emty list;
    std::cout<<"How many numbers do you want to add?: ";
    int n, x;
    std::cin>>n;
    for(int i = 0; i<n; i++){
        std::cout<<"Enter the number: \n";
        std::cin>>x;
        Insert(x);
        Print();
    }

    return 0;
}

void Insert(int x){
    struct Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Print(){
    struct Node* temp = head;
    std::cout<<"List is: ";
    while(temp != NULL){
        std::cout<<" "<<temp->data;
        temp = temp->next;
    }
    std::cout<<"\n";
}