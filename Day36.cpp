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