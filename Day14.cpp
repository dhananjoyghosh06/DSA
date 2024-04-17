//Find the maximum ones in a row and return no of ones and and also the row number -Leetcode 2663
//Approach used - Brute Force 
//TC-O(m*n)
//SC-O(1)
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int maxi =0;
        int rowCount =0;
        for ( int i=0;i<row;i++){
            int count =0;
            int rowC = i;
            for(int j = 0;j<col;j++){
                if(mat[i][j] == 1) count++;
            }
            if(count>maxi){
                rowCount = rowC;
                maxi=count;
            }
            if(count == maxi){
                maxi = count ;
                rowCount = min(rowC, rowCount);
            }
            int maxi = max(count,maxi);

        }
        return {rowCount, maxi};
    }
};

//2nd Approach
//TC - O(m*n)
//SC-O(1);
class Solution {
public:
    int lower_bound(vector<int> mat, int m, int target){
        int low = 0;
        int high = m-1;
        int ans = m;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mat[mid]>=target){
                ans = mid;
                high= mid-1;
            }else {
                low = mid+1;

            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int row = mat.size();
        int col = mat[0].size();
        int max_count =0;
        int index=0;

        for(int i =0;i<row;i++){
            sort(mat[i].begin(), mat[i].end());
        }

        for(int i =0; i<row ;i++){
            int count = col - lower_bound(mat[i], col, 1);
            if(count>max_count){
                max_count = count ;
                index = i;
            }
        }

        return {index,max_count};
       
    }
};