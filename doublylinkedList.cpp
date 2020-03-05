#include <iostream>
using namespace std;

struct Node* head;
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* genNewNode(int x) {
    Node *temp;
    temp = new Node;
    temp ->data = x;
    temp ->prev = NULL;
    temp ->next = NULL;
    return temp;
}


void insertAtHead(int x) {
    Node* temp;
    temp = genNewNode(x);
    
    if (head == NULL) {
        head =  temp;
        return;
    }  
    head ->prev = temp;
    temp->next = head;
    head = temp;

}

void printFromFront() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp ->data;
        temp = temp -> next;
    }

}

void printFromBack() {
    Node* temp = head;
    while(temp ->next != NULL) {
        temp = temp ->next;
    }

    while(temp != NULL) {
        cout << temp ->data;
        temp = temp ->prev;
    }

}



int main() {
    head = NULL;
    insertAtHead(5);
    insertAtHead(6);
    //printFromFront();
    printFromBack();
    return 0;
}