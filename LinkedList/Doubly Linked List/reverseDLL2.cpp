#include<iostream>
#include<stack>
#include "DLLStructure.cpp"
using namespace std;

void reverseDLL(Node* &head){
     Node* curr = head;   
     Node* last = NULL;   
     while(curr != NULL){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }
    head = last->prev;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtTail(tail, 11);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);
    insertAtPosition(head, tail, 6, 12);
    // deleteNode(head, 8);
    print(head);
    reverseDLL(head);
    print(head);
}