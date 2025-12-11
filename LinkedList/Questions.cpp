#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int d) : data(d), next(NULL){}
};

//Q13 find the starting point of the loop in linked list 
Node* startPoint(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow){
            slow = head;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        } 
    }
    return NULL;
}

//Q12 Delete the middle node of linked list optimal approach
Node* deleteMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    
    while(fast != NULL &&fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = NULL;
    delete slow;
    return head;
}

//Q11 find the Length of the loop in linked list brute and optimal
int loopLength_op(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            int Length = 1;
            fast = fast->next; //start from one ahead
            
            while(fast != slow){
                fast = fast->next;
                Length++;
            }
            return Length;
        }
    }
    return 0;
}

int loopLength(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    int timer = 1;
    
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return timer - value;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

//Q10 detect the cycle in the linked list brute and optimal
bool detectCycle_op(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) return true;
    }
    return false;
}

bool detectCycle(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;
    
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// Q9 Find the middle of the linked list brute and optimal
Node* middle_op(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Q9 Find the middle of the linked list
Node* middle(Node* head){
    Node* temp = head;
    int count = 0;
    
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    
    temp = head;
    int middleNode = (count / 2) + 1;
    
    while(--middleNode){
        temp = temp->next;
    }
    return temp;
}

//Q8 Get the intersection point of Y linked list 2 methods
Node* getIntersectionNode_op(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    
    if(head1 == NULL || head2 == NULL) return NULL;
    
    while(t1 != t2){
        t1 = t1->next;
        t2 = t2->next;
        
        if(t1 == t2) return t1;
        
        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
    }
    return t1;
}

Node* getIntersectionNode(Node* head1, Node* head2){
    map<Node*, int> mpp;
    Node* temp = head1;
    
    while(temp != NULL){
        mpp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()) return temp;
        temp = temp->next;
    }
    return NULL;
}

//Q7 add one to a linked list 0 <= list[i] <= 9
int helper(Node* head){
    if(head == NULL) return 1;
    
    int carry = helper(head->next);
    int sum = head->data + carry;
    
    head->data = sum % 10;
    return sum / 10;
}

Node* add1ToLL(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

//Q6 reverse the given linked list and return the new Head
Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        Node* frontNode = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = curr->next;
        curr = frontNode;
    }
    return prev;
}

// Q5 if the linked list is a valid Palidrome
bool isPalidrome(Node* head){
    if(head == NULL || head->next == NULL) return true;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    
    while(second != NULL){
        if(first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

// Q4 remove the nth node from the end of linked lit
Node* removeNthNodefromEnd(Node* head, int n){
    Node* fast = head;
    Node* slow = head;
    
    for(int i=0;i<n;i++) fast = fast->next;
    
    if(fast == NULL){
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    
    return head;
}
//Q3 sort 0 1 2 in linked list
Node* sort_0_1_2(Node* head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zero = zeroHead;
    Node* one =  oneHead;
    Node* two = twoHead;
    
    Node* temp = head;
    
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        } else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    zero->next = (oneHead->next) ? oneHead->next :twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    
    Node* newHead = zeroHead->next;
    
    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

//add int main to run the code
