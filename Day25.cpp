//Q1. Permutations of a string Leetcode - 567
//TC-O(M)+O(N)
//SC-O(26 * 26) - O(1)

class Solution {
    private:
    bool cheakEqual(vector<int>count1, vector<int>count2){
        for(int i =0;i<26;i++){
            if(count1[i]!=count2[i]) return 0;
        }
        return 1;
    }
    public:
    bool checkInclusion(string s1, string s2) {
        vector<int>count1(26,0);
        for(auto it:s1){
            int idx = it-'a';
            count1[idx]++;
        }

        int i =0;
        vector<int>count2(26,0);
        int windowSize = s1.length();
        //1st window process 
        while(i<windowSize && i<s2.length()){
            int idx = s2[i]-'a';
            count2[idx]++;
            i++;
        }

        if(cheakEqual(count1,count2)) return 1;

        //rest of the window 

        while(i<s2.length()){
            int idx = s2[i]-'a';
            count2[idx]++;
            int oldChar = s2[i-windowSize]-'a';
            count2[oldChar]--;

            i++;
            if(cheakEqual(count1,count2)) return 1;
        }
         return 0;
    }
};