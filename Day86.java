//Q1. Count derangements
//TC-O(2^n)
//SC-O(N)

public class Day86 {
    public static final long MOD = 100000007;
   public static long countDerangements(int n) {
       // Write your code here.
       if(n == 1) return 0;
       if(n==2) return 1;

       long ans = ((n-1)%MOD) * ((countDerangements(n-1) % MOD) + (countDerangements(n-2) %MOD));

       return ans;
   }
}

// Top Down Approach
//SC-O(n)
//TC-O(n+n)
import java.util.*;
public class Day86 {
	 public static final long MOD = 100000007;
	public static long countDerangements(int n) {
		// Write your code here.
		long[] dp = new long[n+1];
		Arrays.fill(dp,-1);
		return solve(n,dp);
	}
	private static long solve(int n, long[] dp){
		if(n == 1) return dp[0]= 0L;
		if(n==2) return dp[1] = 1L;
		if(dp[n-1] != -1) return dp[n-1];
		long ans = ((n-1)%MOD) * ((countDerangements(n-1) % MOD) + (countDerangements(n-2) %MOD));
		return dp[n-1]= ans;
	}

}

//Bottom Up Approach 
//SC-O(n)
//TC-O(n)

public static final long MOD = 100000007;
public static long countDerangements(int n) {
	// Write your code here.
	if(n==2) return 1;
	else if(n==1) return 0;
	long[] dp = new long[n+1];
	Arrays.fill(dp,0L);
	dp[1] = 0L;
	dp[2] =1L;
	
	for(int i =3;i<=n;i++){
		long first = dp[i-1] %MOD;
		long second = dp[i-2] % MOD ;

		long ans =  ((i-1) * (first+second)%MOD ) %MOD; 
		dp[i] = ans;
	}
	return dp[n];
}


//Q2. Painting the fence -- Have totally doubt on the question because of lack of knowledge on Permutation & Combination
//TC-O(2^n)
//SC-O(N)

class Solution {
    int countWays(int n, int k) {
        // code here.
        return solve(n,k);
       
    }
    int solve(int n, int k){
         if(n ==1 ) return k;
        if(n == 2) return k+(k*(k-1));
        
        int ans =  (k-1)*solve(n-2,k) + (k-1) * solve(n-1,k);
        
        return ans;
    }
}
//Top Down approach
//TC-O(n)
//SC-O(n+n)

class Solution {
    int countWays(int n, int k) {
        // code here.
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        
        return solve(n,k,dp);
       
    }
    int solve(int n, int k, int[] dp){
         if(n ==1 ) return k;
        if(n == 2) return k+(k*(k-1));
        if(dp[n] != -1) return dp[n];
        int ans =  (k-1)*solve(n-2,k,dp) + (k-1) * solve(n-1,k,dp);
        dp[n]= ans;
        return ans;
    }
}

//Tabulation Appraoch
//TC-O(n)
//SC-O(n)

class Solution {
    int countWays(int n, int k) {
        // code here.
        if(n==1) return k;
        if(n==2) return (k+(k*(k-1)));
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        dp[1] = k;
        dp[2] = (k+(k*(k-1)));
        
        for(int i=3;i<=n;i++){
            int ans = ((k-1) * dp[i-2]) +( (k-1) * dp[i-1]);
            dp[i] = ans;
        }
        return dp[n];
    }
}

//Space optimisation
//TC-O(N)
//SC-O(1)
class Solution {
    int countWays(int n, int k) {
        // code here.
        if(n==1) return k;
        if(n==2) return (k+(k*(k-1)));
       
        int prev2 = k;
        int prev1 = (k+(k*(k-1)));
        
        for(int i=3;i<=n;i++){
            int ans = ((k-1) * prev2) + ((k-1) * prev1);
            
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
}


//Q3. Knapsack Problem 
//TC-O(n*capcity)
//SC-O(n*cap+n*cap)

//top down dp/ memoization
class Solution {
    // Function to return max value that can be put in knapsack of capacity.
    static int knapSack(int capacity, int val[], int wt[]) {
        // code here
        int n = val.length;
        int dp[][] = new int[n+1][capacity+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=capacity;j++){
                dp[i][j] = -1;
            }
        }
        return solve(capacity,val,wt,n-1,dp);
    }
    static int solve(int cap,int[] val, int[] wt, int idx, int[][] dp){
        if(idx == 0){
            if(wt[idx] > cap) return 0;
            else return val[idx];
        }
        if(dp[idx][cap] !=-1) return dp[idx][cap];
        int include = 0;
        
        if(wt[idx] <= cap){
            include = val[idx] + solve(cap-wt[idx], val,wt,idx-1,dp);
        }
        
        int exclude = solve(cap, val,wt,idx-1,dp);
        
        
        return dp[idx][cap] = Math.max(include,exclude);
        
    }
}

//Tabulization / bottom up dp
//TC-O(n*c)
//TC-O(n*c)
class Solution {
    // Function to return max value that can be put in knapsack of capacity.
    static int knapSack(int capacity, int val[], int wt[]) {
        // code here
        int n = val.length;
        int dp[][] = new int[n][capacity+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<=capacity;j++){
                dp[i][j] = 0;
            }
        }
        for(int w= wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                dp[0][w] = val[0];
            }else{
                dp[0][w] = 0;
            }
        
        }
       
        for(int i=1;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int include =0;
                if(wt[i]<=j)
                include = val[i] + dp[i-1][j-wt[i]];
                int exclude = dp[i-1][j];
                int ans = Math.max(include, exclude);
                dp[i][j] = ans;
            }
        }
        
        return dp[n-1][capacity];
    }
   
}

//Space Optimisation
//TC-O(n*n)
//SC-O(n)

class Solution {
    // Function to return max value that can be put in knapsack of capacity.
    static int knapSack(int capacity, int val[], int wt[]) {
        // code here
        int n = val.length;
        // int dp[][] = new int[n][capacity+1]
        int[] prev = new int[capacity+1];
        int[]  curr = new int[capacity+1];
        for(int i=0;i<=capacity;i++){
            curr[i] = 0;
            prev[i] = 0;
        }
       
        
        for(int w= wt[0];w<=capacity;w++){
            if(wt[0]<=capacity){
                prev[w] = val[0];
            }else{
                prev[w] = 0;
            }
        
        }
       
        for(int i=1;i<n;i++){
            for(int j=0;j<=capacity;j++){
                int include =0;
                if(wt[i]<=j)
                include = val[i] + prev[j-wt[i]];
                int exclude = prev[j];
                int ans = Math.max(include, exclude);
                
                
                curr[j] = ans;
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev[capacity];
    }
   
}


//Combination Sum IV- Leetcode 377
//Recursion Approach
//SC-O(2^n)
//TC-O(N)

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int n = nums.length;
        
        
        return solve(nums,target,n);
    }
    int solve(int[] nums , int target, int n){
        if(target == 0) return 1;
        if(target<0) return 0;
        int ans  = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=target){
                ans+=solve(nums,target-nums[i],n);
            }
        }

        return ans;
    }
}

//Memoization Approach
//TC-O(N)
//SC-O(N+N)
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int n = nums.length;
        int [] dp = new int[target+1];
       
        Arrays.fill(dp,-1);
        return solve(nums,target,n,dp);
    }
    int solve(int[] nums , int target, int n, int[] dp){
        if(target == 0) return 1;
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans  = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=target){
                ans+=solve(nums,target-nums[i],n,dp);
            }
        }

        return dp[target] =  ans;
    }
}

//Tabulization Approach
//SC-O(N* target)
//TC-O(N)

class Solution {
    public int combinationSum4(int[] nums, int target) {
        int n = nums.length;
        int [] dp = new int[target+1];
       
        Arrays.fill(dp,0);

        dp[0] = 1;

        for(int i=1;i<=target;i++){
                for(int j=0;j<n;j++){
                    if(i-nums[j]>=0)
                    dp[i] +=dp[i-nums[j]];
                }
        }
        return dp[target];
    }

}
