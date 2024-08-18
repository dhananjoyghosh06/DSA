// Q1. Deque or double ended queue implementation using array
//TC-O(1)
//SC-O(n)
#include <iostream>
#include<queue>
using namespace std;

class Deque{
  int* arr;
  int front;
  int rear;
  int size;
  public:
  Deque(int n){
      size = n;
      arr = new int[size];
      front =-1;
      rear = -1;
  }
  void push_front(int val){
      if((front == 0 && rear == size-1) || (rear == (front-1 + size) % size)){
        cout << "Queue is full" << endl;
        return;
    }
      else if(front ==-1 ){
        front =0;
        rear =0;
        
      }
      else if (front ==0 && rear != size-1){
          front = size-1;
          
      }
      else{
          front--;
          
      }
      
      arr[front] = val;
      return ;
  }
  void push_rear(int val){
      if((front==0 && rear == size-1) ||(rear==(front-1)%(size-1))){
         cout<<"Queue is full yaar"<<endl;
          return;
      }
      else if(front ==-1 && rear ==-1){
          front = rear = 0;
      }else if(rear == size-1 && front !=0){
          rear = 0;
      }else{
          rear = rear+1;
      }
      arr[rear] = val;
      return;
  }
  int pop_front(){
      int ans = arr[front];
      arr[front]=-1;
      if(front == -1 && rear ==-1){
          cout<<"Queue is empty"<<endl;
          return -1;
      }
      else if (front== rear){
          rear = -1;
          front =-1;
      }
      else if (front == size-1){
          front =0;
      }else{
          front ++;
      }
      
      return ans;
  }
  int pop_rear(){
      int ans = arr[rear];
      arr[rear]=-1;
      cout<<ans<<endl;
      if(front == -1 && rear ==-1){
          cout<<"Queue is empty yaar"<<endl;
          return -1;
      }
      else if (front == rear ){
          front = rear = -1;
      }
      else if (rear == 0){
          rear =size-1;
      }else{
          rear--;
      }
      
      return ans;
  }
  int getRear(){
      if(front ==-1 && rear==-1){
          cout<<"No rear"<<" ";
          return -1;
      }
      return arr[rear];
  }
  int getFront(){
      if(front ==-1 && rear==-1){
          cout<<"No Front"<<" ";
          return -1;
      }
      return arr[front];
  }
  void FR(){
      cout<<getRear()<<endl;
      cout<<getFront()<<endl;
  }
  void printA(){
      for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";
      }cout<<endl;
  }
};
int main() {
    
    Deque d(10);
    d.push_front(10);
    d.push_front(20);
    d.push_rear(30);
     d.push_rear(40);
     d.push_front(50);
    d.push_front(60);
    d.push_rear(70);
     d.push_rear(80);
     d.push_front(90);
     d.push_rear(100);
     d.printA();
     cout<<d.pop_rear()<<" popped"<<endl;
     cout<<d.pop_front()<<" popped"<<endl;
     d.FR();
     d.printA();
    return 0;
}