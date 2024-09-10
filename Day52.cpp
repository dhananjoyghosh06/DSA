//Q1. Merge k sorted arrays
//TC-O(k^2*Log(k))
//SC-O(k*k)

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    class Node
    {
      public:
      int data;
      int rowTracker;
      int colTracker;
      Node(int data, int row, int col){
          this->data = data;
          this->rowTracker = row;
          this->colTracker = col;
      }
    };
    class compare{
        public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        
        priority_queue<Node* ,vector<Node*>, compare>pq;
        
        for(int i=0;i<k;i++){
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        vector<int>ans;
        
        while(pq.size()>0){
            Node* temp = pq.top();
            ans.push_back(temp->data);
            pq.pop();
            
            int i= temp->rowTracker;
            int j = temp->colTracker;
            
            if(j+1<arr[i].size()){
                Node* next = new Node(arr[i][j+1], i, j+1);
                pq.push(next);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends