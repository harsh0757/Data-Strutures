#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int d) : data(d), next(NULL), prev(NULL) { }
}; 

Node* findTail(Node* tail){
    Node* temp = tail;
    while(temp->next != NULL) temp = temp->next;
    return temp;
}

vector<pair<int, int>> findPairswithSum(Node* head, int target){
    vector<pair<int, int>> ans;
    Node* left = head;
    Node* right = findTail(head);
    
    if(head == NULL) return ans;
    
    while(left->data < right->data){
        if(left->data + right->data == target){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if(left->data + right->data < target){
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    return ans;
}

Node* deleteOcc(Node* head, int key){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            if(temp == head) head = head->next;
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            
            if(nextNode) nextNode->prev = prevNode;
            if(prevNode) prevNode->next = nextNode;
            
            delete temp;
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Manually build sorted doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->prev = n1; n2->next = n3;
    n3->prev = n2; n3->next = n4;
    n4->prev = n3; n4->next = n5;
    n5->prev = n4;

    Node* head = n1;

    int sum = 6; // target sum
    auto pairs = findPairswithSum(head, sum);

    cout << "Pairs with sum " << sum << ":\n";
    if (pairs.empty()) {
        cout << "No pairs found\n";
    } else {
        for (auto &p : pairs) cout << "(" << p.first << ", " << p.second << ")\n";
    }

    // cleanup nodes (no cycle, safe to delete)
    delete n1; delete n2; delete n3; delete n4; delete n5;
    return 0;
}
