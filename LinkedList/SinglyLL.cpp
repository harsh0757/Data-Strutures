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
}