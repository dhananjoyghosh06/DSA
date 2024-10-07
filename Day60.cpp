#include<bits/stdc++.h>
using namespace std;


//Q1.Find pairs with a given sum in a DLL 
//TC-O(n)
//SC-O(n) // for the ans vector
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        Node* last = head;
        while(last->next!=NULL){
            last = last->next;
        }
        
        vector<pair<int,int>> ans;
        while(head!=last && last->next!=head && head->prev!=last){
                 if( (head->data + last->data) == target ){
                     ans.push_back({head->data,last->data});
                     last = last->prev;
                     head = head->next;
                 }
                 else if( (head->data + last->data) < target){
                     head= head->next;
                 }
                 else{
                     last = last->prev;
                 }
        }
        
        
        return ans;
        
    }
};

//Q2. Triplets in Sorted Linked List
//TC-O(nlogn * n * n)
//SC-O(upto n for ans )

class Solution {
    int threeSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end()); // nlogn
            int ans = 0;
            int n = nums.size();
            for(int i=0;i<n;i++){ // n*n
                
                int j = i+1;
                int k = n-1;
                while(j<k){
                    int sum  =  nums[i] +  nums[j] + nums[k] ;
                    if(sum == target){
                       ans++;
                        j++;
                        k--;
                        
                    }else if(sum > target){
                        k--;
                    }else{
                        j++;
                    }
                }
            }

            return ans;
    }
  public:
    int countTriplets(struct Node* head, int x) {
        // code here.
        //SC-O(upto n)
        vector<int>nums;
        Node* temp = head;
        while(temp){
            nums.push_back(temp->data);
            temp=temp->next;
        }
        
        return threeSum(nums,x);
    }
};