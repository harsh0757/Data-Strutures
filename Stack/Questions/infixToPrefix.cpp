#include<iostream>
#include<stack>
using namespace std;
//pending

bool operand(char c){
    if((c>= 'A' && c<='Z') || (c>= 'a' && c<='z') || (c>= '0' && c<='9')) {
        return true;
    }
    return false;
}

string swapBrackets(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }
    return s;
}

string reverseString(string s){
    string reversed = "";
    for(int i = s.length() - 1; i >= 0; i--){
        reversed += s[i];
    }
    return reversed;
}

int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return -1;  // Default for non-operators
}

string infixToPrefix(string s){
    stack<char> st;
    string ans = "";
    int i = 0;

    s = reverseString(s);
    s = swapBrackets(s);
    while(i<s.length()) {
        if(operand(s[i])) ans += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() && st.top() !='('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); 
        } else {
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            } else {
                    while(!st.empty() && priority(s[i]) <= st.top()){
                        ans += st.top();
                        st.pop();
                    }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        if(!st.empty()) st.pop(); 
    }
    return reverseString(ans);
}

int main(){
    string s = "(a+b)*c-d+f";
    cout<<"Converting To prefix ... "<<infixToPrefix(s)<<endl;
    return 0;
}