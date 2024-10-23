//Q1. Count of smaller number after self
//TC-O(nlogn)
//SC-O(n)

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        int[][] v = new int[n][2];
        for(int i=0;i<n;i++){
                v[i][0] = nums[i];
                v[i][1] = i;
        }
        int[] ans = new int[n];
        mergeSort(v,ans,0,n-1);
        List<Integer> ansToR = new ArrayList<Integer>();
        for(int it : ans){
            ansToR.add(it);
        }

        return ansToR;
    }
    private void mergeSort(int[][] v, int[] ans, int st, int end){
        if(st<end){
            int mid = st+(end-st)/2;
            mergeSort(v,ans,st,mid);
            mergeSort(v,ans,mid+1,end);
            merge(v,ans,st,end,mid);
        }
    }
    private void merge(int[][] v, int[] ans, int st, int end, int mid){
        int [][] t = new int [end-st+1][2];
        int i = st;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=end){
            if(v[i][0] > v[j][0]){
                ans[v[i][1]]+= end-j+1;
                t[k][1] = v[i][1];
                t[k][0]=v[i][0];
                i++;
                k++;
            }else{
                t[k][1] = v[j][1];
                t[k][0]=v[j][0];
                j++;
                k++;
            }
        }
         while (i <= mid) {
            t[k][0] = v[i][0];
            t[k][1] = v[i][1];
            k++;
            i++;
        }
        // if any elements left in right array
        while (j <= end) {
            t[k][0] = v[j][0];
            t[k][1] = v[j][1];
            k++;
            j++;
        }
        k=0;
        for(i= st;i<=end;i++,k++){
            v[i][0] = t[k][0];
            v[i][1] = t[k][1];
        }
    }
}