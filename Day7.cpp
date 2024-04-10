// Merge Sort 
//TC- O(nlog(n))
//SC-O(n)

void merge(vector < int > & arr, int st, int end){
    int mid = st+(end-st)/2;
    int len1 = mid -st+1;
    int len2 = end-mid;
    //creating new arrays
    int *first = new int[len1];
    int *second = new int[len2];
    //storing the values by half number of elements in the array left part
    int k = st;
    for (int i = 0 ; i<len1;i++){
        first[i] = arr[k++];
    }
    //string the values by half number of elements in the array right part
    k = mid+1;
    for (int i = 0 ; i<len2;i++){
        second[i] = arr[k++];
    }
    
    int idx1 = 0;
    int idx2 = 0;
    int idx = st;
    //now merging and sorting and stoting the element into the main array by sorted
    while(idx1<len1 && idx2<len2){
        if(first[idx1]>second[idx2]){
            arr[idx++] = second[idx2++];
        }
        else{
            arr[idx++] = first[idx1++];
        }
    }
    
    while(idx1<len1){
        arr[idx++] = first[idx1++];
    }
     while(idx1<len2){
        arr[idx++] = second[idx2++];
    }
    delete []first;
    delete []second;
    
}
void mergesort(vector < int > & arr,int st, int end){
    int mid = st+(end-st)/2;
    if(st>=end) return ;
    //left part solve
    mergesort(arr, st, mid);
    mergesort(arr, mid+1, end);
    
    merge(arr, st, end);
}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    int st = 0;
    int end = n-1;
    mergesort(arr, st, end);

}
