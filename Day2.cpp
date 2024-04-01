// Question -  Given an array of size n. The task is to rotate array by d elements where d ≤ n.

// step1 : Create  a function which is reversing an array one time 
// step2 : Call the function one with parameter( arr, st=0, end= d-1) which reverses the part1 which is 0 to d-1 ;
//step3 : call the function one which parameter (arr, st= d , end = n) which revereses the part2 which is d to n ;
//step4 : call the function one which parameter (arr, st = 0 , end=n) which reverses the part3 which is 0 to n-1 ;
//TC- O(log(n)+O(log(n/2))+O(log(n/2))) ~= O(log(n))
//SC- O(1)

void reverse(int arr[], int st, int end){
    while(st<end){
        int temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;
        st++;
        end--;
    }
}
void leftRotate(int arr[], int n, int d) {
    d= d%n;
    // code here
   reverse(arr, 0, d-1);
   reverse(arr, d, n-1);
   reverse(arr, 0, n-1);
    
}