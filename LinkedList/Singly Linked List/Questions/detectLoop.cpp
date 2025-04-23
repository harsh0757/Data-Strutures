#include <iostream>
#include<map>
#include "linkedListStructure.cpp"

using namespace std;

bool detectLoop(Node* head){
    map<Node*, int> mpp;
    Node* temp = head;

    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
    }
}

int main(){
}