#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* StartNode;  // First Node in a linkedList it's type is (Node*) i.e a pointer . It is a global variable so it can be accessed anywhere. 

bool isEmpty() {
    if(StartNode == NULL ) return true;
    else false;
}

void insertToHead(int x) {
    Node* temp;
    temp = new Node; //
    temp->data = x;
    temp->link = StartNode;
    StartNode = temp; //saving the address of temp(newly added variable) to StartNode

}


void insertAtTail(int x) { 
    Node* temp;
    Node* newTemp;
    temp = StartNode; 
    while (temp->link != NULL){  // if pointer to the next node is not null change the temp's address
        temp = temp->link;
    }
    newTemp = new Node;  //Dynamically allocating type Node (stuct)
    temp->link = newTemp;
    newTemp -> data = x;
    newTemp -> link = NULL;


}

void add(int data, int predececssor) {
    Node* temp;
    Node* newTemp;
    Node* flag;
    temp = StartNode;
    while(temp -> data != predececssor) { //traversing . . .
        temp = temp -> link;
    }
    newTemp = new Node;
    flag = temp -> link;
    temp-> link = newTemp;
    newTemp->link = flag;
    newTemp -> data = data;

}

void removeFromHead() {
    Node* temp = StartNode;
    StartNode = temp -> link;
    delete temp;
}

void remove(int data) {
    Node* temp = StartNode;
    Node* previous;
    while(temp-> data != data) {
        previous = temp;
        temp = temp -> link;
    }
    previous -> link = temp -> link;
    delete temp;

}

bool search(int data) {
    Node* temp;
    while( temp != NULL) {
        if(temp -> data == data) return true;
        else return false;
    temp = temp -> link; 
    }
}

void Traverse() { //This is also called Traversing
    Node* temp;
    temp = StartNode;
    while(temp != NULL) {
        cout << temp->data<<",";
        temp = temp->link;
    }
}

int main() {
StartNode = NULL; // defining the address of StartNode
insertToHead(4);
insertToHead(5);
insertAtTail(6);
insertAtTail(8);
add(10,4);
//removeFromHead();
remove(6);
Traverse();
//insertAtLast(;)

return 0;
}

// // A simple representation of graph using STL
// #include <bits/stdc++.h>
// using namespace std;

// // A utility function to add an edge in an
// // undirected graph.
// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// // A utility function to print the adjacency list
// // representation of graph
// void printGraph(vector<int> adj[], int V)
// {
//     for (int v = 0; v < V; ++v)
//     {
//         cout << "\n Adjacency list of vertex "
//              << v << "\n head ";
//         for (auto x : adj[v])
//             cout << "-> " << x;
//         printf("\n");
//     }
// }

// // Driver code
// int main()
// {
//     int V = 5;
//     vector<int> adj[V];
//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 4);
//     addEdge(adj, 1, 2);
//     addEdge(adj, 1, 3);
//     addEdge(adj, 1, 4);
//     addEdge(adj, 2, 3);
//     addEdge(adj, 3, 4);
//     printGraph(adj, V);
//     return 0;
// }

// Program to create a graph and use Deapth First Search(DFS) and Breadth First Search(BFS) Traversal.

// #include <conio.h>
// #include <iostream.h>
// #include <stdlib.h>

//                                                                void create(); // For creating a graph
// void dfs();                                                                   // For Deapth First Search(DFS) Traversal.
// void bfs();                                                                   // For Breadth First Search(BFS) Traversal.

// struct node // Structure for elements in the graph
// {
//     int data, status;
//     struct node *next;
//     struct link *adj;
// };

// struct link // Structure for adjacency list
// {
//     struct node *next;
//     struct link *adj;
// };

// struct node *start, *p, *q;
// struct link *l, *k;

// int main()
// {
//     int choice;
//     clrscr();
//     create();
//     while (1)
//     {
//         cout << "

//                 -----------------------";
//                 cout
//              << "
//                 1 : DFS 2 : BSF 3 : Exit
//                                         Enter your choice : ";
//                                                             cin >>
//             choice;
//         switch (choice)
//         {
//         case 1:
//             dfs();
//             break;
//         case 2:
//             bfs();
//             break;
//         case 3:
//             exit(0);
//             break;
//         default:
//             cout << "
//                         Incorrect choice !Re -
//                         enter your choice.";
//                         getch();
//         }
//     }
//     return 0;
// }

// void create() // Creating a graph
// {
//     int dat, flag = 0;
//     start = NULL;
//     cout << "
//         Enter the nodes in the graph(0 to end) : ";
//                                                  while (1)
//     {
//         cin >> dat;
//         if (dat == 0)
//             break;
//         p = new node;
//         p->data = dat;
//         p->status = 0;
//         p->next = NULL;
//         p->adj = NULL;
//         if (flag == 0)
//         {
//             start = p;
//             q = p;
//             flag++;
//         }
//         else
//         {
//             q->next = p;
//             q = p;
//         }
//     }
//     p = start;
//     while (p != NULL)
//     {
//         cout << "Enter the links to " << p->data << " (0 to end) : ";
//         flag = 0;
//         while (1)
//         {
//             cin >> dat;
//             if (dat == 0)
//                 break;
//             k = new link;
//             k->adj = NULL;
//             if (flag == 0)
//             {
//                 p->adj = k;
//                 l = k;
//                 flag++;
//             }
//             else
//             {
//                 l->adj = k;
//                 l = k;
//             }
//             q = start;
//             while (q != NULL)
//             {
//                 if (q->data == dat)
//                     k->next = q;
//                 q = q->next;
//             }
//         }
//         p = p->next;
//     }
//     cout << "

//         -------------------------";
//         return;
// }

// // Deapth First Search(DFS) Traversal.
// void bfs()
// {
//     int qu[20], i = 1, j = 0;
//     p = start;
//     while (p != NULL)
//     {
//         p->status = 0;
//         p = p->next;
//     }
//     p = start;
//     qu[0] = p->data;
//     p->status = 1;
//     while (1)
//     {
//         if (qu[j] == 0)
//             break;
//         p = start;
//         while (p != NULL)
//         {
//             if (p->data == qu[j])
//                 break;
//             p = p->next;
//         }
//         k = p->adj;
//         while (k != NULL)
//         {
//             q = k->next;
//             if (q->status == 0)
//             {
//                 qu[i] = q->data;
//                 q->status = 1;
//                 qu[i + 1] = 0;
//                 i++;
//             }
//             k = k->adj;
//         }
//         j++;
//     }
//     j = 0;
//     cout << "

//         Breadth First Search Results
//             ";
//         cout
//          << "
//         ---------------------------";
//         while (qu[j] != 0)
//     {
//         cout << qu[j] << "  ";
//         j++;
//     }
//     getch();
//     return;
// }

// // Breadth First Search(BFS) Traversal.
// void dfs()
// {
//     int stack[25], top = 1;
//     cout << "

//         Deapth First Search Results
//             ";
//         cout
//          << "
//         ---------------------------";
//         p = start;
//     while (p != NULL)
//     {
//         p->status = 0;
//         p = p->next;
//     }
//     p = start;
//     stack[0] = 0;
//     stack[top] = p->data;
//     p->status = 1;
//     while (1)
//     {
//         if (stack[top] == 0)
//             break;
//         p = start;
//         while (p != NULL)
//         {
//             if (p->data == stack[top])
//                 break;
//             p = p->next;
//         }
//         cout << stack[top] << "  ";
//         top--;
//         k = p->adj;
//         while (k != NULL)
//         {
//             q = k->next;
//             if (q->status == 0)
//             {
//                 top++;
//                 stack[top] = q->data;
//                 q->status = 1;
//             }
//             k = k->adj;
//         }
//     }
//     getch();
//     return;
// }
