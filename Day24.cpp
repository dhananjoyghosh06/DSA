Q1. Reverse a word 
i/p- "My Name is Dhananjoy"
o/p- "Dhananjoy is Name My";

#include<bits/stdc++.h>
using namespace std;
void reverseS(string s, vector<string>&ans){
    string temp = "";
    for(int i=0;i<=s.length();i++){
        if(s[i]==' ' || s[i]=='\0'){
            ans.push_back(temp);
            temp="";
        }
        temp.push_back(s[i]);
    }
}
int main(){
    string s = "My name is Dhananjoy";
    vector<string>ans ;
    reverseS(s,ans);
    
    reverse(ans.begin(), ans.end());
    
    for(auto it : ans) cout<<it<<" ";
    
    
    return 0;
}
