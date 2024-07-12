Q1. Reverse a string using stack 
//TC-O(n)
//SC-O(n)

#include <iostream>
#include<stack>
#include<string>
using namespace std;

void revereseString(string &s)
{
    stack<char>st;
    for(char ch : s){
        st.push(ch);
    }
    
    for(int i=0;i<s.length();i++){
        s[i]=st.top();
        st.pop();
    }
    
   
}
int main() {
   string s ="hello";
   revereseString(s);
   
   cout<<s;

    return 0;
}

//Q2. Delete middle element from a stack 
//TC- O(logn)
//SC-O(1)

#include <bits/stdc++.h> 

void solve(stack<int>&s, int N,int count){
   if(count == (N/2)){
      s.pop();
      return ;
   }

   int ele = s.top();
   s.pop();
   solve(s,N,count+1);
   s.push(ele);
}
void deleteMiddle(stack<int>&s, int N){
	
   // Write your code here
   int count =0;

   solve(s, N, count);

}

//Q3. Valid Parenthesis
//TC-O(n)
//SC-O(n)

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        if(n<2) return false;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(s[i]==')'&& !st.empty() && st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}'&& !st.empty()&& st.top()=='{'){
                     st.pop();
                }
                 else if(s[i]==']'&& !st.empty() && st.top()=='['){
                     st.pop();
                }
             else return false;
            }

            
        }
        if(!st.empty()) return false;
            else return true;
    }
};

//Q4. Insert an element at its Bottom in a given stack
//TC-O(n)
//SC-O(1)

#include <bits/stdc++.h> 

void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    
    solve(myStack,x);

    return myStack;
}

//Q5. Reverse a stack using recursion 
//TC-O(n*n)
//SC-O(1)
void insertAtBottom(stack<int> &st, int num){

    //base case
    if(st.empty()){
        st.push(num);
        return;
    }

    int val = st.top();
    st.pop();
    //recursion
    insertAtBottom(st,num);
    st.push(val);
}

void solve(stack<int> &st)
{
    //base case
    if(st.empty()) {
        return;
    }
    // in hand
    int num = st.top();
    st.pop();
    //recursion
    solve(st);
    //insert at bottom 
    insertAtBottom(st,num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    solve(stack);
}



