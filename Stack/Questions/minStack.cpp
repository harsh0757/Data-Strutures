#include<iostream>
#include<stack>

using namespace std;

class minStack{
//  stack<pair<value, min>> st; defined like this
    stack<pair<int, int>> st;
public:
    void push(int value){
        if(st.empty()){
            st.push({value, value});
        } else {
            st.push({value, min(value, st.top().second)});
        }
    }

    void getMin(){
        if (!st.empty()) {
            cout << st.top().second << endl; // Print the second element of the top pair (min)
        } else {
            cout << "Stack is empty!" << endl;
        }
    }
};

int main(){
    minStack obj;
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(8);
    obj.getMin();
}