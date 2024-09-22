//Sort 0, 1 and 2's in LL
//TC-O(n)
//SC-O(3)=O(1)
//Approach 1 
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        vector<int>count(2);
        Node* temp  = head;
        while(temp!=NULL){
           if(temp->data == 0){
               count[0]++;
           }else if(temp->data == 1){
               count[1]++;
           }
           else {
               count[2]++;
           }
            temp= temp->next;
        }
        temp = head;
        for(int i=0;i<=2;i++){
            
            while(count[i]>0 && temp!=NULL){
                temp->data = i;
                count[i]--;
                temp = temp->next;
            }
        }
        return head;
    }
};

//Approach 2 - Three Pointers 
//Three pointer approach is not applicable because it the decrement of the end pointer is not possible in linked list. But we can do this using doubly linked list

//Approach 3
//Heap sort using STL ( priority queue)
//TC-O(n+n)
//SC-O(n)
class Solution {
  public:
   
    Node* segregate(Node* head) {
          Node* temp= head;
          priority_queue<int, vector<int>, greater<int>>pq;
          
          while(temp!=NULL){
              pq.push(temp->data);
             temp = temp->next;
          }
          temp = head;
          
          while(temp!=NULL){
              temp->data = pq.top();
              pq.pop();
              temp=temp->next;
          }
          return head;
    }
};

//Q3. Merge two sorted Linked List 
//TC-O(n)
//SC-O(1)


// Definition for singly-linked list.
//  struct ListNode {
//     int val;
//    ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
    private:
    ListNode* solve(ListNode* list1, ListNode* list2){
        if(list1->next == NULL){
            list1->next = list2;
            return list1;
        }
         ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;;
        ListNode* curr2 = list2;
        ListNode* next2 = NULL;
        while(next1!=NULL && curr2!=NULL){
            if ((next1->val>=curr2->val) && (curr2->val>= curr1->val) ){
                curr1->next = curr2;
                 next2 = curr2->next;
                curr2->next = next1;
                 curr1 = curr2;
                curr2 = next2;
               
            }else{
                curr1 = next1;
                next1 = next1->next;
                if(next1 == NULL){
                    curr1->next = curr2;
                    return list1;
                }
                
            }
        }
        return list1;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;

       
        if(list1->val <= list2->val){
            return solve(list1, list2);
        }else{
            return solve(list2, list1);

        }
        

    }
};

// Q4. Palindromic Linked List 
//TC-O(n)
//SC-O(n)

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
    private:
    bool checkPalindrome(vector<int>nums){
        int n = nums.size();
        if(n==1) return true;
        int st = 0;
        int end = n-1;
        while(st<end){
            if(nums[st]!=nums[end]){
                return false;
            }
            st++;
            end--;

        }

        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        //step1 
        vector<int> ele;
        ListNode* temp = head;
        while(temp!=NULL){
            ele.push_back(temp->val);
            temp = temp->next;
        }

        return checkPalindrome(ele);
    }
};




//2nd Approach 
//TC-O(n)
//SC-O(1)
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
    private :
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            
                fast= fast->next;
                if(fast->next == nullptr){
                    break;
                }
                fast=fast->next;
                slow= slow->next;
          
           
        }

        return slow ;
    }
    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head ->next ==nullptr){
            return true;
        }
        ListNode* middle = findMiddle(head);
        ListNode* temp = middle->next;
        middle->next = reverseLL(temp);
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        while(head2!=nullptr){
            if(head1->val!=head2->val){
                return false;

            }
            head1=head1->next;
            head2=head2->next;
        }

        //making the LL same as start
        temp = middle->next;
        middle->next= reverseLL(temp);

        return true;
    }
};

//Q4. Add two numbers represented by a LL
//TC-O(n)
//SC-O(n) -> for creating the new linked list

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
    //This part based on question on different platforms 

   /* ListNode* reverseLL(ListNode* head){
        if(head == nullptr && head->next == nullptr){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;

     } */
    void insertAtTail(ListNode* &head, ListNode* &tail, int data){
            ListNode* newNode = new ListNode(data);
            if(head == nullptr){
                head = newNode;
                tail= newNode;
                return  ;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
    }
    ListNode* addAll(ListNode* head1, ListNode* head2){
        int carry= 0;
        ListNode* headAns = nullptr;
        ListNode* tailAns = nullptr;
        while(head1!=nullptr || head2!=nullptr || carry!=0){
            int val1 = 0;
            int val2= 0;
            if(head1!=nullptr) val1 = head1->val;
            if(head2!=nullptr)  val2 = head2->val;
            int sum = val1 + val2 + carry;
            int digit = sum %10;
            insertAtTail(headAns,tailAns,digit);
            carry= sum/10;
            if(head1!=NULL)
            head1= head1->next;
            if(head2!=NULL)
            head2=head2->next;
        }
       

        return headAns;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* head1 = reverseLL(l1);
        // ListNode* head2 = reverseLL(l2);

        ListNode* ans = addAll(l1, l2);
        return ans;
    }
};