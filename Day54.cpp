//Q1. Reverse a linkedlist 
//TC-O(n)
//SC-O(1)



#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode  reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
             
             ListNode* curr = temp->next;
             temp->next=prev;
             prev = temp;
            temp = curr;        
        }
       return prev;

    }
};

//Approach2 -> Recusrive approach in leetcode 



//Q2. Find middle of a LL 
//TC-O(n)
//SC-O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        cout<<count<<endl;
        int mid = count/2+1;
        count = 1;
        temp=head;
        while(count<mid){
         temp=temp->next;
         count++;
        }
        return temp;
    }
};

//Approach 2 : Slow and fast pointer approach
//TC-O()
//SC-O()

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head ;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next !=nullptr){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};


//Q2. Reverse LL in k number of groups -- very very important , tough and logical
//SC-O(n/k) == O(n)
//TC-O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       //base case 
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* curr= head;

        int count = 0;
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k) return head;
        curr= head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
         count = 0;
        while(curr!=nullptr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
            
            count ++;
        }

        if(next != nullptr){
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};

