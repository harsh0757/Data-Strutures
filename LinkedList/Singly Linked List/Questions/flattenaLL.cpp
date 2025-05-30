#include<iostream>
#include <vector>
#include <algorithm>
#include "/workspaces/Data-Strutures/LinkedList/Singly Linked List/Questions/linkedListStructure.cpp"
using namespace std;


//optimised --> O(n1 + n2)
Node* merge2Lists(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->bottom  = list1;
            res = list1;
            list1 = list1->bottom;
        } else {
            res->bottom = list2;
            res= list2;
            list2 = list2->bottom;
        }
        res->next = NULL;
    }

    if(list1) res->bottom = list1;
    else res->bottom = list2;

    return dummyNode->bottom;
}

//for multiple lists
Node* optimised(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* mergedhead = optimised(head->next);
    return merge2Lists(head, mergedhead);
}

//brute force
// 1. add the LL to an array
// 2. Sort the array 
// 3. convert to vertical linked list

void printFlattenedLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}


Node* convertArrToLL(vector<int> arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->bottom = newNode;
        temp = temp->bottom;
    }
    return head;
}

Node* flattenLL(Node* head){
    vector<int> arr;
    Node* temp = head;

    while(temp != NULL){
        Node* t2 = temp;
        while(t2 != NULL){
            arr.push_back(t2->data);
            t2 = t2->bottom;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    return convertArrToLL
    (arr);
}

int main() {
    // Create a linked list with bottom pointers
    Node* head = new Node(5);
    head->bottom = new Node(14);

    head->next = new Node(10);
    head->next->bottom = new Node(11);  // Fix 4 -> 11

    head->next->next = new Node(12);
    head->next->next->bottom = new Node(13);  // 13 < 20
    head->next->next->bottom->bottom = new Node(20);

    head->next->next->next = new Node(7);
    head->next->next->next->bottom = new Node(17);

    // Flatten the linked list
    // and print the flattened list
    Node* flattened = optimised(head);
    cout << "\nFlattened linked list: ";
    printFlattenedLL(flattened);

    return 0;
}