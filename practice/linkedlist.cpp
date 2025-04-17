#include<iostream> 
using namespace std;

class Node{
public:
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp  = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp  = new Node(data);
    tail->next = temp;
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

    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
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

void addTwoNumbers(Node* l1, Node* l2) {
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* temp1 = l1;
    Node* temp2 = l2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1) sum = sum + temp1->data;
        if(temp2) sum = sum + temp2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next  = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    print(dummyNode->next);
}


int main() {
    Node* node1 = new Node(3);
    Node* head1 = node1;
    Node* tail1 = node1;
    insertAtTail(tail1, 5);

    Node* node2 = new Node(4);
    Node* head2 = node2;
    Node* tail2 = node2;
    insertAtTail(tail2, 5);
    insertAtTail(tail2, 9);
    insertAtTail(tail2, 9);

    addTwoNumbers(head1, head2);

    return 0;
}
// int main(){
//     Node* node1 = new Node(10);
//     Node* head = node1;
//     Node* tail = node1;

//     insertAtHead(head, 15);
//     print(head);
//     insertAtHead(head, 14);
//     print(head);
//     insertAtHead(head, 12);
//     print(head);
//     insertAtTail(tail, 16);
//     print(head);
//     insertAtPosition(head, tail, 2, 13);
//     print(head);
//     deleteNode(head, 4);
//     print(head);
// }