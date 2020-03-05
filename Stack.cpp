//Stack using one-dimensional array
#include <iostream>
using namespace std;

#define SIZE 10;
int top = -1;

int stack[SIZE];

void push(val) {
    if (top != SIZE - 1 ) {
        top++;
        stack[top] = val; 
    }
    else {
        cout << "The Stack is FULL";
    }
}

void pop(val) {
    if (top != -1 ) {
        stack[top] = 

    }

}

void isEmpty() {

}

void isFull() {

}

int main() {

}




class Stack {
    static int top;
    int size,val;

    void createStack(size);
    void push(val);
    void pop();
    bool isEmpty();
    bool isFull();
    
};