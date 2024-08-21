//Nstack in an single array 
//TC-O(1)
//SC-O(k+n);

#include<iostream>
#include<vector>
using namespace std;

class Nstack{
    int n; // size of the array;
    int k; //number of stack;
    int freeSpot;
    vector<int>next;
    vector<int>top;
    public:
    Nstack(int size, int numOfStack){
        this->n= size;
        this->k=numOfStack;
        this->freeSpot = 0;
        next.resize(n);
        top.resize(k);
        for(int i=0;i<n-1;i++){
            next[i]=i+1;
        }
        next[n-1] = -1;
        for(int i=0;i<k;i++) top[i]=-1;
    }
    void push(vector<int>&arr, int val, int stackNum){
        if(freeSpot ==-1) {
            cout<<"Stack is Empty";
            return;
        }
        int i = freeSpot;
        freeSpot= next[i];
        arr[i]= val;
        next[i]= top[stackNum-1];
        top[stackNum-1] = i;
    }
    int getTop(int stackNum){
        return top[stackNum-1];
    }
    void pop(vector<int>&arr, int stackNum){
        if(top[stackNum-1] == -1) return ;
        int i = top[stackNum-1]; // i= 6
        top[stackNum-1] = next[i]; // top[1]=7;
        arr[i]=-1;
        next[i]=freeSpot; // next[i] =6
        freeSpot = i; // freSpot = 6;
        // return arr[i];
    }
};
int main(){
    vector<int>nums(10, -1);
    Nstack n(10,3);
    n.push(nums,10,1);
    n.push(nums,20,1);
     n.push(nums,30,2);
    n.push(nums,40,2);
     n.push(nums,50,3);
    n.push(nums,60,3);
      n.push(nums,70,1);
      n.pop(nums,1);
    for(auto it : nums){
        cout<<it<<' ';
    }cout<<endl;
    
    cout<<n.getTop(1)<<endl;
}

//Insert an element at the bottom of a stack
//SC-O(1)
//TC-O(n)


#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int val = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(val);
}
int main() {
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    int element = 100;
    insertAtBottom(st,element);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }cout<<endl;
    return 0;
}

//Q3. Insert an element at the kth position from the top in a stack
//SC-O(1)
//TC-O(n+n+k)
void insertAtKposition(stack<int>&st, int element, int k ,int count){
        if(count>=(st.size()-k)){
            st.push(element);
            return;
        }
        int val = st.top();
        st.pop();
        count++;
        insertAtKposition(st,element,k,count);
        st.push(val);
        
}
int main() {
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    int element = 100;
   
    insertAtKposition(st,element,3,0);
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }cout<<endl;
    
    return 0;
}

//Q4. Reverse a stack 
//TC-O(n*n)
//SC-O(1)
void insertAtBottom(stack<int>&st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int val = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(val);
}
void reverseStack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int val = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,val);
}
int main() {
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    int element = 100;
     
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }cout<<endl;
    
    return 0;
}