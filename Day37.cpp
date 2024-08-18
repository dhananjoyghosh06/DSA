//Q1. Implement Queue using an array
//TC- O(1)
//SC- O(n)

// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
class Queue{
    int* arr;
    int qfront;
    int rear;
    int size;
    public:
    Queue(int size){
        this->size = size;
        arr = new int[size];
        this->qfront = 0;
        this->rear = 0;
    }
    
    void enQueue(int val){
        if(rear == this->size){
            cout<<"Queue is full"<<endl;
            return;
        }else{
            arr[rear++]= val;
        }
    }
    int deQueue(){
        if(qfront==rear) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                rear =0;
                qfront =0;
                
            }
            return ans;
        }
    }
    int front(){
        if(qfront == rear ){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            return arr[qfront];
        }
    }
    int sizeofQ(){
        return rear-qfront;
    }
};

int main() {
    //create  a queue 
    int size = 10;
    Queue q(size);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(20);
    cout<<q.front()<<endl;
     cout<<q.sizeofQ()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.sizeofQ()<<endl;
     cout<<q.deQueue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.sizeofQ()<<endl;
    return 0;
}


//Q2 - Cicular Queue Implementation
//TC- O(1)
//SC- O(n)
//There is small mistake to find the size of the queue (((How to find the size)))
// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;

class cQueue{
    int* arr;
    int rear;
    int qfront;
    int size;
    public:
    cQueue(int size){
        this->size = size;
        arr = new int[size];
        qfront =-1;
        rear = -1;
    }
    
    void push(int val){
        if((qfront ==0 && rear == size-1 ) || (rear == (qfront-1)%(size-1))){
            cout<<"Queue is full"<<endl;
            return;
        }
        else{
            if(qfront ==-1){
                rear =0;
                qfront=0;
                arr[rear]= val;
            }else
            {
                rear = (rear+1)%(size);
                arr[rear] = val;
            }
        }
    }
    int pop(){
        //check empty
        if(qfront ==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            int ans =-1;
            //handle when queue has a single element
            if(qfront == rear){
                ans = arr[qfront];
                arr[qfront]=-1; // assigning -1 to indicate emptyness on that block
                rear = qfront =-1;
                return ans;
            }
            else if(qfront == size-1){
                ans = arr[qfront];
                arr[qfront]=-1; // assigning -1 to indicate emptyness on that block
                qfront = 0;
                return ans;
            }
            else{
                ans = arr[qfront];
                arr[qfront]=-1; // assigning -1 to indicate emptyness on that block
                qfront++;
                
                return ans;
            }
        }
    }
    int front(){
        if(qfront ==-1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else return arr[qfront];
        
    }
    int sizeofQ(){
        if(front !=1 && rear == front) return 1;
        else if(front == -1) return 0;
        else {
            if(front>rear){
                int ans = front - rear;
            }
        }
        
    }
    void printArr(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }
};
int main() {
    //create  a queue 
    int size = 3;
    cQueue q(size);
    cout<<q.pop()<<endl; //empty //-1
    q.push(10);
    q.push(20);
    q.push(30);
   
    cout<<"front of the queue "<<q.front()<<endl; //40
    cout<<q.pop()<<endl; //10
    cout<<q.pop()<<endl; //20
    cout<<"front of the queue "<<q.front()<<endl; //40
    cout<<q.pop()<<endl; //30
    q.push(40);
    q.push(50);
    cout<<"front of the queue "<<q.front()<<endl; //40
    return 0;
}