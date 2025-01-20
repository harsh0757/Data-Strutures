#include<iostream>
#include<stack>
using namespace std;

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isBalanced(string s) {
    stack<char> st;
    for(int  i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        } else {
            if(st.empty()) return false; //if it's a closing bracket and stack is empty
            char ch = st.top();
            st.pop();
            if(isMatchingPair(ch, s[i])){
                continue;
            } else {
                return false;
            }
        }
    }
    return st.empty(); //stack should be empty if all brackets are matched
}

int main(){
    string str = "()[{}()]";
    // string str = "())";
    if(isBalanced(str)){
        cout<<"String is balanced"<<endl;
    } else {
        cout<<"String is not balanced"<<endl;
    }
}

// TC --> O(N)
// SC --> O(N)