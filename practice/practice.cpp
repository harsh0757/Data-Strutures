#include <iostream>
#include "../LinkedList/Singly Linked List/Questions/linkedListStructure.cpp"
using namespace std;

void addNumber(Node* head1, Node* head2) {
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummyNode = new Node(-1);
    int carry = 0;
    Node* curr = dummyNode;

    while(t1 != NULL || t2!= NULL){
        int sum = carry;
        if(t1) sum = sum + t1->data;
        if(t2) sum = sum + t2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
    }

}

int main(){

}