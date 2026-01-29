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
void deletepos(int pos) {
    if (head == NULL)
        return;
    if (pos == 1) {
        head = head->next;
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != NULL; i++) {
        curr = curr->next;
    }

    if (curr->next != NULL) {
        curr->next = curr->next->next;
    }
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

    cout << "Original List: \n";
    printList();

    deletepos(3);

    cout <<"After Deleting \n";
    printList();

    return 0;
}
