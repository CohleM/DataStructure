#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* top; //top node

void push(int x) {
    Node* temp;
    temp = new Node; ////Dynamically allocating type Node (stuct)
    temp -> data = x;
    temp -> link = top;
    top = temp;

}

void pop() {
    Node* temp;
    if(temp == NULL ) return; //if temp is null stack is empty
    temp = top;
    top = top -> link;
}

void Traverse()
{ //This is also called Traversing
    Node *temp;
    temp = top;
    while (temp != NULL){
        cout << temp->data << ",";
        temp = temp->link;

    }
}
    int main()
    {
        top = NULL;
        push(5);
        push(4);
        push(3);
        pop();
        Traverse();

        return 0;
    }

