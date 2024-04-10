//  Question - Count Inversions in an array 
// Method used - Merge Sort 
//Learned and enjoyed alot by doing this 



//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge( long long arr[], long long st, long long end ){
    long long mid = st+(end-st)/2;
    long long left = mid-st+1;
    long long right = end-mid;
    
    long long* first = new long long[left];
    long long* second = new long long[right];

    
    long long k = st;
    for(long long i =0 ;i<left;i++){
        first[i] = arr[k++]; 
    }
    k= mid+1;
    for(long long i = 0 ; i<right;i++){
        second[i] = arr[k++];
    }
    
    long long idx1=0; 
    long long idx2=0; 
    long long idx =st;
    long long count =0;
    
    while(idx1<left && idx2 < right){
        if(first[idx1]<=second[idx2]){
            arr[idx++] = first[idx1++];
        }
        else{
            count+=left-idx1;
            arr[idx++]=second[idx2++];
        }
    }
    while(idx1<left){
         arr[idx++] = first[idx1++];
    }
    while(idx2<right){
        arr[idx++]=second[idx2++];
    }
    return count;
}
long long mergeSort (long long arr[], long long st, long long end ){

    if(st>=end) return 0;
    
    long long ans=0;
    
    long long mid = st+(end-st)/2;
    
    ans+=mergeSort(arr,st, mid);
   ans+= mergeSort(arr,mid+1, end);
    ans+= merge(arr, st , end);
    return ans;
}
long long int inversionCount(long long arr[], long long N)
{   
    // Your Code Here
    long long st = 0;
    long long end = N-1;
    return mergeSort(arr,st, end);
   
}

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends