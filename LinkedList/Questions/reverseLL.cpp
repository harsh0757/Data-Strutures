#include <iostream>
#include "linkedListStructure.cpp"
using namespace std;

void reverseLL(Node* &head) {
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtTail(tail, 11);
    insertAtTail(tail, 13);
    insertAtPosition(head, tail, 5, 12);
    print(head);
    reverseLL(head);
    print(head);
}