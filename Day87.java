//Q1. Minimum number of perfect squares to sum of n
//TC-O(2^n)
//SC-O(n)

import java.util.Arrays;

class Solution {
    public int numSquares(int n) {
            if(n == 0) return 0;
        if(n == 1) return 1;
        int ans = n;
        for(int i=2;i*i<=n;i++){
            ans = Math.min(ans, 1+numSquares(n-(i*i)));
        }

        return ans;
    }
    
}
// Memoization appraoch 
//TC-O(N)
//SC-O(N+N)
public int numSquares(int n) {
        int [] dp = new int[n+1];
        Arrays.fill(dp,-1);
     return solve(n,dp);
    }
private int solve(int n, int[] dp){
    if(n == 0) return 0;
  if(n == 1) return 1;
  if(dp[n] != -1) return dp[n];
  int ans = n;
  for(int i=2;i*i<=n;i++){
      ans = Math.min(ans, 1+numSquares(n-(i*i)));
  }

  return dp[n]=  ans;
}

//Tabulaization Approach 
//SC-O(n*n)
//TC-O(n)

class Solution {
    public int numSquares(int n) {
        int [] dp = new int[n+1];
        for(int i=0;i<=n;i++){
            dp[i] = i;
        }
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
           for(int j=2;j*j<=n;j++){
            if((i-(j*j))>=0)
            dp[i] =  Math.min(dp[i], 1+dp[i-(j*j)]);
           }
        }
        return dp[n];
    }
    
} 

// Find minimum costs to buy train tickets
//TC-O(2^N)
//SC-O(N)

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        
        return solve(days,costs, 0);
    }

    private int solve(int[] days, int[] costs, int idx){
        int n = days.length;
        if(idx>=n) return 0;
        // int ans = Integer.MAX_VALUE;
        int op1 = costs[0] + solve(days,costs,idx+1);
        int i=0;
        for(i=idx;i<n && days[i] < days[idx]+7; i++)
        {

        }
        int op2 = costs[1] + solve(days,costs,i);

        for(i=idx;i<n && days[i]<days[idx] + 30 ;i++)
        {}
        int op3 = costs[2]+ solve(days,costs,i);

        return Math.min(Math.min(op1,op2), op3);
         
    }

}

//Memoization Approach
//TC-O(365) which is a constant time complexity
//SC-O(n+n)

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        int [] dp = new int[n+1];
        Arrays.fill(dp,-1);
        return solve(days,costs, 0,dp);
    }

    private int solve(int[] days, int[] costs, int idx, int[] dp){
        int n = days.length;
        if(idx>=n) return 0;
        // int ans = Integer.MAX_VALUE;
        if(dp[idx]!= -1) return dp[idx];
        int op1 = costs[0] + solve(days,costs,idx+1,dp);
        int i=0;
        for(i=idx;i<n && days[i] < days[idx]+7; i++)
        {

        }
        int op2 = costs[1] + solve(days,costs,i,dp);

        for(i=idx;i<n && days[i]<days[idx] + 30 ;i++)
        {}
        int op3 = costs[2]+ solve(days,costs,i,dp);

        return dp[idx] = Math.min(Math.min(op1,op2), op3);
         
    }

}

//Tabulization Approach
//TC-O(N)
//SC-O(N)

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        int [] dp = new int[n+1];
        Arrays.fill(dp,Integer.MAX_VALUE);

        dp[n] = 0;

        for(int k=n-1;k>=0;k--){
                int op1 = costs[0] + solve(days,costs,k+1,dp);
                int i=0;
                for(i=k;i<n && days[i] < days[k]+7; i++)
                {

                }
                int op2 = costs[1] + solve(days,costs,i,dp);

                for(i=k;i<n && days[i]<days[k] + 30 ;i++)
                {}
                int op3 = costs[2]+ solve(days,costs,i,dp);

                dp[k] =   Math.min(Math.min(op1,op2), op3);
        }
        return dp[0];
    }

   

}

//SPACE OPTIMIZATION TECHNIQUE
//TC-O(N)
//SC-O(1) // Beacuse of the maximum day of monthly subscription could not be more than 30 and weekly subscription could not be more than 7

class Pair<U,V>{
    public U first;public V second;
    Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        Queue<Pair<Integer,Integer>> monthly =new LinkedList<>();
        Queue<Pair<Integer,Integer>> weekly = new LinkedList<>();

        int ans = 0;
        
        for(int day : days){
            while(!monthly.isEmpty() && monthly.peek().first + 30 <= day){
                monthly.poll();
            }
            while(!weekly.isEmpty() && weekly.peek().first + 7 <= day){
                weekly.poll();
            }

            // 
            Pair<Integer,Integer> monthPair = new Pair<>(day,ans+costs[2]);
            Pair<Integer,Integer> weekPair = new Pair<>(day,ans+costs[1]);
            monthly.offer(monthPair);
            weekly.offer(weekPair);

            ans = Math.min(ans+costs[0], Math.min(monthly.peek().second, weekly.peek().second));

        }

        return ans;
    }
}