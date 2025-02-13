#include <iostream>
#include "linkedListStructure.cpp"
using namespace std;

Node* reverseLL(Node* &head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead  = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
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
    head = reverseLL(head);
    print(head);
}