//Q1. Append Characters to String to Make Subsequence (Leetcode - 2486)
// Time Conplexity = O(n1+n2);
//SC- O(1);

class Solution {
public:
    int appendCharacters(string s, string t) {
        int count1= 0;
        int count2=0;

        while(count1<s.length() && count2<t.length()){
            if(s[count1] == t[count2]){
                count2++;
            }
            count1++;
        }
        return t.length()-count2;
    }
};