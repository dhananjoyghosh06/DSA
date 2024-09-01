//Q1. Implement queue using stack

//SC-O(1);

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class queueUsingStack{
    stack<int>st;
    int front;
    
    void deleteFromBottom(int count,int n){ //O(n)
      
        if(st.empty()){
            return ;
        }
        
        int val = st.top();
        st.pop();
        count +=1;
        deleteFromBottom(count,n);
        if(count !=n){
           st.push(val);
        }
        count --;
        
    }
     void setFrontAfterPop(int count,int n){ //O(n)
        if(st.empty()){
            return ;
            
        } 
        int val =st.top();
        st.pop();
        count++;
        setFrontAfterPop(count,n);
        
        if(count == n){
            this->front = val;
        }
        count--;
        st.push(val);
    }
    public:
    queueUsingStack(){
        front =-1;
    }
    void push(int val){ //O(1)
        if(front ==-1){
            this->front= val;
        }
        st.push(val);
        return ;
    }
    void pop(){ // O(n+n) -O(n)
        if(front ==-1){
            cout<<"Queue is empty"<<endl;
            return ;
        }
       deleteFromBottom(0,st.size());
       
        if(st.empty()){
            front=-1;
        }
        else setFrontAfterPop(0,st.size());
       
    }
    int getFront(){
        return this->front;
    }
};
int main()
{
    queueUsingStack a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);
     cout<<a.getFront()<<endl;
    a.pop();
    cout<<a.getFront()<<endl;
    a.pop();
    cout<<a.getFront()<<endl;
     
    a.pop();
    cout<<a.getFront()<<endl;
    a.pop();
    cout<<a.getFront()<<endl;
     a.pop();
    cout<<a.getFront()<<endl;
    a.pop();
    cout<<a.getFront()<<endl;
    a.pop();
    cout<<a.getFront()<<endl;
    
}