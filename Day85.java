//Q1. House Robbery I --Leetcode 198
//SC-O(n)
//TC-O(1)

import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1;i<n;i++){
            int include = nums[i]+prev2;
            int exclude =  prev1;
            prev2 = prev1;
            prev1 = Math.max(include,exclude);
        }

        return prev1;
    }
}

//Q2. House Robbery II --Leetcode 213
//SC-O(n)
//TC-O(n+n)

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];

        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(i !=0) arr1.add(nums[i]);
            if(i!=n-1) arr2.add(nums[i]);
        }

        return Math.max(robRec(arr1), robRec(arr2));
    }
    public int robRec(ArrayList<Integer> nums) {
        int n = nums.size();
        if(n == 1) return nums.get(0);
        int prev2 = 0;
        int prev1 = nums.get(0);
        for(int i=1;i<n;i++){
            int include = nums.get(i)+prev2;
            int exclude =  prev1;
            prev2 = prev1;
            prev1 = Math.max(include,exclude);
        }

        return prev1;
    }
}

//Optimal Approach
//TC-O(n)
//SC-O(1)
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];

        int ans1 = robRec(nums,0,n-2);
        int ans2 = robRec(nums,1,n-1);

        return Math.max(ans1,ans2);
    }
    public int robRec(int[] nums, int stIdx, int endIdx) {
        int n = nums.length;
        if(stIdx == endIdx) return nums[stIdx];
        int prev2 = 0;
        int prev1 = nums[stIdx];
        for(int i=stIdx+1;i<=endIdx;i++){
            int include = nums[i]+prev2;
            int exclude =  prev1;
            prev2 = prev1;
            prev1 = Math.max(include,exclude);
        }

        return prev1;
    }
}

//Q3.Rod Cutting -- Recursion Approach
//TC-O(2^n)
//SC-O(n)

class Solution {
    public int cutRod(int[] price) {
        // code here
        int len = price.length; // 8
        int ans = solve(price,len);
        return ans;
    }
    
    private int solve(int[] price,int len){
        if(len == 0) return 0;
        
        int ans = 0;
        for(int i=1;i<=len;i++){
            int currCost= price[i-1];
            currCost += solve(price,len-i);
            ans = Math.max(currCost,ans);
        }
        
        return ans;
    }
}

//Top Down Approach
//TC-O(n)
//SC-O(n+n)
class Solution {
    public int cutRod(int[] price) {
        // code here
        int len = price.length; // 8
        
         int[] dp = new int[len+1];
         Arrays.fill(dp,-1);
         int ans = solve(price,len,dp);
        return ans;
    }
    
    private int solve(int[] price,int len, int[] dp){
        if(len == 0) return 0;
        if(dp[len] != -1) return dp[len];
        
        int ans = 0;
        for(int i=1;i<=len;i++){
            int currCost = price[i-1];
            currCost += solve(price,len-i,dp);
            ans = Math.max(currCost,ans);
        }
        
        return dp[len] = ans;
    }
}

//Bottom Up Approach -- Tabulation
//TC-O(n)
//SC-O(n)

class Solution {
    public int cutRod(int[] price) {
        // code here
        int len = price.length; // 8
        
         int[] dp = new int[len+1];
         Arrays.fill(dp,-1);
         dp[0] = 0;
         
         for(int i=1;i<=len;i++){
           int maxiumCost  = 0;
           for (int j = 1; j <= i; j++) {
                maxiumCost = Math.max(maxiumCost, price[j - 1] + dp[i - j]);
            }
            dp[i] = maxiumCost; // Store the maximum profit for rod length 'len'
        }
        return dp[len];
    }
}  

//Memoization Approach
//SC-O(n)
//TC-O(n+n)

private static long solve(int n, long[] dp){
		if(n == 1) return dp[1]= 0L;
		if(n==2) return dp[2] = 1L;
		if(dp[n] != -1) return dp[n];
		long ans = ((n-1)%MOD) * ((countDerangements(n-1) % MOD) + (countDerangements(n-2) %MOD));
		return dp[n]= ans;
	}


//Tabulation or Bottom Up Approach
//SC-O(n)
//TC-O(n)

public static long countDerangements(int n) {
    // Write your code here.
    if (n <= 0) return 0;

    if(n==2) return 1;
    else if(n==1) return 0;
    long[] dp = new long[n+1];
    Arrays.fill(dp,0L);
    dp[1] = 0L;
    dp[2] =1L;
    
    for(int i =3;i<=n;i++){
        long first = dp[i-1] %MOD;
        long second = dp[i-2] % MOD ;

        long ans = ((i - 1) * (first + second) );
        dp[i] = ans;
    }
    return dp[n]%MOD;
}

