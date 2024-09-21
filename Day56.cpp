//Q1. Implementation of Circular Linked List


#include<bits/stdc++.h>
using namespace std;

class dllNode{
    public:
    int data;
    dllNode* next;
    dllNode* prev;
    dllNode(int data){
        this->data = data;
        this->prev= NULL;
        this->next = NULL;  
    }
    ~dllNode(){
        int val = this->data;
        if(this->next !=NULL){
            delete this->next;
            next =NULL;
        }
    }
};

void print(dllNode* & head){
    dllNode* temp = head;
    cout<<"head->";
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }   cout<<"NULL"<<endl;
    
}
void insertAtTailInDLL(int data, dllNode* & head){
    dllNode* temp = head;
    dllNode* newNode = new dllNode(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev = temp;

}
void insertInHeadInDLL(int data, dllNode* &head){
    if(head == NULL){
      dllNode* newNode = new dllNode(data);
      head = newNode;
      return ;
    }
        dllNode* temp = head;
        dllNode* newNode = new dllNode(data);
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
}
void insertAtPosition(int data,int pos,dllNode* &head){
    if(pos== 1) {
        insertInHeadInDLL(data,head);
        return ;
    }
    dllNode* temp = head;
    int count =0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(count+1<pos) {
        cout<<"Position is not valid"<<endl;
        return;
    }
    if(pos== count+1 ){
        insertAtTailInDLL(data,head);
        cout<<"called"<<endl;
        return ;
    }
    count = 1;
    dllNode* newNode = new dllNode(data);
    dllNode* curr=head;
    dllNode* nextNode =NULL;
    if(curr->next!=NULL)
     nextNode= curr->next;
    while(curr->next!=NULL && count<pos-1){
        curr=curr->next;
        nextNode = curr->next;
        count++;
    }
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = nextNode;
    if(nextNode!=NULL)
    nextNode->prev = newNode;
}
void deleteNode(int pos ,dllNode* &head){
     dllNode* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp= temp->next;
        count++;
    }
    if(head == NULL || pos>count){
        cout<<"There is no node into that posoition to delete"<<endl;
        return;
    }
    if(pos == 1 ){
        temp = head;
       
        head = head -> next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return ;
    }
     count = 1;
    dllNode* curr = head;
    while(curr!=NULL && count <pos){
        curr= curr->next;
        count++;
    }
    curr->prev->next = curr->next;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}   
void reverseLinkedList( dllNode* &head){
     dllNode* temp = head;
      
     while(temp->next!=NULL){
        temp->prev= temp->next;
        temp->next->prev=NULL;
        temp->next->next = temp;
        temp->next= temp->next->next;
        head = temp;
        temp=temp->next;
    }
}
int main(){
    dllNode* head = new dllNode(10);
    insertAtPosition(100,1,head);
     insertAtPosition(200,2,head);
      insertAtPosition(300,3,head);
    print(head);
    //  deleteNode(1,head);
     deleteNode(5,head);
     print(head);
     reverseLinkedList(head);
        print(head);
    return 0;
}

//Q2. Reverse a Doubly Linked List -- Approach 1 by using stack
//TC-O(n)
//SC-O(n)

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        stack<DLLNode*>st;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        Node* temp ;
        while(!st.empty()){
            DLLNode* top = st.top();
            if (top == nullptr) {
            return nullptr;
        }
         temp = top;
        top = top->prev;
        if (top != nullptr) {
            top->next = nullptr;
        }
        temp->prev = nullptr;  // Disconnect from the previous node
       
        }
        return temp;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution ob;
        head = ob.reverseDLL(head);

        printList(head);
        cout << "\n";
    }
    return 0;
}

// Approach 2 -- swapping 
//TC-O(n)
//SC-0(1)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        DLLNode* curr = head;
        DLLNode* temp = NULL;
        while(curr!=NULL){
            temp  = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        
        head = temp->prev;
        return head;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution ob;
        head = ob.reverseDLL(head);

        printList(head);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

//Q3. Check a linked list is circular or not - brute force 
//TC-O(n)
//SC-O(1)
bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL) return true;
    else if(head->next ==NULL) return false;
    else if(head->next == head) return true;

    Node* temp = head->next;
    while(temp!=NULL && temp !=head){
        
        temp=temp->next;
        
    }
    if(temp ==head) return true;
    return false;


}

//Optimal Approach 
//TC-O()
//SC-O()







//Q4. Detect Cycle in a linkedlist and remove the cycle 
//Brute force approach
//TC-O(n)
//SC-O(n)


struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
       
    unordered_set<Node*> mpp;
    
    Node* prev = NULL;
    while(head!=NULL){
        if(mpp.find(head)==mpp.end()){
            mpp.insert(head);
            prev = head;
            head = head->next;
        }else{
            prev->next =NULL;
            break;
        }
        
    } 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        unordered_map<Node*, int> myMap;

        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
    }
    return 0;
}

//Optimal Approach (Floyd's cycle detection algorithm)
//TC-O(n)
//SC-O(n)




struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};



class Solution {
    Node* getStPoint(Node* slow, Node* fast){
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
       if(head == NULL) return ;
        Node* slow = head;
        Node* fast = head;
    
           while(fast!=NULL && fast->next!=NULL){
               fast = fast->next->next;
               slow = slow->next;
               if(slow == fast ){
                  Node* stPoint = getStPoint(head, fast);
                  Node* temp = stPoint;
                  while(temp->next !=stPoint){
                      temp= temp->next;
                  }
                  temp->next = NULL;
               }
           }
    }     
};

// } Driver Code Ends


//Q5. Remove duplicates from a unsorted linked list
//TC-O(n)
//SC-O(n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_set<int>st;
        Node* curr = head;
        Node* prev = NULL;
        while(curr!=NULL){
           
            if(st.find(curr->data) != st.end()){
                
                prev->next = curr->next;
                delete curr;
                
            }
            else {
                st.insert(curr->data);
            prev = curr;
            }
            curr = prev->next;
            
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        printList(result);
    }

    return 0;
}

// } Driver Code Ends

