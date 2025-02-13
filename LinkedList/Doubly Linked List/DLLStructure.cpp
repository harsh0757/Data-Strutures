#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
            this->prev = NULL;
            delete next;
        }
        cout<<"Memory is free from the node for : "<<value<<endl;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) { 
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp == NULL){
        insertAtTail(tail, data);
        return;
    }
    
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = nodeToInsert;
    }
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, int position){
    if(head == NULL){
        cout<<"List is empty. I have saved you from segmentation fault"<<endl;
        return;
    }
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if(curr->next != NULL){
            curr->next->prev = prev;
        }
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}