//Q1. Find the first repeated word in a string
//TC-o(n)
//SC-O(n)

#include<bits/stdc++.h>
using namespace std;

void func(string s){
    int n = s.length();
    unordered_map<string, int>mpp;
    string temp="";
    string ans="";
    for(int i=0;i<=n;i++){
        if(s[i]==' ' || s[i]=='\0'){
            mpp[temp]++;
            if(mpp[temp]>1){
                ans=temp;
                break;
            }
            temp="";
        }
        else{
            temp+=s[i];
        }
    }
    if(ans!="")
    cout<<ans<<endl;
    else
    cout<<"There is not a repeating word present"<<endl;
}

int main()
{
    string u="Ravi had been saying that he had been there";
    string v="Ravi had been saying that";
    string w="he had had he";
    func(u);
    func(v);
    func(w);
     
     
    return 0;
     
}