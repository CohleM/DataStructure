#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* front; // front node
Node* rear; // rear node

void enqueue(int x) {
    Node* temp;
    temp = new Node; ////Dynamically allocating type Node (stuct)
    temp -> data = x;
    temp ->link = NULL;
    if(front == NULL && rear == NULL ) { //in this case the queue is empty
        front = rear = temp;
        return;    
    }
    rear->link = temp;
    rear = temp;

}
void dequeue() {
    Node* temp;
    if(front == NULL) return;  // if queue is empty front will be NULL
    if(front == rear) front=rear= NULL; // if there is only one element then front and rear will be equal
    else {
        front = front -> link; 
    }
}

void Traverse()
{ //This is also called Traversing
    Node *temp;
    temp = front;
    while (temp != NULL){
        cout << temp->data << ",";
        temp = temp->link;

    }
}
    int main()
    {
        front = NULL;
        rear = NULL;

        enqueue(5);
        enqueue(7);
        dequeue();
        Traverse();

        return 0;
    }


