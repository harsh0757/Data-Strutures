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

void insertAtPosition(){

}

void print(DNode* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    DNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
    }
}

int main(){
    
}