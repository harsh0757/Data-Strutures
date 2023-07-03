#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

//constructor
    Node(int data){
        this->data = data;
        this->next = NULL;  
    }
//destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;   
        }
        cout<<"Memory is free for node with data "<<value <<endl;
    }
};

void insertAtStart(int data, Node* &start){
    //create new node;
    Node* temp = new Node(data);

    temp->next = start;
    start = temp;    
}

void insertAtLast(int data, Node* &last){
    Node* temp = new Node(data);
    last->next = temp;
    last = temp;
}


void insertAtPosition(Node* &start, Node* last, int position, int data){
    if(position == 1){
        insertAtStart(data,start);
        return;
    }

     Node* temp = start;
     int count = 1;

     while(count < position - 1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtLast(data,last);
        return;
    }

    //create a node
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* start){
//deleting start node
    if(position == 1){
        Node* temp = start;
        start = start->next;
        temp->next = NULL;
        delete temp;
    }

//deleting middle and last node
     Node* curr = start;
     Node* prev = NULL;

     int count = 1;
     while(count < position){
        prev = curr;
        curr = curr->next;
        count++;
     }

     prev->next = curr->next;
     curr->next = NULL;
     delete curr;
}

void print(Node* &start){
    if(start == NULL){
        cout<<"List is Empty"<<endl;
        return;
    }

    Node* temp = start;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node* start = node1;
    Node* last = node1;
    print(start);
    insertAtStart(5,start);
    print(start);
    insertAtLast(15,last);
    print(start);
    insertAtPosition(start, last, 4, 8);
    print(start);
    deleteNode(4,start);
    print(start);
    deleteNode(2,start);
    print(start);
}