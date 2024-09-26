//Q1.  Write a program to move the last element to front in a linked list.
//TC-O(n)
//SC-O(1)
//Approach 1
class Solution {
  public:
    Node *moveToFront(Node *head) {
     
        // Base case
        if(head == NULL ||head->next == NULL){
            return head;
        }
        // declare two pointers
        Node* last =head;
        Node* prev = nullptr;
        while(last->next !=NULL ){
            prev = last;
            last= last->next;
        }
        prev->next =NULL;
        last->next = head;
        head = last;
        
        return head;
    }
};

//Q2. Add "1" to a number represented by linked list.
//TC-O(n)
//SC-O(1)

class Solution {
    Node* reverseLL(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next= prev;
            prev =curr;
            curr= next;
        }
        return prev;
    }
  public:
    Node* addOne(Node* head) {
        // No base case becasue the length 
        // the ll should greater than or equal to 1
        Node* rHead = reverseLL(head);
        Node* temp = rHead;
        int carry =0;
        
        while(temp!=NULL){
            int val;
            
            if(temp == rHead){
                
                val= (temp->data + 1)%10;
                carry = (temp->data + 1)/10;
            }else{ 
                 val = (temp->data + carry)%10;
                 carry = (temp->data + carry)/10;
            }
            temp->data = val;
            if(temp->next == NULL && carry>0){
                Node* newNode = new Node(carry);
                temp->next = newNode;
                break;
            }
            temp= temp->next;
            
        }
        
        head = reverseLL(rHead);
        
        return head;
    }
};

//Q3. Intersection of two linked list
//TC-O(m+n)
//SC-O(n+m)

class Solution {
    private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = head;
            return;
        }
        tail->next = newNode;
        tail= newNode;
    }
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        Node* temp1= head1;
        Node* temp2 = head2;
        
        Node* ans = NULL;
        Node* ansTail = NULL;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data == temp2->data){
                insertAtTail(ans,ansTail,temp1->data);
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->data > temp2->data){
                temp2=temp2->next;
            }else{
                temp1=temp1->next;
            }
        }
        
        return ans;
    }
};

//Q4. Find the intersection point of two Linked lists
//TC-O(m+n)
//SC-O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int len1= 0;
        
        while(temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }
        int len2= 0;
        while(temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }
        

        temp1 = headA;
        temp2 = headB;
        if(len1>len2){
            int diff = len1-len2;
            int count =0;
            while(temp1!=NULL && count<diff){
                temp1 = temp1->next;
                count++;
            }
        }else{
            int diff = len2-len1;
            int count =0;
            while(temp2!=NULL && count<diff){
                temp2 = temp2->next;
                count++;
            }
        }

        
        while(temp1!=temp2 && temp1!=NULL && temp2!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return temp1;
    }
};

//Q5. Quick sort on LL
//TC-O(nlogn)
//SC-O(n)

class Solution {
    private :
    struct Node* partition(struct Node* head, struct Node*tail){
        //take the  first node as pivot
        struct Node* pivot = tail;
        
        //take prev and curr pointer to shifft the 
        //lesser values in the left side and greater
        //values in the right sides
        
        struct Node* prev = head;
        struct Node* curr = head;
        // traverse the list until it crosses the tail pointer 
        while(curr!=tail->next){
            if(curr->data < pivot->data){
                swap(curr->data,prev->data);
                prev = prev->next;
            }
            curr= curr->next;
        }
        swap(prev->data, pivot->data);
        return prev;
        
    }
    void quickSortHelper(struct Node* head, struct Node* tail){
        //base case 
         if (head == NULL || head == tail || head == tail->next) {
            return;
        }
        
       struct Node* pivot = partition(head, tail);
       
       if (pivot != head) {
            struct Node* temp = head;
            while (temp->next != pivot) {
                temp = temp->next;
            }
            quickSortHelper(head, temp);  // Sort the left side of the pivot
        }
        
        quickSortHelper(pivot->next, tail);
       quickSortHelper(pivot->next, tail);
        
        
    }
  public:
    struct Node* quickSort(struct Node* head) {
        // code here
        if(head == NULL) return head;
        struct Node* tail =head;
        while(tail->next !=NULL){
            tail = tail->next;
        }
        // helper function
        quickSortHelper(head,tail);
        
        return head;
    }
};