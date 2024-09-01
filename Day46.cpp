//  Q1. Heap sort 
//TC-O(nlogn)
//SC-O(1)

#include <iostream>
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
void heapSort(int arr[], int n){
    int t = n;
    while(t>1){
        swap(arr[t], arr[1]);
        t--;
        
        heapify(arr,t,1);
    }
}
void BuildHeap(int arr[], int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}
int main() {
    
    int arr[9] = {-1,55,53,54,75,81,67,52,51};
    int n = 8;
    BuildHeap(arr,n);
    heapSort(arr,n);
    for(int it : arr){
        cout<<it<<' ';
    }cout<<endl;
    return 0;
}