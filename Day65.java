//Q1. Two sum II 
//TC-O(N)
//SC-O(1)

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int st = 0;
        int end = numbers.length-1;

        while(st<end){
            int sum = numbers[st]+numbers[end];
            if( sum == target) return new int[]{st+1,end+1};
            else if (sum<target) st++;
            else end--;
        }

        return new int[]{-1,-1};
    }
}

//Q2. Minimum size subarray sum
//TC-O(n)
//SC-O(1)

class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int sum = 0,left=0,ans=nums.length+1;
       for(int i=0;i<nums.length;i++){
            sum+=nums[i];
                while(sum>=target){
                    ans = Integer.min(ans, i-left+1);
                    sum-=nums[left];
                    left++;
                }
       }
        return ans==nums.length+1? 0 : ans;
    }
   
}
//Q3. H-Index II 
//TC-O(logn)
//SC-O(1)

class Solution {
    public int hIndex(int[] arr) {
        int st = 0;
        int n =  arr.length;
        int end  = n-1;
        int  ans = 0;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(arr[mid] >= n-mid) {
                ans = n-mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
}