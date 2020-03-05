#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* genNewNode(int data) {
    Node* temp = new Node;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
Node* insert(Node* root,int data) {
    if(root == NULL) {
        root = genNewNode(data);
    }
    else if (data <= root->data) {
        root -> left = insert(root->left,data);
    }
    else if (data >= root->data){
        root->right = insert(root->right,data);
    }

    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root, 20);
    root = insert(root, 25);
    return 0;
}
