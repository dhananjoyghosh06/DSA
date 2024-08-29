//Q1. Interleave the first half of the queue with other half
//TC-O()
//SC-O()

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void interLeave(vector<int> &arr){
        int n= arr.size();
        int half = n/2;
        vector<int>temp1(half);
        vector<int>temp2(half);
        for(int i=0;i<half;i++){
            temp1[i] = arr[i];
        }
        int it =0;
        for(int i=half;i<n;i++){
            temp2[it++]=arr[i];
        }
        int i=0;
        int k=0;
        int j=half;
        while(k<half && j<n && i<n){
            arr[i++]=temp1[k++];
            arr[i++]=temp2[j++];
        }

    }
};

int main(){
    vector<int>arr={11,12,13,14,15,16,17,18,19,20};
    Solution s;
    s.interLeave(arr);
    for(int it:arr){
        cout<<it<<" ";
    }cout<<endl;

}

//approach 2 using a single stack

// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void interval(queue<int>&q){
    stack<int>st;
    int n = q.size();
    if(n<=2) return ;
    if(n%2!=0) cout<<"Not possible"<<endl;
    int half = n/2;
    
    while(half--){
        int val = q.front();
        q.pop();
        st.push(val);
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        q.push(top);
    }
    half = n/2;
    while(half--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    half = n/2;
    while(half--){
        int val = q.front();
        q.pop();
        st.push(val);
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        int front = q.front();
        q.pop();
        q.push(top);
        q.push(front);
    }
}

int main() {
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    queue<int>q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    interval(q2);
    while(!q2.empty()){
        cout<<q2.front()<<' ';
        q2.pop();
    }cout<<endl;
    return 0;
}