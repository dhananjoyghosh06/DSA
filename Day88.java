public class Day88 {
    public static void main(String[] args){
        int[] arr1 = {1,3,4,5};
        int[] arr2 = {3,4,6,7};

        int n = arr1.length+arr2.length;
        int ans[] = new int[n];
        int p1=0;
        int p2=0;
        int p=0;
        
        while(p1<arr1.length && p2<arr2.length){
            if(arr1[p1]<=arr2[p2]){
                ans[p++] = arr1[p1++];
            }else{
                ans[p++] = arr2[p2++];
            }
        }
        while(p1<arr1.length){
            ans[p++] = arr1[p1++];
        }
        while(p2<arr2.length){
            ans[p++] = arr2[p2++];
        }


        for(int it : ans){
            System.err.print(it + " ");
        }
    }
}
