//Q1. Implementation of Doubly Linked list 
//TC-O()
//SC-O()
//Q1. Implementation of Doubly Linked list 
//TC-O()
//SC-O()

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

int main(){
    dllNode* head = new dllNode(10);
    insertAtPosition(100,1,head);
     insertAtPosition(200,2,head);
      insertAtPosition(300,3,head);
    print(head);
    //  deleteNode(1,head);
     deleteNode(5,head);
        print(head);
    return 0;
}



//Q2. Implementation of Circular Linkedlist

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
  public  :
  int data;
  Node* next;
  Node(int data ){
      this->data  = data;
      this->next = NULL;
  }
  ~Node(){
      if(next!=NULL){
          delete next;
          next =NULL;
      }
  }
};
void insertAtNode(Node* &tail, int element, int data){
    Node* newNode = new Node(data);
    if(tail==NULL){
        tail= newNode;
        newNode->next = newNode;
        return ;
    }
    else {
        Node* curr = tail;
        while(curr->data!=element){
            curr= curr->next;
        }
        
        newNode->next = curr->next;
        curr->next = newNode;
        return ;
    }
    
}
void print(Node* tail){
    Node* temp = tail;
    cout<<"Tail->";
    do{
        cout<<tail->data<<"->";
        tail=tail->next;
    }while(tail!= temp);
    cout<<"NULL"<<endl;
}
void deleteNode(Node* &tail, int val){
    if(tail==NULL){
        cout<<"Nothing to delete "<<endl;
        return;
    }
    Node* prev = tail;
    Node* curr= prev->next;
    
    while(curr->data != val){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    //this condition is for if there is one node present in the linkedlist and I'm wanting to delte that  particular node present in the ll 
    if(curr == prev ){
        tail=NULL;
    }
    if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    
}
int main() {
    Node* tail  =NULL;
    insertAtNode(tail,5,5);
     insertAtNode(tail,5,10);
      insertAtNode(tail,10,15);
     insertAtNode(tail,15,20);
      insertAtNode(tail,5,25);
     insertAtNode(tail,5,30);
    insertAtNode(tail,5,5);
  
     deleteNode(tail,5);
       deleteNode(tail,30);
    print(tail);
    

    return 0;
}