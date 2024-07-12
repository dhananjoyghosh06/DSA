//Q1. Converting Roman Numerals to decimal 
TC-O(n);
TC-(1);

#include <bits/stdc++.h>
using namespace std;


//  Driver Code Ends
//User function template for C++

class Solution {
    public:
    int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;

    return -1;
}
  public:
    int romanToDecimal(string &str) {
        // code here
        
        int res =0;
        for(int i=0;i<str.length();i++){
             // Getting value of symbol s[i]
        int s1 = value(str[i]);

        if (i + 1 < str.length()) {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);

            // Comparing both values
            if (s1 >= s2) {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends

//Q2. Boyer Moore Algorithm 
//TC-O(n-m+1)
//O(256)

#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256
void badCharHeuristic(string str, int size,
                      int badchar[NO_OF_CHARS]){
            int i;
            for(i=0;i<NO_OF_CHARS;i++){
                badchar[i] = -1;
            }
            for(i=0;i<size;i++){
                badchar[(int)str[i]] =i;
                cout<<(int)str[i]<<endl;
            }
            
}

void search (string txt, string pat){
    int m = pat.size();
    int n = txt.size();
    
    int badChar[NO_OF_CHARS]; // 65-0,66-1,67-2 
    
    badCharHeuristic(pat, m, badChar);
    int s=0; 
    while (s <= (n - m)){ // iterate the txt
        int j =m-1;
        while(j>=0 && pat[j]==txt[s+j]) j--;
        if(j<0){
           cout << "pattern occurs at shift = " << s
                 << endl;

            s += (s + m < n) ? m - badChar[txt[s + m]] : 1;
        } 
         else
            s += max(1, j - badChar[txt[s + j]]);
    
    }
    
}
int main()
{
    string txt = "LO HELLO O HELLO";
    string pat = "HELLO";
    search(txt, pat);
    return 0;
}