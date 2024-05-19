//Q1 : Remove duplicate from a string and return it in lexicographical order 
//Approach - USED a vector which stores the last occurence of the string 
// USED a stack to store the element with maintaing the lexicographical order 
// USED a vector which stores boolean values for cheaking the character's previous occurence 


class Solution {
public:
    string removeDuplicateLetters(string s ) {
        //bcabc
        vector<int>LastOccurence(26, -1);

        for(int i =0;i<s.length();i++){
            LastOccurence[s[i]-'a'] = i;
        }
        //Li-{2,3,4}
        stack<int>st;
        vector<bool>visited(26, false);

        for(int i =0;i<s.length();i++){
            char ch = s[i];
            if(visited[ch-'a'] == true) continue;

            while(!st.empty() && st.top()>ch && i<LastOccurence[st.top()-'a']){
                visited[st.top()-'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch-'a'] = true;
        }

        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};