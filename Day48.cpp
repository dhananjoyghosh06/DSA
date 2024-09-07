//Q1. Find the k smallest element in an array
//TC-O(n)
//SC-O(k)
//Better approach using prioirty queue(max_heap)

#include<queue>
#include<iostream>
using namespace std;

int kthSmallest(int arr[],int n,int k)
{
    priority_queue<int>pq; //max heap
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[10]={60,50,70,40,80,30,90,20,100,10};
    
   cout<< kthSmallest(arr,10,9)<<endl;
   
   return 0;
}


//Q2. Kth largest elements in an array 
//TC-O(k+(n-k)*logk)
//SC-O(k+(n-k)*logk)


#include <bits/stdc++.h>

using namespace std;

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    priority_queue<int,vector<int>,greater<int>>pq; //max heap
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<n;i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends