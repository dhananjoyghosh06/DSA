// Longest Palindromic Substring ( Leetcode - 5)
//Method used - Binary Search 
//TC- O(n*n)
//SC-O(n)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans ="";
        //Odd length
        for(int i=0;i<n;i++){
            int prev =i-1;  
        int next = i+1;
        while(prev>=0 && next<n && s[prev] == s[next]){
            prev--;
            next++;
        }
        if(ans.length()<next-prev-1)
        {
            ans =s.substr(prev+1, next-prev-1);
        }

        //Even 
        prev = i;
        next = i+1;

        while(prev>=0 && next<n && s[next]==s[prev]){
            prev--;
            next++;
        }
        if(next-prev-1 >ans.size()){
            ans = s.substr(prev+1, next-prev-1);
        }
 } 
        

        return ans;
    }
};