//Q1. Reverse a string at O(1) space complexity

//1st Approach- Method used : Two pointer 
//TC- (O(log(n)))
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st =0 ;
        int end = s.size()-1;
        while (st<end){
            swap(s[st],s[end]);
            st++;
            end--;
        }
    }
};

//2nd approach - method used - Recursion 

class Solution {
public:
    void recursive (vector<char>& s, int st, int end){
        if(st>end) return ;
        swap(s[st], s[end]);
        st++;
        end--;
        recursive(s, st, end);
    }
    void reverseString(vector<char>& s) {
        int st =0 ;
        int end = s.size()-1;
        recursive(s,st,end);
    }
};
