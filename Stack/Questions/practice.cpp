#include <bits/stdc++.h>

using namespace std;

// L4 Implement min stack 
//push, pop, top, getMin, size
//if we do getMin operation normally it will increase the time complexity comparing all numbers in stack
// so we can store pairs in stack like : pair<int, int> val, min seen till now
class minStack{
    //TC --> O(1) SC --> O(2N)
    stack<pair<int, int>> st;
public:
    void push(int val){
        if(st.empty()) st.push({val, val});
        else st.push({val, min(val, st.top().second)});
    }
    
    void getMin(){
        if (!st.empty()) {
            cout << st.top().second << endl; // Print the second element of the top pair (min)
        } else {
            cout << "Stack is empty!" << endl;
        }
    }
    
    int top(){
        return st.top().first;
    }
};


// Lecture 2 
// prefix, infix, postfix
// priority order of operator ^, * /, + - --> 3, 2 , 1 anything apart from this has a least priority

//infix --> (p + q) * (m - n) --> most common in programming language
//prefix --> * + pq - mn  used in tree data structure
//postfix --> pq + mn -*  used in stack based calculator

// a + b * (c ^ d - e)
//approach
//if it is operand i will add it to the answer
//and on operator and i will put it into the stack and answer stays as same
//if the operator has lesser priority than the stack top element them we will pop the operator from stack
//and add it to the answer
//and for the closing bracket take out everthing from stack until you get opening bracket

int priority(char ch){
    if(ch == '^') return 3;
    else if (ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else return -1;
}

string infixToPostfix(string s) {
    // TC --> O(N) + O(N)
    // SC --> O(N) + O(N)
    int i = 0;
    stack < char > st;
    string ans = "";

    while (i < s.length()) {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); //pop out the opening bracket
        } else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]); //push the current element in the stack
        }
        i++;
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

//approach
//I am looking for last opening encountered
//preserve the opening brackets and should be able to see last one
//stack will preserve last opening as it follows Last in first out principle

bool balanceParantheses(string s) {
    // TC --> O(N) SC --> O(N)
    stack < char > st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) return false;
            char ch = st.top();
            st.pop();

            if (s[i] == ')' && ch == '(' ||
                s[i] == '}' && ch == '{' ||
                s[i] == ']' && ch == '[') {
                continue;
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    // your code goes here
    string str1 = "()[{}()]";
    string str2 = "()[{}(])";
    if (balanceParantheses(str2)) {
        cout << "Parantheses are balanced " << endl;
    } else {
        cout << "Parantheses are not balanced" << endl;
    }
    
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix expression: " << exp << endl;
    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    
    minStack obj;
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(8);
    obj.getMin();
    
    return 0;
}
