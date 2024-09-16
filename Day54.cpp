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

//Approach