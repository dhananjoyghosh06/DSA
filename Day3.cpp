//Question1 : Maximum SubArray Leetcode 53
//1st Approach : Using two loops 
// for i in range(n) and j from i to n for getting all the contiguous subarrays 
// store the sum of all the possible subarrays and compare with them with maxi which is storing the maximum sum from all the possible subarrays
// TC - O(n^2)
//SC - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int n= nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi =max(maxi,sum);
            }
            
        }
        return maxi;
    }
};

//2nd Approach - Kadane's Algorithm
//initialise the maxi = nums[0] & sum = 0;
//step 1 : sum +=nums[i];
//step2  : maxi= max(maxi,sum);
// if(sum <0) sum =0;

class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int n= nums.size();
        int maxi = nums[0];
        int sum = 0;

        for(int i = 0 ;i<n;i++){
            sum +=nums[i];
            maxi=max(maxi,sum);
            if(sum <0){
                sum =0;
            }
        }   
        
        return maxi;
    }
};


//question 3 : Minimise the difference between heights
class Solution {
public:
    int getDiff(vector<int>& nums) { 
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int maxi = arr[n-1]+k;
        int mini = arr[0]+k

        for(int i = 0 ;i<n;i++){
            sum +=nums[i];
            maxi=max(maxi,sum);
            if(sum <0){
                sum =0;
            }
        }   
        
        return maxi;
    }
};