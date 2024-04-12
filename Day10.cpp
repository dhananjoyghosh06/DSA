#include <bits/stdc++.h>
void helper(string str, vector<string>&ans, string op, int i)
{
	 if(i == str.length()){
		 if(op.length() >0){
			 ans.push_back(op);
			 return;
		 }
		 return;
	 }

	 //exclude 
	 helper(str, ans , op, i+1);

	 //include
	 op.push_back(str[i]);
	 helper(str,ans,op,i+1);
} 

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string>ans;
	string op = "";
	helper(str, ans, op, 0);

	return ans;
	
}
