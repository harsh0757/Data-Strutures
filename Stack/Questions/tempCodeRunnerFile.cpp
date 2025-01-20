#include<iostream>
#include<stack>
#include <queue>
using namespace std;

string infixToPostfix(string s){
    stack<char> st;
    string ans = "";
    int i=0;
    while(i<s.size()){
    //if it is operand
        if((s[i] >= 'A' && s[i]<='Z') ||
          (s[i] >= 'a' && s[i]<='z') ||
          (s[i] >= '0' && s[i]<='9')) {
            ans += s[i];
          } else if(s[i] == '('){
            st.push(s[i]);
          } else if(s[i] == ')'){
            while(st.empty() && st.top() != '('){
              ans += st.top();
              st.pop();
            }
            st.pop() //pop out the opening bracket
          } else {
            while(st.empty() && priority(s[i]) <= priority(st.top())){
              ans += st.top();
              st.pop();
            }
            st.push(s[i]);
          }
    }
    i++;
    while(!st.empty()){
      ans = ans + st.top();
      st.pop();
    }
    return ans;
}

int main(){
  string str = "a+b*(c^d-e)";
  cout<<"Converting to Postfix...\n"<<infixToPostfix(str)<<endl;
}