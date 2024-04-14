//Spiral print of a matrix
// Method used = brute force 
// TC - O(n*n);
//SC - O(n)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans ;
        int count = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col;

        int stRow = 0;
        int stCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        while (count<total){
            for(int i = stCol;count<total && i<=endCol;i++){
                ans.push_back(matrix[stRow][i]);
                count++;
            }
            stRow++;
            for(int i = stRow ;count<total && i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;
            for(int i = endCol;i>=stCol && count<total;i--){
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;
            for(int i = endRow;i>=stRow && count<total;i--){
                ans.push_back(matrix[i][stCol]);
                count++;
            }
            stCol++;
        }

        return ans;
    }
};


//Q2 - Search In a matrix where the elements are row wise sorted 
//Method used - Merge Sort 
//TC- O(log(m*n))
//SC- O(1)
class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int target, int st , int end){
        int row = matrix.size();
        int col = matrix[0].size();
        if(st>end) return false;
        int mid = st+(end-st)/2;
        int ele = matrix[mid/col][mid%col];
        if(ele == target) return true;
        if( ele < target)  return helper(matrix, target, mid+1, end);
        else return helper(matrix, target, st, mid-1);
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row*col -1;


        // while(left<=right){
        //    int  mid = left+(right-left)/2;
        //     int ele = matrix[mid/col][mid%col];
        //     if(ele == target) return true;
        //     else if (ele<target) left=mid+1;
        //     else right= mid-1;
        // }
        // return false;
        return helper(matrix, target, left, right);
    }
};

//Question - 3 - Search in a 2D array when the array is row wise sorted in acending order and column wise sorted in acending order 
//leetcode - 240
//Method used - brute force;
//TC - O(n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        sort(matrix.begin(), matrix.end());
        int row = matrix.size();
        int col = matrix[0].size();

        int rowPointer = 0;
        int colPointer = col-1;
        while(rowPointer<=row-1 && colPointer>=0){
            int ele = matrix[rowPointer][colPointer];

            if(ele == target) return true;
            else if ( ele<target) rowPointer++;
            else colPointer--;
        } 

        return false;
        
    }
};