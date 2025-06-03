#include<iostream>
#include<unordered_map>
#include "/Users/harshchanana/Data-Strutures/LinkedList/Singly Linked List/Questions/linkedListStructure.cpp"

using namespace std;

Node* optimalstartingPoint(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;

            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

Node* startingPoint(Node* &head){
    unordered_map<Node*, int> mpp;
    Node* temp = head;

    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return NULL;
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

    // Detecting starting point of the cycle
    Node* cycleStart = optimalstartingPoint(head);

    if(cycleStart != NULL) {
        cout << "Cycle detected at node with data: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
