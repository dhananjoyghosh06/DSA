//Print all the subsecuences of a string
#include <bits/stdc++.h>
using namespace std;
void recursionF(string s, string temp, vector<string>&ans, int index){
    // base case 
    if(index>= s.length()) {
        ans.push_back(temp);
        return ;
    }
    
    //exclude
    recursionF(s,temp,ans,index+1);
    // include 
    temp.push_back(s[index]);
    recursionF(s,temp,ans,index+1);
}
vector<string>subsecuences(string s){
    vector<string>ans;
    string temp ="";
    int index = 0;
    recursionF(s,temp,ans,index);
    
    return ans;
}
int main() {
    string s = "abc";
    vector<string>ans ;
    ans = subsecuences(s);
    
    for(auto it:ans ) cout<<it<<endl;
    
}

//Q2. Print all the permutations of a string 

#include <bits/stdc++.h>
using namespace std;
void solve (vector<string>&ans, string s, int index){
    if(index>=s.length()){
        ans.push_back(s);
        return ;
    }
    
    // 
    for(int i=index;i<s.length();i++){
        swap(s[i],s[index]);
        ans.push_back(s);
        swap(s[i],s[index]);
    }
    
    
}
vector<string>permute(string s){
    vector<string>ans;
    int index =0;
    solve(ans , s, index);
    
    return ans;
}
int main() {
    string s = "abc";
    vector<string>ans ;
    ans = permute(s);
    
    for(auto it:ans ) cout<<it<<endl;
    
}

//Q3 - split the binary string into two substring with equal 0's and 1's
#include<bits/stdc++.h>
using namespace std;
int functionCount(string s){
    int countOfZeros = 0;
    int countOfOnes = 0;
    int count = 0;
    
    for(int i =0;i<s.length();i++){
        if(s[i]=='0') countOfZeros++;
        else countOfOnes++;
        if(countOfZeros == countOfOnes ) count++;
        
    }
    if(countOfOnes != countOfZeros) return -1;
    
    return count ;
}
int main()
{
    string str = "0111100010";
    cout<< functionCount(str)<<endl;
    
}