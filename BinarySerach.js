let arr = [
    2,3,6,8,10,12,14,16,18,19
];

let target = 18;

const binarySearch= (arr,target)=>{
        let st = 0;
        let end = arr.length-1;
        while(st<=end){
            let mid = Math.floor(st+(end-st)/2);
            if(arr[mid]==target) return mid;
            else if (arr[mid]<target) st=mid+1;
            else end = mid-1;
        }
        return -1;
} 

let ans = binarySearch(arr,target);

console.log(ans);
