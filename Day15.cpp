//Q1. Print the elements in sorted order using row column wise sorted order 
//Method  used - Brute force
// TC-O(N^2 lon(N))
//SC-O(N*N);


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void mergeSort(vector<int>&matrix, int st, int end){
      int mid = st+(end-st)/2;
      
      if(st>end) return ;
      
      mergeSort(matrix,st, mid);
      mergeSort(matrix, mid+1, end);
      
      merge(matrix, st,end);
  }
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int end = N*N;
        int st =0 ;
        vector<int>matrix;
        
        for(int i =0;i<N;i++){
            for(int j=0;j<N;j++){
               matrix.push_back(Mat[i][j]); 
            }
                
            
        }
        
        sort(matrix.begin(), matrix.end());
        int curr =0;
        for(int i =0;i<N;i++){
            for(int j=0;j<N;j++){
               Mat[i][j] = matrix[curr]; 
               curr++;
            }
        }
        
        return Mat;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends