//Implement N queues in a single stack 
//TC-O(1)
//SC-O(n)+O(2k)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class NQ{
  int n ; //size of the array;
  int k; //number of queues ;
  int *front; // front of each queue;
  int *rear; // rear of each queue ;
  int *arr; // the array where we want to insert queue elements ;
  int *next; //to store next free spot ;
  int freespot; //freespot;
  public :
  NQ(int n, int k){
      this->n =n;
      this->k = k;
      front = new int[k];
       rear = new int[k];
      for(int i=0;i<k;i++){
          front[i]=rear[i]=-1;
      }
     
      arr = new int[n];
      next = new int[n];
      for(int i=0;i<n-1;i++){
          next[i] = i+1;
      }
      next[n-1]= -1;
      freespot = 0;
  }
  void push(int val, int nq){
      if(freespot ==-1){
          cout<<"Q is empty"<<endl;
          return;
      }
      int index = freespot;
      freespot = next[index];

      
      if(front[nq-1] ==-1){
          front[nq-1] = index;
      }else{
          //link new element to the previous element of the queue
          
          next[rear[nq-1]] = index;
      }
      //update next
      next[index] = -1;
      //update the rear;
      rear[nq-1] = index;
      arr[index] = val;
  }
   int pop(int qn){
       if(front[qn-1] == -1){
           cout<<"Queue underflow"<<endl;
           return -1;
       }
       //find the index where we want to pop the element
       int index =  front[qn-1];
       front[qn-1] = next [index];
       //manage the freespot
       next[index] = freespot;
       freespot = index;
       arr[index]=0;
       return arr[index];
   }
   
   void print(){
       cout<<"Arr print"<<endl;
       for(int i=0;i<n;i++){
           cout<<arr[i]<<" ";
       }cout<<endl;
        cout<<"Next print"<<endl;
       for(int i=0;i<n;i++){
           cout<<next[i]<<" ";
       }cout<<endl;
        cout<<"Front print"<<endl;
       for(int i=0;i<k;i++){
           cout<<front[i]<<" ";
       }cout<<endl;
        cout<<"Rear print"<<endl;
       for(int i=0;i<k;i++){
           cout<<rear[i]<<" ";
       }cout<<endl;
       cout<<"freespot -> "<<freespot<<endl;
   }
};
int main() {
   NQ a(8,3);
   a.push(10,1);
   a.push(20,1);
   a.push(15,2);
   a.push(101,3);
   a.push(30,1);
 
   a.pop(1);
   a.push(101,3);
   a.print();
    

    return 0;
}


//Q2. Find the sum of the maximum and minimum element of the widow the of size k 
//TC-O(n*k)
//SC-O(k)+O(k)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(int k, int n , int *arr){
    deque<int>maxi(k);
    deque<int>mini(k);
    //1st window
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()] <=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int sum =0;
    for(int i=k;i<n;i++){
        sum += (arr[maxi.front()]+arr[mini.front()]);
   
        
        //removal of the prev window
        while(( !maxi.empty() && (i-maxi.front()))>=k){
            maxi.pop_front();
        }
         while(!mini.empty() && (i-mini.front())>=k){
            mini.pop_front();
        }
        
        //add the new element of the new window
        while(!maxi.empty() && arr[maxi.back()] <=arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >=arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    
    //for the last window 
    sum += (arr[maxi.front()]+arr[mini.front()]);
    
    
    return sum;
}


int main() {
   int arr[7]={2,5,-1,7,-3,-1,2};
   int k =4;
    cout<<solve(k,7,arr);
    return 0;
}
