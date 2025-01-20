#include<iostream>
#include<stack>

using namespace std;

bool operand(char c){
    if((c>= 'A' && c<='Z') || (c>= 'a' && c<='z') || (c>= '0' && c<='9')) {
        return true;
    }
    return false;
}

void postfixToPrefix(string s){
    stack<string> st;
    string ans;
    int i=0;
    while(i<s.length()){  //O(n)
    //if it is operand
        if(operand(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conString = s[i] + t2 +  t1;  //O(N1 + N2)
            st.push(conString);
        }
        i++;
    }
    cout<<st.top()<<endl;
}

int main(){
    string str = "AB-DE+F*/";
    postfixToPrefix(str);
}