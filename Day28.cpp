
//Q1 Convert a sentence into its equivalent mobile numeric keypad sequence
//SC-O(26)-O(1)
//TC-O(N)
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends

#include<bits/stdc++.h>
string printSequence(string S)
{
    //code here.
    string arr[26] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    string ans ="";
    for(int i=0;i<S.length();i++){
        if(S[i] ==" ") ans+="0";
        else{
            int idx = S[i]-'A';
            ans+=arr[idx];
        }
    }
    return ans;
}

//Q2 - Count all palindromic subsequence in a given string (It can be more optimised when we will do DP )
//SC- O(N*N)
//TC- O()
class Solution {
    private:
    bool isPalindromic(string s, int st, int end){
        int n = s.length();
        while(st<end){
            if(s[st] != s[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    void subSequences(string s, vector<string>&ans, string temp, int i){
            if(i>=s.length()){
                if(temp.length()==5){
                    ans.push_back(temp);
                    return;
                }
                return ;
            }
            
            //exclude 
            subSequences(s,ans,temp, i+1);
            
            //include
            char st = s[i];
            temp.push_back(st);
            subSequences(s,ans,temp, i+1);
}
public:
    
    int countPalindromes(string s) {
        vector<string>ans;
        string temp ="";
        subSequences(s,ans,temp,0);
        long long count =0;
        for(int i=0;i<ans.size();i++){
            if(isPalindromic(ans[i],0,ans.size()-1)) count ++;
        }

        return count;
    }
};

// Q3  - Minimum number of bracket reversals needed to make an expression balanced (Typical Question , if you do not practice this type of question you cannot solve it anymore )
class Solution {
public:
    int minSwaps(string s) {
        if(s.empty()) return 0;
        int open = 0;
        int swaps =0;
        int end = s.length()-1;
        for(int i =0;i<s.length();i++){
            if(s[i] == '[') open ++;
            else open--;

            if(open<0){
                while(i<end && s[i]==']') end--;
                swap(s[i], s[end]);
                swaps++;
                open =1;

            }
           
        }
         return swaps;
    }
};