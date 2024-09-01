//Q1. Heap implementation
//TC-O(logn) for insertion and O(n) for deletion
//SC-O(1)


#include<iostream>
using namespace std;

class heap {
    int arr[100];
    int size;
    public:
    heap(){
        this->size = 0;
    }
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index]= val;
        
        while(index>1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index= parent;
            }else return;
        }
        return ;
    }
    int deleteNode(){
        if(size ==  0){
            cout<<"Nothing to delete "<<endl;
            return -1;
        }
        int ans =arr[1];
        arr[1] = arr[size];
        arr[size ] =0;
        size = size-1;
        //position it 
         int index = 1;
        while(index<=size){
            int left = 2*index ;
            int right = 2*index+1;
            
            if(left<=size && arr[left]>arr[index]){
                swap(arr[index],arr[left]);
                index = left;
            }
            if(right<=size && arr[right]>arr[index]){
                 swap(arr[index],arr[right]);
                 index = right;
            }else return ans;
            
        }
        return ans;
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<' ';
        }cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    cout<<h.deleteNode()<<endl;
    cout<<h.deleteNode()<<endl;
    h.print();
    
    return 0;
}


//Buildcheap 
//TC-O(n * logn)
//SC-O(1)
#include<iostream>
using namespace std;
void heapify(int arr[], int n, int  index){
    int largest = index;
    int left = 2*index;
    int right = 2*index +1;
    
    if(left<=n && arr[left]>arr[index]){
     
        index = left;
    }
    if(right<=n && arr[right]>arr[index]){
     
        index = right;
    }
    
    if(largest !=index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,index);
    }
    
    
}
void BuildHeap(int arr[], int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}
int main(){
    int arr[6] = {-1,54,53,55,52,50};
    BuildHeap(arr,5);
    for(int it :arr)
    cout<<it<<" ";
    cout<<endl;
    return 0;
}