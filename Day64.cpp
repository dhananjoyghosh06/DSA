// Maximum book allocation problem 
//TC-O(nlog(sum))
//SC-O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isPossible(int arr[], int mid, int m, int n){
        int count  = 1;
        long long sum = 0;
        for(int i =0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                
                count++;
                if(count>m || arr[i]>mid){
                    return false;
                }
                sum = arr[i];
            }
        }
        return true;
    }
  public:
    
    long long findPages(int n, int arr[], int m) {
        
        if(m>n) return -1;
        long long st = 0;
        long long sum =0 ;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long end = sum;
        long long ans = -1;
        while(st<=end){
            long long mid = st+(end-st)/2;
            if(isPossible(arr,mid,m,n)){
                ans = mid;
                end = mid-1;
            }
            else {
                st = mid+1;
            }
        }
        return ans ;
    }
};


//Q2. Painter Partition problem - java code
//TC-O(n long(Sum))
//SC-O(1)

//{ Driver Code Starts
//Initial Template for Java

// import java.io.*;
// import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line1[] = read.readLine().trim().split("\\s+");
            int k = Integer.parseInt(input_line1[0]);
            int n = Integer.parseInt(input_line1[1]);
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[n];
            for(int i = 0; i < n; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            
            Solution ob = new Solution();
            System.out.println(ob.minTime(arr,n,k));
        }
    }
}


 class Solution{
     private static boolean isPossible(int arr[], int n, int k, long mid){
         int pCount = 1;
         int pSum = 0;
        for(int i=0;i<n;i++){
            if(pSum+arr[i] <= mid){
                pSum+=arr[i];
            }else{
                pCount++;
                if(pCount>k || arr[i]>mid){
                    return false;
                }
                pSum = arr[i];
            }
        }
        return true;
     }
    static long minTime(int[] arr,int n,int k){
        //code here
       
        long st = 0;
        long sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long end = sum;
        long  ans = -1;
        while(st<=end){
            long mid = st+(end-st)/2;
            if(isPossible(arr,n,k,mid) == true ){
                ans = mid;
                end = mid-1;
            }else{
                st=mid+1;
            }
        }
        
        return ans;
    }
}

//Q3. Aggresive cows 
//-TC-O(n log(max-min))
//SC-O(1)


class Solution {
    public static boolean isPossible(int[] arr, int n, int k, int mid){
        Arrays.sort(arr);
        int count =1 ;
        int lastPos = arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]-lastPos >= mid){
                count++;
                if(count == k) return true;
                lastPos = arr[i];
            }
        }
        
        return false;
    }
    public static int solve(int n, int k, int[] dis) {
        int st = 0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            max = Math.max(max, dis[i]);
            min=Math.min(min,dis[i]);
        }
        int end = max-min;
        int ans = -1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(isPossible(dis,n,k,mid) == true ){
                ans = mid;
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
}

//Q4. Find peak element in mountain (leetcode -162)
//TC-O(logn)
//SC-0(1)

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int st = 0;
        int end = arr.size()-1;
        if(st == end ) return st;
        if(arr[0]>arr[1]) return 0;
        if(arr[end]>arr[end-1]) return end;
        st = 1;
        end = arr.size()-2;
        while(st<=end){
                int mid = st+(end-st)/2;
                if(arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1]) return mid;
                else if(arr[mid]>=arr[mid-1]) st = mid+1;else end=mid-1;
        }

        return -1;
    }
};