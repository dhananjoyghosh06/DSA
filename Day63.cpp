//Q1. Flatten a linked list 
//TC-O(nlogn)
//SC-O(n)

class Solution {
    // Function to flatten a linked list
    private Node merge(Node head1 , Node head2){
        if(head2 == null) return head1;
        if(head1==null) return head2;
        
        Node result = new Node(0);  // Temporary dummy node
        Node temp = result;
        
        // Iteratively merge two lists
        while (head1 != null && head2 != null) {
            if (head1.data <= head2.data) {
                temp.bottom = head1;
                head1 = head1.bottom;
            } else {
                temp.bottom = head2;
                head2 = head2.bottom;
            }
            temp = temp.bottom;
        }
        
        // If there are remaining nodes in either list, append them
        if (head1 != null) {
            temp.bottom = head1;
        } else {
            temp.bottom = head2;
        }
        
        return result.bottom;
        
        
    }
    Node flatten(Node head) {
        // code 
        if(head == null || head.next == null){
            return head;
        }
        
        Node curr = head;
        while(curr.next!=null){
            curr= curr.next;
            head = merge(head, curr);
        }
        
        return head;
    }
}

// Q2. Merge k sorted Lists 
//TC-O(m*n)
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
    ListNode* merge(ListNode* head1, ListNode* head2){
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;
         ListNode* result = new ListNode(0);
         ListNode* temp = result ;
         while(head1!=nullptr && head2!=nullptr){
            if(head1->val<=head2->val){
                temp->next = head1;
                head1= head1->next;
            }
             else{
                temp->next = head2;
                head2= head2->next;
            }
            temp = temp->next;
         }
          if (head1 != nullptr) {
            temp->next = head1;
        } else {
            temp->next = head2;
        }
        return result->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        else if(n==1) return lists[0];
         ListNode* left = lists[0];
         
        for(int i=1;i<n;i++){
            ListNode* right = lists[i];
            left = merge(left, right); 

        }
        return left;
    }
};

//Q3.   Linked List Matrix
//TC-O(n*n)
//SC-O(n*n)

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& arr) {
        // code Here
        int row = arr.size();
        int col = arr[0].size();
        Node* ans[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               ans[i][j] = new Node(arr[i][j]);
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                Node* currNode = ans[i][j];
                if(i<row-1){
                    currNode->down = ans[i+1][j];
                }
                if(j<col-1){
                    currNode->right = ans[i][j+1];
                }
                
            }
        }
        
       
       return ans[0][0];
    }
};