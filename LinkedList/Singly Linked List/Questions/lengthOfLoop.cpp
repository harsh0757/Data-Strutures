#include<iostream>
#include<unordered_map>
#include "/Users/harshchanana/Data-Strutures/LinkedList/Singly Linked List/Questions/linkedListStructure.cpp"

using namespace std;

int lengthOfLoop(Node* &head){
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a cycle: fifth -> third
    fifth->next = third;

    // Finding length of the loop
    int len = lengthOfLoop(head);

    if (len > 0) {
        cout << "Cycle detected. Length of the loop: " << len << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
