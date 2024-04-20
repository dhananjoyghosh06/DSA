//Q1. Find a specific pair in a matrix
//Approach used - Store the maximum value of the relative subArrays in an another matrix
//TC- O(n^2)
//SC- O(n^2)

#include <bits/stdc++.h> 
int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.
	vector<vector<int>>maxMat(n, vector<int>(n));

	maxMat[n-1][n-1] = mat[n-1][n-1];

	for(int j = n-2;j>=0;j--){
		maxMat[n-1][j] = max(maxMat[n-1][j+1], mat[n-1][j]);

	}

	for(int i =n-2;i>=0;i--){
		maxMat[i][n-1] = max(maxMat[i+1][n-1], mat[i][n-1]);
	}

	for(int i = n-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			int maxi = max(maxMat[i+1][j], maxMat[i][j+1]);
			maxMat[i][j] = max(maxi, mat[i][j]);
		}
	}

	int ans = INT_MIN;

	for(int i = 0;i<n;i++){
		for(int j =0;j<n;j++){
			if (i + 1 < n && j + 1 < n) {
                ans = max(ans, maxMat[i + 1][j + 1] - mat[i][j]);
            }
		}
	}
	
	return ans;
}