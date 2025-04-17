#include <iostream>
#include "linkedListStructure.cpp"
using namespace std;

void optimised(Node* head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    print(head);
}

void oddEvenLL(Node* &head){
    vector<int> v;
    Node* temp = head;
    if(head == NULL || head->next == NULL) return;

    while(temp != NULL && temp->next != NULL){
        v.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) v.push_back(temp->data);

    temp = head->next;
    while (temp != NULL && temp->next != NULL){
        v.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) v.push_back(temp->data);

    int i=0;
    temp = head;

    while(temp != NULL){
        temp->data= v[i];
        i++;
        temp = temp->next;
    }
    print(head);
}

int main(){
    Node* node1 = new Node(6);
    Node* head = node1;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    print(head);
    oddEvenLL(head);
}