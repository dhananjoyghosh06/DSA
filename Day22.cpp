Q1.  Count ans Say Problem 
// Q was given , Given an integer N return the sequence as n 
//The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//countAndSay(1) = "1"
//countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.

//What I did -- 

// Initialise an empty string and call the recursive function n-1 times 
// store ans with the returned value 

//In the recursive function , Base case will be if n ==0 return "1";
//If not then traverse the passed string as argument 
//Initialise count =1 
//In this loop call a condition while(s[i] == s[i+1] && i<n-1) count ++;i++;
// If the condition doesnot satified then just store the count in ans by converting into string 
//ans lastly store the s[i]
//return ans 

//TC-O(m*n)
//SC-O(2^n)
class Solution {
public:
    string recursion(string s){
        int n = s.length();
        if(n==0) return "1";

        string ans ="";
       
        for(int i =0;i<n;i++){
            int count = 1;

          
                while(s[i]==s[i+1] && i<n-1){
                    count++;
                    i++;
                }

                ans+=to_string(count);
                ans+=s[i];
            
        }
        return ans;


    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans = "";

        
        while(n--){
            ans =recursion(ans);
        }

        return ans;


    }
};