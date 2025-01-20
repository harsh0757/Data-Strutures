#include<iostream>
#include<stack>

using namespace std;

bool operand(char c){
    if((c>= 'A' && c<='Z') || (c>= 'a' && c<='z') || (c>= '0' && c<='9')) {
        return true;
    }
    return false;
}

void postFixToInfix(string s){
    stack<string> st;
    string ans;
    int i=0;
    while(i<s.size()){  //O(n)
    //if it is operand
        if(operand(s[i])) st.push(string(1, s[i]));  //st.push(string(1, s[i])); converts the character s[i] to a string of length 1 and
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conString = '(' + t2 + s[i] + t1 + ')';
            st.push(conString);
        }
        i++;
    }
    cout<<st.top()<<endl;
}

int main(){
    string str = "AB-DE+F*/";
    postFixToInfix(str);
}