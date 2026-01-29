#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {   
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void traverseForward(Node* head) {
    Node* temp = head;
    cout << "Forward traversal: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void traverseReverse(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
 
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Reverse traversal: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    traverseForward(head);
    traverseReverse(head);

    return 0;
}