#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
    Stack() {
        top = NULL;
    }
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed into stack\n";
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }
    bool isEmpty() {
        return top == NULL;
    }
};
