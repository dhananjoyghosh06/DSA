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