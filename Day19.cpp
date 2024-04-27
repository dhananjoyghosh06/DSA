//Q1. cheak wheather a string is palindrome or not ? 
//Method used- Recursion & Two Pointer
 
#include <bits/stdc++.h> 
using namespace std;
bool solve ( string s, int low, int high){
    if(low>=high) return true;

    if(isalnum(s[low]) && isalnum(s[high]) && tolower(s[low]) != tolower(s[high])) return false;
    return solve(s, low+1, high-1);
}
bool checkPalindrome(string s)
{
    // Write your code here.
   int low=0;
   int high = s.size()-1;

   string d="";
   for(int i =0;i<=high;i++){
       if(isalpha(s[i]) || isdigit(s[i])){
           d+=s[i];
       }
   }
   
   int hi = d.size()-1;
   return solve(d, low, hi);
  
//    while(low<hi){
//        if(tolower(d[low])!= tolower(d[hi])){
//            return false;
//        }
//        low++;
//        hi--;
//    }

//    return true;

}