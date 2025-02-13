#include<iostream>
#include<stack>
#include "DLLStructure.cpp"
using namespace std;

void reverseDLL(Node* &head){
    Node* temp = head;
    stack<int> s;

    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
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