#include<iostream>
#include<stack>
using namespace std;

class Node{
public: 
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* reverseLL_BE(Node* &head){
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* front = curr->next;

        curr->next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

Node* reverseLL(Node* &head){
    Node* temp = head;

    stack<int> st;

    while(temp != nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != nullptr){
        temp->data = st.top();

        st.pop();

        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    // Insert at tail
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);

    // Insert at head
    insertAtHead(head, 5);
    insertAtHead(head, 2);

    // Print the list
    printList(head);
    head = reverseLL_BE(head);
    printList(head);

    return 0;
}