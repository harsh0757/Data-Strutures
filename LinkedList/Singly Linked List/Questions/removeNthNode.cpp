#include <iostream>
#include "linkedListStructure.cpp"
using namespace std;

void optimised(Node* &head, int N){
    Node* fast = head;
    Node* slow  = head;
    
    for(int i=0;i<N;i++) {
        fast = fast->next;

        if(fast == NULL){
            print(head->next);
            return;
        }
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    print(head);
}

void removeNthNode(Node* &head, int N){
    Node* temp = head;
    int cnt = 0;

    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }

    if(cnt == N) {
        Node* newhead = head;
        head = head->next;
        delete newhead;
        print(head);
        return;
    }
    temp = head;
    int res = cnt - N - 1;

    while(res){
        temp = temp->next;
        res--;
    }
    Node* delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;
    print(head);
}

int main()
{
    Node* node1 = new Node(6);
    Node* head = node1;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    optimised(head, 6);
}