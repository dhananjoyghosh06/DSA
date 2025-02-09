//Q1. Min score Triangulation
//Top Down approach
//TC-O(N*N*N)
//SC-O(N*N)
class Day89 {
    public int sol= Integer.MAX_VALUE;
    public int minScoreTriangulation(int[] values) {
        int i=0,j=values.length-1;
        int[][] dp = new int[values.length][values.length];
        for(int[] arr : dp)
        Arrays.fill(arr,-1);
        return solve(values,dp, i,j);
    }
    int solve(int[] values,int[][] dp, int i, int j){
        if(i+1 == j) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        int ans = Integer.MAX_VALUE;
        for(int k=i+1;k<j;k++){
        int temp = (values[i]*values[j]*values[k]) + solve(values,dp,i,k) + solve(values,dp,k,j);
        ans = Math.min(temp,ans);
        }
        
        
        return dp[i][j] = ans;
    }
}


//Tabulization Approach
//SC-O(n*n*n)
//TC-O(n*n)

class Solution {
    public int sol= Integer.MAX_VALUE;
    public int minScoreTriangulation(int[] values) {
       
        int[][] dp = new int[values.length][values.length];
        for(int[] arr : dp)
        Arrays.fill(arr,0);
       for(int i=values.length-1;i>=0;i--){
        for(int j=i+2;j<values.length;j++){
             int ans = Integer.MAX_VALUE;
            for(int k=i+1;k<j;k++){
            int temp = (values[i]*values[j]*values[k]) + dp[i][k]+dp[k][j];
            ans = Math.min(temp,ans);
            }
            dp[i][j] = ans;
        }
       }

       return dp[0][values.length-1];
    }
}

//Q2. Minimum Sideways Jumps -- Leetcode 1824
//TC-O(2^n)
//SC-O(N+N)
class Solution {
    public int minSideJumps(int[] obstacles) {
        //using recursion
        
        return solve( obstacles, 0, 2);
    }
    private int solve(int[] obs, int currPos, int currLen){
        int n = obs.length-1;
        if(currPos == n) return 0;
        if(obs[currPos+1] != currLen){
            return solve(obs,currPos+1, currLen);
        }else{
            int ans = Integer.MAX_VALUE;
            for(int i=1;i<=3;i++){
                if(i!=currLen && obs[currPos] !=i){
                    ans = Math.min(ans, 1+solve(obs,currPos,i));
                }
            }
            return ans;
        }
    }
}

//USING Top Down Approach
//TC-O(3*3*N)
//SC-O(3*N+3)
class Solution {
    public int minSideJumps(int[] obstacles) {
        //using Memoization(Top Down)
        int n = obstacles.length;
        int[][] dp = new int[4][n];
        for(int[] arr : dp){
            Arrays.fill(arr,-1);
        }
        return solve( obstacles,dp, 0, 2);
    }
    private int solve(int[] obs,int[][] dp, int currPos, int currLen){
        int n = obs.length-1;
        if(currPos == n) return 0;
        if(dp[currLen][currPos]!=-1) return dp[currLen][currPos];
        if(obs[currPos+1] != currLen){
            return dp[currLen][currPos] = solve(obs,dp,currPos+1,currLen);
        }else{
            int ans = Integer.MAX_VALUE;
            for(int i=1;i<=3;i++){
                if(i!=currLen && obs[currPos] !=i){
                    ans = Math.min(ans, 1+solve(obs,dp,currPos,i));
                }
            }
            return dp[currLen][currPos] = ans;
        }
    }
}

//Tabulization Approach
//TC-O(n*3*3)
//SC-O(3*n)
class Solution {
    public int minSideJumps(int[] obstacles) {
        //using Memoization(Top Down)
        int n = obstacles.length-1;
        int[][] dp = new int[4][n+1];
        for(int[] arr : dp){
            Arrays.fill(arr,0);
        }

        for(int currPos=n-1;currPos>=0;currPos--){
            for(int currLen=1;currLen<=3;currLen++){
                    if(obstacles[currPos+1]!=currLen){
                        dp[currLen][currPos] = dp[currLen][currPos+1];
                    }else{
                        int ans = Integer.MAX_VALUE;
                        for(int i=1;i<=3;i++){
                            if(i!=currLen && obstacles[currPos] !=i){
                                ans = Math.min(ans, 1+dp[i][currPos+1]);
                            }
                        }
                        dp[currLen][currPos] =ans;
                    }
            }
        }
        return Math.min(Math.min(dp[2][0], 1+dp[1][0]), 1+dp[3][0]);
    }
    
}

//Q3. Reducing dishes
//TC-O(nlog + 2^n)
//SC-O(n)

class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        return solve(satisfaction,0,0);
    }
    private int solve(int[] satisfaction, int idx, int time){
        if(idx == satisfaction.length) return 0;

        int include = satisfaction[idx]*(time+1)+solve(satisfaction,idx+1, time+1);
        int exclude =  solve(satisfaction,idx+1, time);

        return Math.max(include,exclude);
    } 
}

//Using memoization
//TC-O(NLOGN+n*n)
//SC-O(n*n)
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int n = satisfaction.length;
        int[][]dp = new int[n][n+1];
        for(int[] arr:dp){
            Arrays.fill(arr,-1);
        }
        return solve(satisfaction,dp,0,0);
    }
    private int solve(int[] satisfaction,int[][]dp, int idx, int time){
        if(idx == satisfaction.length) return 0;
        if(dp[idx][time+1] !=-1) return dp[idx][time+1];
        int include = satisfaction[idx]*(time+1)+solve(satisfaction,dp,idx+1, time+1);
        int exclude =  solve(satisfaction,dp,idx+1, time);

        return dp[idx][time+1] = Math.max(include,exclude);
    } 
}

//Tabulization Approach 
//TC-O(N*N+LogN)
//SC-O(N*N)
 public int maxSatisfaction(int[] satisfaction) {
    Arrays.sort(satisfaction);
    int n = satisfaction.length;
    int[][]dp = new int[n+1][n+1];
    for(int[] arr:dp){
        Arrays.fill(arr,0);
    }
    for(int idx =n-1;idx>=0;idx--){
        for(int time = idx ;time>=0;time--){
            int include = satisfaction[idx]*(time+1)+dp[idx+1][time+1];
    int exclude =  dp[idx+1][time];
     dp[idx][time] = Math.max(include,exclude);
        }
       
    }
    return dp[0][0];
}
//TC-O(N*N+LogN)
//SC-O(N)
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int n = satisfaction.length;
        int[] curr = new int[n+1];
        int[] next = new int[n+1];
        Arrays.fill(next,0);
        Arrays.fill(curr,0);
        for(int idx =n-1;idx>=0;idx--){
            for(int time = idx ;time>=0;time--){
            int include = satisfaction[idx]*(time+1)+next[time+1];
            int exclude =  next[time];
            curr[time]= Math.max(include,exclude);
            }
           next = curr.clone();
        }
        return next[0];
    }
}

//Q4. Longest Increasing Subsequences
//TC-O(2^n)
//SC-O(n*n)

class Solution{
    public int prev;
    public int longestIncreasingSubsec(int[] nums){
        prev =-1;
        return solve(nums,0);
    }
    private int solve(int[] nums, int idx){
        int n = nums.length;
        if(idx>=n) return 0;

        // two conditions to find longest increasing subsequences.One is including the element at the idx and another is excluding. 
        // to include the idx'th element there is a condition that the previous element has been included is lesser than the idx'th element 
        int include=0;
        if(prev == -1 || prev<=nums[idx]){
            prev = nums[idx];
            include = 1 + solve(nums,idx+1);
        }
        int exclude = solve(nums,idx+1);

        return Math.max(include, exclude);
    }
}

//Using Memoization
//TC-O(n^2)
//SC-O(n+n^2)

class Solution {
   
    public int lengthOfLIS(int[] nums) {
        int prev = -1;
        int[][] dp  = new int[nums.length+1][nums.length+1];
        for(int[] arr : dp){
            Arrays.fill(arr,-1);
        }
        
        return solve(nums,dp,0, prev);
    }
     private int solve(int[] nums, int[][] dp, int idx, int prev){
        int n = nums.length;
        if(idx>=n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int include=0;
        if(prev == -1 || nums[prev]<nums[idx]){        
            include = 1 + solve(nums,dp,idx+1, idx);
        }
        int exclude = solve(nums,dp,idx+1,prev);

        return dp[idx][prev+1] =  Math.max(include, exclude);
    }
}

//using tabulation
//TC-O(n^2)
//SC-O(n+n^2)

class Solution {
   
    public int lengthOfLIS(int[] nums) {
        
        int[][] dp  = new int[nums.length+1][nums.length+1];
        for(int[] arr : dp){
            Arrays.fill(arr,0);
        }
        for(int idx = nums.length-1;idx>=0;idx--){
            for(int prev = idx-1;prev>=-1;prev--){
                int include=0;
                if(prev == -1 || nums[prev]<nums[idx]){        
                    include = 1 + dp[idx+1][idx+1];
                }
                int exclude = dp[idx+1][prev+1];
                dp[idx][prev+1] = Math.max(include,exclude);
            }
        }
        return dp[0][0];
    }
}

//Space Optimization
//SC-O(n)
//TC-O(N^2)
class Solution {
   
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] currRow  = new int[n+1];
        int[] nextRow = new int[n+1];
        Arrays.fill(currRow,0);
        Arrays.fill(nextRow,0);   
        
        for(int idx = nums.length-1;idx>=0;idx--){
            for(int prev = idx-1;prev>=-1;prev--){
                int include=0;
                if(prev == -1 || nums[prev]<nums[idx]){        
                    include = 1 + nextRow[idx+1];
                }
                int exclude = nextRow[prev+1];
                currRow[prev+1] = Math.max(include,exclude);
            }
            nextRow =  currRow;
        }
        return nextRow[0];
    }
}

//Optimal Solution
//TC-O(nlogn)
//SC-O(n)

class Solution {
    public int lengthOfLIS(int[] nums) {
        //using nlogn complexity
        int n = nums.length;
        return solveOptimal(nums,n);
    }
    private int solveOptimal(int[] nums, int n){
        if(n == 0) return 0;

        ArrayList<Integer> helper= new ArrayList<>();
        helper.add(nums[0]);

        for(int i=1;i<n;i++){
            int size = helper.size();
            if(helper.get(size-1)<nums[i]){
                helper.add(nums[i]);
            }else{
                int lowIdx = lowerBound(helper,nums[i]);
                helper.set(lowIdx,nums[i]);
            }
        }

        return helper.size();
    }
    public int lowerBound(ArrayList<Integer> arr, int target) {

        int low = 0;

        int high = arr.size() - 1;

        

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr.get(mid) >= target) {

                high = mid - 1; // Search left half

            } else {

                low = mid + 1; // Search right half

            }

        }

        

        // If loop exits, 'low' points to the lower bound

        return low;

    }

}

//Russian Dolls Envelopes 
//TC-O(NLOGN)
//SC-O(N+N)

class Solution {
    public int maxEnvelopes(int[][] arr) {
         Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0]; 
            } else {
                return b[1] - a[1];
            }
        });
        int[] nums = new int[arr.length];
        for(int i=0;i<arr.length;i++){
            nums[i] = arr[i][1];
        }
        return solveOptimal(nums,nums.length);
    }
    private int solveOptimal(int[] nums, int n){
        if(n == 0) return 0;

        ArrayList<Integer> helper= new ArrayList<>();
        helper.add(nums[0]);

        for(int i=1;i<n;i++){
            int size = helper.size();
            if(helper.get(size-1)<nums[i]){
                helper.add(nums[i]);
            }else{
                int lowIdx = lowerBound(helper,nums[i]);
                helper.set(lowIdx,nums[i]);
            }
        }

        return helper.size();
    }
    public int lowerBound(ArrayList<Integer> arr, int target) {

        int low = 0;

        int high = arr.size() - 1;

        

        while (low <= high) {

            int mid = (low + high) / 2;

            if (arr.get(mid) >= target) {

                high = mid - 1; // Search left half

            } else {

                low = mid + 1; // Search right half

            }

        }

        

        // If loop exits, 'low' points to the lower bound

        return low;

    }
}
