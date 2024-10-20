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