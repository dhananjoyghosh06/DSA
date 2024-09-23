//Q1. Clone a linked list with random pointers 
//TC-O(n)
//SC-O(N)
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->random == NULL && temp2->random != NULL) ||
            (temp1->random != NULL && temp2->random == NULL) ||
            (temp1->random != NULL && temp2->random != NULL &&
             temp1->random->data != temp2->random->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
    private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head== NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
 
    }
  public:
    Node *copyList(Node *head) {
        // Write your code here
        Node* cloneHead = NULL;
        Node* cloneTail= NULL;
        Node* temp = head;
        
        unordered_map<Node* ,Node*>mpp;
        
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            mpp[temp] = cloneTail;
            temp=temp->next;
        }
        Node* oriNode = head;
        Node* cloneNode = cloneHead;
    
        while(oriNode!=NULL){
            cloneNode->random = mpp[oriNode->random];
            cloneNode = cloneNode->next;
            oriNode = oriNode->next;
        }
        return cloneHead;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < arr.size(); ++i) {
            append(&head, &tail, arr[i]);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> arr2;
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Node *temp = head;
        for (int i = 0; i < arr2.size(); i += 2) {
            int a = arr2[i];
            int b = arr2[i + 1];

            Node *tempA = head;
            Node *tempB = head;
            for (int j = 1; j < a; ++j) {
                tempA = tempA->next;
            }
            for (int j = 1; j < b; ++j) {
                tempB = tempB->next;
            }

            tempA->random = tempB;
        }

        Solution ob;
        Node *res = ob.copyList(head);
        if (res == head) {
            cout << "false" << endl;
            continue;
        }
        if (validation(head, res)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

//Optimal Approach 
//TC-O(n)
//SC-O(1)

class Solution {
    private:
    void insertAtTail(Node* &head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head== NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
 
    }
  public:
    Node* copyList(Node* head) {
        if (!head) return NULL;
    
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;

        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

    
        Node* oriNode = head;
        Node* cloneNode = cloneHead;
        
        while (oriNode != NULL && cloneNode != NULL) {
            Node* next = oriNode->next;
            oriNode->next = cloneNode;
            oriNode = next;
             next = cloneNode->next ;
             cloneNode->next = oriNode;
            cloneNode=next;
        }

        // Step 3: Set random pointers for the cloned nodes
        oriNode = head;
        while (oriNode != NULL) {
            if (oriNode->next != NULL) {
             oriNode->next->random = oriNode->random ? oriNode->random->next : NULL;
            }
            oriNode = oriNode->next->next;
        }

        // Step 4: Separate the cloned list from the original list
        oriNode = head;
        cloneNode = cloneHead;
        while (oriNode != NULL && cloneNode != NULL) {
            oriNode->next = cloneNode->next;
            oriNode = oriNode->next;
            if(oriNode!=NULL)
            cloneNode->next = oriNode->next;
            cloneNode= cloneNode->next;
        }

        return cloneHead;
    }
};

//Q2. Merge Sort in Linked list
//TC-O (nlogn)
//SC-O(nlogn)

class Solution {
    private :
    Node* getMiddle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void insertionAtTail(Node* &head, Node* &tailAns, int data ){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode ;
            tailAns= head;
            return ;
        }
        tailAns->next = newNode;
        tailAns = newNode;
    }
    Node* merge(Node* head1, Node* head2){
        if(head1 == NULL) return head2;
        if(head2 ==NULL){
            return head1;
        }
        Node* temp1= head1 ;
        Node* temp2 = head2;
        Node* ans = NULL;
        Node* tailAns= NULL;
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data<=temp2->data){
                insertionAtTail(ans,tailAns,temp1->data);
                temp1 = temp1->next;
            }else{
                 insertionAtTail(ans,tailAns, temp2->data);
                 temp2 = temp2->next;
            }
        }
        while(temp1!=NULL){
             insertionAtTail(ans,tailAns,temp1->data);
                temp1 = temp1->next;
        }
         while(temp2!=NULL){
             insertionAtTail(ans,tailAns,temp2->data);
             temp2 = temp2->next;
        }
        return ans;
    }
    public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
            // base case 
        if(head == NULL || head->next == NULL){
                return head;
        }
        // get the middle node
        Node* mid = getMiddle( head);
            
        //divide the linked list into two parts 
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        //now break down into single pieces using recursion
        left = mergeSort(left);
        right = mergeSort(right);
        
        //merge the left and right both part
        Node* res = merge(left,right);
        
        return res;
    }
};

//Q3. Flatten of a linked list
//TC-O(n*n*m)
//SC-O(n)

class Solution {
  private:
     Node* merge(Node* head1, Node* head2) {
        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;

        // Use bottom pointers instead of creating new nodes
        Node* result;
        if (head1->data <= head2->data) {
            result = head1;
            result->bottom = merge(head1->bottom, head2);
        } else {
            result = head2;
            result->bottom = merge(head1, head2->bottom);
        }

        return result;
    }
  public:
    // Function which returns the  root of the flattened linked list.
     Node* flatten(Node* head) {
        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursively flatten the rest of the list
        head->next = flatten(head->next);

        // Merge this list with the next list
        head = merge(head, head->next);

        return head;
    }
};

//Q4. 