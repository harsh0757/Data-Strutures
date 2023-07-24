#include<iostream>
using namespace std;

class DNode{
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~DNode(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(DNode* &head, int data){
    DNode* temp =  new DNode(data);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(DNode* &tail, int data){
    DNode* temp = new DNode(data);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(DNode* &head, DNode* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    DNode* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        InsertAtTail(tail,data);
        return;
    }

    DNode* NodeToInsert = new DNode(data);
    NodeToInsert->next = temp->next;
    temp->next->prev = NodeToInsert;
    temp->next = NodeToInsert;
    NodeToInsert->prev = temp;
}

void Delete(int position, DNode* &head){
    if(position == 1){
        DNode* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    DNode* curr = head;
    DNode* prev = NULL;

    int count = 1;
    if(count < position){
        prev = curr;
        curr = curr->next;
        count++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next->prev = prev;
    curr->next = NULL;

    delete curr;
}

void print(DNode* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    DNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    DNode* node1 = new DNode(10);
    DNode* head = node1;
    DNode* tail = node1;

    insertAtHead(head,20);
    print(head);
    InsertAtTail(tail,30);
    print(head);
    insertAtPosition(head,tail,4,40);
    print(head);

}