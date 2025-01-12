

//Recursion approach 
//TC-O(n*amount)
//SC-O(amount)

class Solution {
    public int coinChange(int[] coins, int amount) {
         int ans = helper(coins, amount);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
    private int helper(int[] arr, int amount){
        if(amount  == 0 ) return 0;
        else if(amount  < 0) return Integer.MAX_VALUE;

        int mini = Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++){
            int ans = helper(arr, amount-arr[i]);
            if(ans != Integer.MAX_VALUE) mini = Math.min(mini, ans+1);
        }    

        return mini;
    }
}

// Memoization/ Top Down Approach 
//TC-O(amount*n)
//SC-O(amount + amount)

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[]  dp = new int[amount +1];
        Arrays.fill(dp,-1);
         int ans = helper(coins, amount,dp);
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
    private int helper(int[] arr, int amount, int[] dp){
        if( amount  == 0 ) return dp[0] = 0;
        else if( amount  < 0 ) return Integer.MAX_VALUE;
       
        if(dp[amount] != -1) return dp[amount]; 
        int mini = Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++){
            int ans = helper(arr, amount-arr[i],dp);
            if(ans != Integer.MAX_VALUE) mini = Math.min(mini, ans+1);
        }    

        return dp[amount] = mini;
    }

}

//Tabulation / Bottom Up approach 
//TC-O(amount *n)
//SC-O(n)

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[]  dp = new int[amount +1];
        Arrays.fill(dp,Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.length;j++){
                if( (i-coins[j] >=0) && (dp[i-coins[j]] != Integer.MAX_VALUE))
                dp[i] = Math.min(dp[i], dp[i-coins[j]]+1); 
            }
        }
        if(dp[amount ] != Integer.MAX_VALUE)
        return dp[amount];
        else return -1;
    }

}

//Q2. Maximum Sum in a non-adjacent elements in an array
//TC-O(2^n)
//SC-O(n)

class Solution {
    int findMaxSum(int arr[]) {
        // code here
        int n = arr.length;
        int ans1 = 0 ;ans1+= sumRec(arr,0,n);
        int ans2 =0; ans2= sumRec(arr,1,n);
        
        return Math.max(ans1,ans2);
    }
    int sumRec(int[] arr, int i, int n){
        if(i>=n) return 0;
        int sum = 0;
        
            for(int idx=i+2;idx<n;idx++){
                int currSum = arr[i];
                currSum+=sumRec(arr,idx,n);
                sum = Math.max(sum,currSum);
            }
        
        sum = Math.max(sum, arr[i]);
        return sum;
    }
}

//Memoization / Top Down Approach
//TC-O(n)
//SC-O(n+n)

class Solution {
    int findMaxSum(int arr[]) {
        // code here
        int n = arr.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        int ans1 = 0 ;ans1+= sumRec(arr,0,n,dp);
        int ans2 =0; ans2= sumRec(arr,1,n,dp);
        
        return Math.max(ans1,ans2);
    }
    int sumRec(int[] arr, int i, int n, int[] dp){
        if(i>=n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int sum = 0;
        
        for(int idx=i+2;idx<n;idx++){
            int currSum = arr[i];
            currSum+=sumRec(arr,idx,n,dp);
            sum = Math.max(sum,currSum);
        }
        
        sum = Math.max(sum, arr[i]);
        return dp[i] = sum;
    }
}

//Tabulation (Bottom Up Approach)
//TC-O(n)
//SC-O(n)


class Solution {
    int findMaxSum(int arr[]) {
        // code here
        int n = arr.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        
        dp[0] = arr[0];
        dp[1] = Math.max(arr[0], arr[1]);
        for(int i=2;i<n;i++){
            int include = dp[i-2]+arr[i];
            int exclude = dp[i-1]+0;
            
            dp[i] = Math.max(include,exclude);
        }
        
        return dp[n-1];
    }
    
}

//Space optimization
//TC-O(N)
//SC-O(1)
class Solution {
    int findMaxSum(int arr[]) {
        // code here
        int n = arr.length;
       
        
        int prev2= 0;
        int prev1= arr[0];
        
        for(int i=2;i<n;i++){
            int include = prev2+arr[i];
            int exclude = prev1+0;
            
            int ans= Math.max(include,exclude);
            prev2 = prev1;
            prev1 = ans;
        }
        
        return prev1;
    }
    
}