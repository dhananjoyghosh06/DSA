//Q1. Rotate String 
//1st approach - Using queue
// TC- O(n)
//SC-O(N^2)

#include<bits/stdc++.h>
using namespace std;
bool solve(string s, string goal){
    if(s.length() != goal.length()) return false;
    
    // q1 push
    queue<int>q1;
    queue<int>q2;
    
    for(int i =0;i<s.length();i++){
        q1.push(s[i]);
        q2.push(goal[i]);
    }
    // rotate
    int k = 0;
    while(k<s.length()){
        char p = q1.front();
        q1.pop();
        q1.push(p);
        
        
        
        if(q1==q2) return true;
        
        k++;
    }
    
    return false;
    
}
int main(){
    string s, goal;
    cin>>s>>goal;
    
    cout<<solve(s,goal);
}

//Q2 > Method used - Concatenation method 
// TC- O(n)
//SC-O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
      if(s.length() != goal.length()) return false;
      //concatenate 
      s = s+s;
      //find method
      int idx = s.find(goal) ;
      //
      if(idx == -1 )  return false;

      return true
      ;
    }
}; 