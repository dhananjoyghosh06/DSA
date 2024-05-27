//  Q1 Find next greater number with same set of digits 

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    void solve(string s, vector<int>&ans, int index){
        if(index>=s.length()){
            ans.push_back(stoi(s));
            return ;
        }
        
        for(int i = index; i<s.length();i++){
            
                swap(s[i], s[index]);
                solve(s,ans,index+1);
                swap(s[i],s[index]);
            
        }
        
    }
    int findNext (int N) 
    {
        //code here.
        string s = to_string(N);
        vector<int>ans;
        solve(s,ans,0);
        int mini = INT_MAX;
        for(auto it:ans){
            if(it>N) {
                mini=min(it,mini);
            }
        }
        if(mini!=INT_MAX) return mini;
        else return -1;
        
    }  
};

//{ Driver Code Starts.
int main()
{
		int n; cin >> n;
		Solution ob;
		int res = ob.findNext (n);
		cout<<res<<endl;
	
}
// } Driver Code Ends