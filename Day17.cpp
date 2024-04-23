//Q1. Find the kth smallest element in a row & column sorted matrix
//Method used - Binary Search + Upper Bound
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int smallest = matrix[0][0];
        int largest = matrix[row-1][col-1];

        while(smallest<largest){
            int mid = smallest+(largest-smallest)/2;
            int count = 0;
            for(int i=0;i<row;i++){
                int pos= upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
                count+=pos;
            }

            if(count<k) smallest = mid+1;
            else largest = mid;
        }
        return smallest;

      
    }
};

//Q1 approach2 - Maxheap / same in minheap logic
//TC-O(n^2)
//SC-O(N^2)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int smallest = matrix[0][0];
        int largest = matrix[row-1][col-1];

        priority_queue<int>maxHeap;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(maxHeap.size()>k) maxHeap.pop();
                maxHeap.push(matrix[row][col]);
            }

        }
        return maxHeap.top();
    }
};




//Q2. Find the common element in all rows in a 2D Array
//TC- O(n*n)
//SC- O(row)+O(n*n)

#include<bits/stdc++.h>
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Write your code here
    int row = mat.size();
    int col = mat[0].size();
    vector<int>ans;

    unordered_map<int, int > mpp;
   unordered_set<int>sett;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            sett.insert(mat[i][j]);
        }

        for(auto it: sett){
            mpp[it]++;
        }

        sett.clear();
    }

    for(auto it : mpp){
        if(it.second==row){
            ans.push_back(it.first);
        }
    }

    return ans;
}
