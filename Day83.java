//Q1. Fibonacci Series nth number -- Top Down Approach
//TC-O(n)
//SC-O(n+n)

class Solution {
    public int nthFibonacci(int n) {
        // code here
        //Top Down Approach (dp series)
        int[] arr = new int[n+1];
        Arrays.fill(arr,-1);
        return solve(n,arr);
        
    }
    int solve(int n, int[] arr){
        if(n == 1 || n == 0) return n;
        
        arr[n-1] = nthFibonacci(n-1);
        arr[n-2] = nthFibonacci(n-2);
        return arr[n-1]+arr[n-2];
    }
}


//Bottom Up Approach
//TC-O(n)
//SC-O(n)



class Solution {
    public int nthFibonacci(int n) {
        // code here
        //Tabulation Approach (dp series)
        if(n==1 || n==0) return n;
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        dp[1]=1;
        dp[0]=0;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
    }
}

//Space Optimisation Approach
//TC-O(n)
//SC-O(1)



// User function Template for Java

class Solution {
    public int nthFibonacci(int n) {
        // code here
        //Space optimised approach
        if(n==1 || n==0) return n;
        int prev1 =1;
        int prev2 =0;
        
        for(int i=2;i<=n;i++){
            int curr = prev1+prev2;
            prev2=prev1;
            prev1=curr;
        } 
        
        return prev1;
    }
}

Q2. Minimum cost climbing stairs - USING RECURSION
//TC-O(2^n)
//SC-O(n)

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int ans = Math.min(solve(cost,n-1), solve(cost,n-2));

        return ans;

    }
    int solve(int[] cost, int n){
        if(n == 0) return cost[0];
        else if(n == 1) return cost[1];

        return Math.min(solve(cost,n-1), solve(cost,n-2)) + cost[n];
    }
}

//TOP DOWN with memoization
//TC-O(n)
//SC-O(n+n)

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        int ans = Math.min(solve(cost,dp,n-1), solve(cost,dp,n-2));

        return ans;

    }
    int solve(int[] cost, int[] dp, int n){
        if(n == 0) return cost[0];
        else if(n == 1) return cost[1];
        
        if(dp[n] != -1) return dp[n];
       
        return dp[n]= Math.min(solve(cost,dp,n-1),solve(cost,dp,n-2)) + cost[n];
    }
}

//Tabulation approach or Bottom up approach
//TC-O(n)
//SC-O(n)

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if(n == 2) return Math.min(cost[0], cost[1]);
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        
        dp[0] =cost[0];
        dp[1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i] =cost[i]+ Math.min(dp[i-1], dp[i-2]);
        }
        

        return Math.min(dp[n-1], dp[n-2]);

    }
   
}