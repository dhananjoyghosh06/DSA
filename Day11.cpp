//Permutations of string 
// method Used - Recursion
// TC- O()
//SC -
class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> & ans, int i){
        if(i >= nums.size()) {
            ans.push_back(nums);
            return ;
        }

        for(int j =i;j<nums.size();j++){
            swap(nums[i], nums[j]);
            helper(nums,ans,i+1);
            swap(nums[i], nums[j]);
        }

    } 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans,0);

        return ans;
    }
};