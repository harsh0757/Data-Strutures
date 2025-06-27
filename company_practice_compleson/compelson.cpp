#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;
    
    Node(int d) : data(d), next(NULL){}
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

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

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
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


bool detectCycle(Node* &head){
    if(head == NULL && head->next == NULL) return head;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

Node* reverseLL(Node* &head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    head = prev;
    return head;
}

// int main(){
//     Node* node1 = new Node(6);
//     Node* head = node1;
//     insertAtHead(head, 5);
//     insertAtHead(head, 2);
//     insertAtHead(head, 4);
//     insertAtHead(head, 3);
//     insertAtHead(head, 1);
//     print(head);
//     reverseLL(head);
//     print(head);
// }

int main() {
    // Create a sample linked list
    // with a loop for testing
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    // fifth->next = third; 

    // Check if there is a loop 
    // n the linked list
    if (detectCycle(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    int rows = 3, col = 3;
    int **arr = new int*[rows];
    for(int i = 0;i<rows;i++){
        arr[i] = new int[col];
    }
}