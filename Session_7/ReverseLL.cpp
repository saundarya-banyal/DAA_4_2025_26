#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

void insert(int val) {
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;   
        curr->next = prev;       
        prev = curr;             
        curr = nextNode;         
    }
    head = prev;  
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    printList();
    reverseList();

    cout << "\nReversed List: ";
    printList();

    return 0;
}
