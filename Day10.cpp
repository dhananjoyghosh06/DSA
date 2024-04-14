//Subsequesnces of a string
//Method used - Recursion 
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
//Mobile keypad number letter combinations 
//Method used - Recursion + Backtracking
class Solution {
public:
    void getAns(string digits, vector<string>&ans,string op, string mapp[], int i ){
        if(i>=digits.length()){
            ans.push_back(op);
            return ;
        }
        //find the i'th number
        int number = digits[i]-'0';
        //find the map value corresponding to the mapp
        string value = mapp[number];
        //traverse the value
        for(int j=0;j<value.length();j++){
            op.push_back(value[j]);
            getAns(digits, ans, op, mapp, i+1);
            op.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string op = "";
        string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        getAns(digits, ans, op, mapp, 0);

        return ans;
    }
};
