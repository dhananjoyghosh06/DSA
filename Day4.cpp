// Q1 : Peak Index in a mountain Array (LeetCode - 852(medium))
//Method used - Binary Search
//TC- O(log(n))
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int st = 0;
        int end = n-1;
        while(st<end) {
            int mid = st+(end-st)/2;
            if(arr[mid]< arr[mid+1]) st=mid+1;
            else end = mid;
        }
        return st;
    }
};

// Q2.  Square root of x 
//Method used - Binary Search (Leetcode- 69(medium))
//TC - O(log(n))

class Solution {
public:
    int mySqrt(int x) {
        int st = 0;
        int end= x;
        int ans =-1;
        while(st<=end){
            long long int mid = st+(end-st)/2;
            long long int sq = mid*mid;
            if(sq == x) return mid;
            else if (sq<x) {
                ans =mid;
                st = mid+1;
            }
            else {
             end = mid-1;  
            }
        }

        return ans;
               
    }
};