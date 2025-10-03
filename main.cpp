// COMSC-210 | Lab 17 | Keng C Chan
// IDE used: Visual Studio Code (VS Code)
#include <iostream>
#include <cstdlib> //rand()
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// function prototypes
// addToFront() adds a new mode with the given value to Head of list
// arguments: head pointer, float value
// returns: NA
void addToFront(Node *&head, float value);

// addToTail() adds a new mode with the given value to Tail of list
// arguments: head pointer, float value
// returns: NA
void addToTail(Node *&head, float value);

// deleteNode() delete the nth node (1-based index) from list
// arguments: head pointer, int position
// returns: NA
void deleteNode(Node *&head, int position);

// insertNode() inserts a new node with given value after nth list
// arguments: head pointer, int position, float value
// returns: NA
void insertNode(Node *&head, int position, float value);

// deleteNode() delete all node in the linked list
// arguments: head pointer
// returns: NA
void deleteList(Node *&head);

// output() output the linked list
// arguments: pointer to head
// returns: NA
void output(Node *head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        addToFront(head, tmp_val); //(Puts New node at the Head)
        //addToTail(head, tmp_val); (Puts New node at the End)

    }
    cout << "Initial list:\n";
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    cout << "List after Delete:\n";
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    cout << "List after insertion:\n";
    output(head);

    // deleting the linked list
    deleteList(head);
    cout << "List after delete the entire linked list:\n";
    output(head);

    return 0;
}

void addToFront(Node *&head, float value){
    Node *newNode = new Node{value, head};
    head = newNode;
}

void addToTail(Node *&head, float value){
    Node *newNode = new Node{value, nullptr};
    if (!head){
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next){
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node *&head, int position){
    if (!head || position < 1) return;
    Node *current = head;
    if (position == 1) {
        //delete head
        head = head->next;
        delete current; 
        return;
    }
    Node *prev = nullptr;
    for (int i = 1; current && i < position; i++){
        prev = current;
        current = current->next;
    }
    if (current){
        prev->next = current->next;
        delete current;
    }
}

void insertNode(Node *&head, int position, float value){
    if (position < 1) return;
    Node *current = head;
    for (int i = 1; current && i < position; i++){
        current = current->next;
    }    
    if (!current) return;
    Node *newNode = new Node{value, current->next};
    current->next = newNode;
}

void deleteList(Node *&head){
    Node *current = head;
    while (current){
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

void output(Node * head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
