#include <iostream>
#include "linkedListStructure.cpp"
using namespace std;

void addLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;

    while(t1 != NULL || t2 != NULL){
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    print(dummyNode->next);
}

int main() {
    Node* node1 = new Node(3);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAtTail(tail1, 5);

    Node* node3 = new Node(4);
    Node* head2 = node3;
    Node* tail2 = node3;
    insertAtTail(tail2, 5);
    insertAtTail(tail2, 9);
    insertAtTail(tail2, 9);

    addLL(head1, head2);

    return 0;
}