//Q1. Implementation of Singly LinkedList
#include <iostream>
using namespace std;

class LinkedListNode{
    public:
    int data;
    LinkedListNode* next;
    LinkedListNode(int data){
        this->data = data;
        this->next = NULL;
    }
    ~LinkedListNode(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtEnd(LinkedListNode* &tail,int newData){
    LinkedListNode* newNode = new LinkedListNode(newData);
    tail->next = newNode;
    tail=tail->next;
}
void insertAtSt(LinkedListNode* &head,int newData){
    LinkedListNode* newNode = new LinkedListNode(newData);
    LinkedListNode* temp = head;
    head = newNode;
    head->next = temp;

}
void insertAtPosition(LinkedListNode* &head, LinkedListNode* &tail,int pos, int newData){
    LinkedListNode* temp = head;
    
    //inserting at first position 
    if(pos == 1){
        insertAtSt(head, newData);
        return ;
    }
    int count = 1;
    while(count<pos-1){
        count ++;
        temp =temp->next;
    }
    if(temp->next == NULL){
        insertAtEnd(tail,newData);
        return ;
    }
    LinkedListNode* newNode = new LinkedListNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(LinkedListNode* &head, int pos){
    if(pos == 1){
        LinkedListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    LinkedListNode* current = head;
    LinkedListNode* previous = NULL;
    int count = 1;
    LinkedListNode* temp = head;
    while(count<pos){
        previous = current ;
       current = current ->next;
       count++;
    }
    previous->next = current->next;
    current->next = NULL;
    delete current;
}
void printLinkedListNode(LinkedListNode* &head){
    LinkedListNode* temp = head;
    cout<<"head->";
    while(temp!=NULL){
        cout<<temp->data <<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}
int main() {
    
    LinkedListNode* head = new LinkedListNode(10);
    LinkedListNode* tail = head;
    insertAtEnd(tail,20);
    insertAtSt(head,30);
    insertAtSt(head,40);
    insertAtEnd(tail,50);
    insertAtEnd(tail,60);
    insertAtPosition(head,tail,1,5);
    insertAtPosition(head,tail,8,100);
     insertAtEnd(tail,200);
     deleteNode(head,4);
    printLinkedListNode(head);
    return 0;
}

//Q2. Insert Greatest Common Divisors in Linked List //Leetcode 2807
//TC-O(n)
//SC-O(1)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *      : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    int findGcd(int val1, int val2){
        if(val1==0) return val2;
        return findGcd(val2%val1,val1);
    }
    public:
    ListNode* insertGreatestCommonDivisors(ListNode* &head) {
       
        if(head->next == nullptr){

           
            return head;
        }
        ListNode* current = head;
        ListNode* previous = nullptr;
        while(current->next !=nullptr){
            previous= current;
            current = current->next;
            int a = findGcd(previous->val, current->val);
            ListNode* newNode = new ListNode(a);
            previous->next = newNode;
            newNode->next = current;
           
        }
        return head;
    }
};
// Normal Loop method

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if(head== NULL ) return head;
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            Node* prev = curr;
            while(temp!=NULL){
                if(curr->data== temp->data){
                    Node* dupN = temp->next;
                    Node* nodeTD= prev->next;
                    delete nodeTD;
                    prev->next = dupN;
                    temp = prev->next;
                }
                 else{
                     prev = temp;
                     temp = temp->next;
                 } 
             
            }
            curr= curr->next;
        }
       return head;
    }
};


//Q6. Remove Duplicates from Sorted list
//TC-O(n)
//SC-O(1)

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {

        // code here
        if(head== NULL ) return head;
        Node* curr = head;
        while(curr!=NULL){
            if((curr->next !=NULL) && (curr->data == curr->next->data)){
                Node* dup = curr->next->next;
                Node* temp  = curr->next;
                 delete temp;
                 curr->next =dup;
            }  
            else {
                curr= curr->next;
            }
        }
       return head;
    }
};