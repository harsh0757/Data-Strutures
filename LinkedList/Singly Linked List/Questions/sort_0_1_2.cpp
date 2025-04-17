#include <iostream>
#include "linkedListStructure.cpp"
using namespace std;

void optimised(Node* head){
    Node* temp = head;
    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);

    Node* zero = zerohead;
    Node* one = onehead;
    Node* two = twohead;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next; 
        } else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (onehead->next) ? onehead->next : twohead->next;
    one->next = twohead->next; 
    two->next = NULL;

    print(zerohead->next); 
    delete zerohead;
    delete onehead;
    delete twohead; 
}

void sort_0_1_2(Node *head)
{
    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;

        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    print(head);
}

int main()
{
    Node* node1 = new Node(0);
    Node* head = node1;

    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    print(head);
    sort_0_1_2(head);
}