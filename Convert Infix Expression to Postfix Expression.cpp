/*
  Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.
  Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
  Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

  Solution- Follow the below stpes
  1. Scan the characters of infix string until no more characters are left. Create an empty stack and follow the below steps for 
  each character in the string-
    1. If the current character is an operand(note - in this question we assume only alphabets as operand) then print it.
    2. Else if the current character is closing parenthesis ')' then print and pop the characters on top of the stack until. 
    opening parenthesis is encountered. Discard both the parenthesis, i.e. pop the opening parenthesis(and do not print it) and 
    ignore the closing parenthesis.
    3. Else if the stack is empty or the current character is opening parenthesis '(' or if the priority of the current character
    is greater than the character on top then push the current character into the stack.
    4. Finally keep printing and popping the top character in the stack till the priority of this top character is greater than
    or equal to the priority of the current character.
    
 2. When all the characters in the infix expression string have been scanned, print the content of the stack by repeated printing
 of the top element(character) and popping the stack till it becomes empty.
 
 3. ^ has the highest priority, * and / have the second highest priority, + and - have the third highest priority and ( has the 
 smallest priority.
*/

#include<bits/stdc++.h>
using namespace std;

// A utility function to get the priority of a operator
int priority(char c) {
    if(c == '^')
        return 3;
    if(c == '*' or c == '/')
        return 2;
    if(c == '+' or c == '-')
        return 1;
    return 0;
}

void solve() {
    string str;
    cin >> str;
    
    stack<char> st;
    
    for(auto c : str) {
        if(isalpha(c))
            cout << c;
        
        else if(st.empty() or c == '(' or priority(st.top()) < priority(c))
            st.push(c);
        
        else if(c == ')') {
            while(st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        
        else {
            while(!st.empty() and priority(st.top()) >= priority(c)) {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main() {
	int test;
	cin >> test;
	
	while(test--)
	    solve();
	return 0;
}
