//Q1. Longest common Prefix (Brute force approach)
//TC- O(m*n)
//SC-O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string ans = "";
        for(int i=0;i<strs[0].size();i++){
            char ch = strs[0][i];
            bool match = true;
           
            for(int j=1;j<strs.size();j++){
                if(strs[j].size() < i || ch!= strs[j][i]){
                    match= false;
                    break;
                }
            }
            if(match == false) break;
            else ans +=ch;
        }
        return ans;
    }
};

// Trie Approach



