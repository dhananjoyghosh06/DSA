//Day1 
// Leetcode 2091
// Remove the Maximum and Minimum Element from an array


//This Approach using unorder Map which is storing two integers as key and value respectively
//step 1: Create an unordered map and store the elements and inidixes of the given array(nums) in it
//step 2: Initilise mini and maxi and assign the value of the minimum element and maximum element of the given array (nums) respectively 
//step 3: Initilise miniIdx and maxIdx  assign the value of the indices of the max and min elements of the given array (nums) using the unordered map(mpp)
//step 4: Initialise left and point to the minimum of (maxIdx and MinIdx) + 1 because of 0-indexing 
//step 5: Inlitialise right and point to the array size - maximum of (maxIdx and MinIdx) 

// left storing the distance the max or min who occured nearest from the left side
// right storing the distance the max or min who occured nearest from the right side

// there should be 3 types of answer could be possible
    //I   :1stly we can remove the max and min from both the end of the array
    //II  :2ndly we can remove the the max and min from only left side 
    //III :3rdly we can remove the the max and min from only left side

//step 6: Inlitialise tempAns1 and assign the sum of left and right for remove from both the side of  the array
//step 7: Inlitialise tempAns2 and assign the maxium value from maxIdx and minIdx for remove from the both side 
//step 8: Inlitialise tempAns3 and assign value of size of the array minus (min value from the array)
//step 9: Return the minimum from tempAns1 . tempAns2, tempAns3

//TC - O(n)
//SC - O(n)


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mpp;

        for(int i =0;i<n;i++){
            mpp[nums[i]]=i;
        }

        int mini= *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        int minIdx= mpp[mini];
        int maxIdx= mpp[maxi];

        int left = min(maxIdx , minIdx)+1;
        int right =nums.size() - max(maxIdx, minIdx);
    
        int tempAns1 = left+right;
        int tempAns2 = max(minIdx,maxIdx)+1;
        int tempAns3 = nums.size()-min(minIdx,maxIdx);

       return min({tempAns1,tempAns2,tempAns3});
    }
};

//This solution is using traversing the array
// step 1 : Inlitialise maxi and mini as 0;
// step 2 : Traverse the whole array (nums ) asn find out that maximum element's idx and minimum element's idx
//step  3 : Inlitialise tempAns1 and assign the sum of left and right for remove from both the side of  the array
//After next same process of the previous approach 

TC - O(n)
SC - O(1)


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi=0;
        int mini=0;

        for(int i=1 ;i<n;i++){
            if(nums[i]>nums[maxi]){
                maxi =i;
            }
            if(nums[i]<nums[mini]){
                mini =i;
            }
        }

        int left = min(maxi,mini) + 1;
        int right= n- max(maxi,mini);
        int tempans1=left+right;

        int tempans2 = max(mini,maxi) +1;
        int tempans3 = n-min(mini, maxi);

        return min({tempans1, tempans2, tempans3});

    }
};