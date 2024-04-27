//Q1. reverse a String Leetcode - 344

class Solution {
public:
    void reverseString(vector<char>& s) {
        //Approach 1 
        //Using a ans vector 
        //SC-O(n)

        //Aproach 2
        //Using two pointer 
        //SC-O(1)
        //TC- O(logn)
        int st = 0;
        int end = s.size()-1;
        while(st<=end){
            swap(s[st], s[end]);
            st++;
            end--;
        }

        //Brute force

        // for(int i=0;i<s.size()-1;i++){
        //     for(int j =s.size()-1 ; j>=0;j++){
        //         int temp = s[i];
        //         s[i] = s[j];
        //         s[j]= temp;
        //     }
        // }
    }
};