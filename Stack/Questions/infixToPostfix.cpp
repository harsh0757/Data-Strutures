#include<iostream>
#include<stack>
using namespace std;

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

string infixToPostfix(string s){
    stack<char> st;
    string ans;
    int i=0;
    while(i<s.size()){  //O(n)
    //if it is operand
        if((s[i] >= 'A' && s[i]<='Z') ||
          (s[i] >= 'a' && s[i]<='z') ||
          (s[i] >= '0' && s[i]<='9')) ans += s[i];
          else if(s[i] == '(') st.push(s[i]); 
          else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
              ans += st.top();
              st.pop();
            }
            st.pop(); //pop out the opening bracket
          } else {  //O(1)
            while(!st.empty() && priority(s[i]) <= priority(st.top())){ //O(n)
              ans += st.top();
              st.pop();
            }
            st.push(s[i]);
          }
        i++;
    }
    while(!st.empty()){ //O(n)
      ans = ans + st.top();
      st.pop();
    }
    return ans;
}

int main(){
        //outer  //inner  stack      ans variable
  // TC--> O(N) + O(N)  SC-->O(N) + O(N)
  string str = "a+b*(c^d-e)";
  cout<<"Converting to Postfix...\n"<<infixToPostfix(str)<<endl;
}