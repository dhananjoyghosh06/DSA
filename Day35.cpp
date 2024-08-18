//Q1. Sort a stack
//TC-O(n*n)
//SC-O(1)

#include <bits/stdc++.h> 
void sortElement(stack<int> &s, int num){
	if(s.empty() || s.top()<num){
		s.push(num);
		return;
	}

	int n= s.top();
	s.pop();
	sortElement(s,num);
	s.push(n);
}

void solve(stack<int> &s ){
	if(s.empty()){
		return ;
	}

	int num = s.top();
	s.pop();
	solve(s);
	
	sortElement(s,num);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	solve(stack);

}