// Q . Quick Sort 
//TC-O(nlogn)   
//SC- O(n)
#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int st, int end ){
    int pivot = arr[st];
    int count = 0;
    for(int i= st;i<= end;i++){
        if(arr[i]<pivot) count++;
    }
    int pIdx = st+count;
    swap(arr[pIdx], arr[st]);
    
    int i=st, j=end;
    while(i<pIdx && j>pIdx){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        
        swap(arr[i++], arr[j++]);
    }
    
    return pIdx;
}
void quickSort(int arr[], int st, int end){
    if(st>=end) return ;
    
    int p = partition(arr, st, end);
    quickSort(arr, st, p-1);
    quickSort(arr, p+1,end);
}

int main() {
    int arr [5] = { 8, 5, 2, 6, 1};
    for(int i =0 ;i<=4;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    quickSort(arr, 0, 4);
    
    for(int i =0 ;i<=4;i++){
        cout<<arr[i]<<" ";
    }cout<<" ";
    
    return 0;
}

//Q2. Subsets using recursion  Leetcode(78)
// Method used - Recursion
// TC - 2^n
//SC- 2^n

class Solution {
public:
    void edit(vector<int> nums, vector<vector<int>>&ans ,  vector<int>op, int i){
        if(i>=nums.size()) {
            ans.push_back(op);
            return ;
        }
        //exclude 
        edit(nums, ans, op, i+1)
        ;
        //include
        int ele = nums[i];
        op.push_back(ele);
        edit(nums,ans,op,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;

        edit(nums,ans,op,0);

        return ans;
    }
};