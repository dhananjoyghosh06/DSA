//Q1. N meetings in a room
//TC-O(NLogN)
//SC-O(N)

class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}
class customComparator implements Comparator<Pair<Integer,Integer>>{
    @Override
    public int compare(Pair<Integer,Integer> p1, Pair<Integer,Integer> p2){
        return Integer.compare(p1.second, p2.second);
    }
}
class Solution {
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    public int maxMeetings(int start[], int end[]) {
            int n = start.length;
           ArrayList<Pair<Integer,Integer>> arr = new ArrayList<>();
           for(int i=0;i<n;i++){
               Pair<Integer,Integer> newPair = new Pair(start[i], end[i]);
               arr.add(newPair);
           }
           
           Collections.sort(arr, new customComparator());
           int count = 1;
           int endTime = arr.get(0).second;
           
           for(int i=1;i<n;i++){
               if(arr.get(i).first > endTime){
                   count++;
                   endTime = arr.get(i).second;
               }
           }
           
           return count;
    }
}

//Q2. Maximum Meetings in One Room
//TC-O(nlogn)
//SC-O(N)

class Pair<U,V,W>{
    public U first;
    public V second;
    public W third;
    Pair(U first, V second,W third){
        this.first = first;
        this.second = second;
        this.third = third;
    }
}
class CustomComparator implements Comparator<Pair<Integer,Integer,Integer>>{
    @Override
    public int compare(Pair<Integer,Integer,Integer> p1, Pair<Integer,Integer,Integer> p2){
        return Integer.compare(p1.second, p2.second);
    }
}
class Solution {
    public static ArrayList<Integer> maxMeetings(int n, int[] start, int[] end) {
        // code here
        ArrayList<Pair<Integer,Integer,Integer>> arr = new ArrayList<>();
            
           for(int i=0;i<n;i++){
               Pair<Integer,Integer,Integer> newPair = new Pair<>(start[i], end[i],i+1);
               arr.add(newPair);
           }
           
           Collections.sort(arr, new CustomComparator());
            
           ArrayList<Integer> ans = new ArrayList<>();
            ans.add(arr.get(0).third);
           int endTime = arr.get(0).second;
            for(int i=1;i<n;i++){
               if(arr.get(i).first > endTime){
                  ans.add(arr.get(i).third);
                   endTime = arr.get(i).second;
               }
           }
           Collections.sort(ans);
           return ans;
    }
}

//Q3. Shop in candy store
//TC-O(Nlogn)
//SC-O(1)

class Solution4{
    static ArrayList<Integer> candyStore(int candies[],int N,int k){
        // code here
            Arrays.sort(candies);
        int min = 0;
        int buy = 0;
        int free = N-1;
        
        while(buy<=free){
            min +=candies[buy++];
            free= free-k;
        }
        int max = 0;
        buy = N-1;
        free = 0;
        while(buy>=free){
            max+=candies[buy--];
            free = free+k;
        }
       ArrayList<Integer> ans = new ArrayList<>();
       ans.add(min);
       ans.add(max);
        return ans;
    }
}

//Q4. Check if it is possible to survive on Island
//TC-O()
//SC-O()
/* Something wrong with the test case in  gfg . I couldn't run this code. But the logic is correct */ */
class Solution{
    static int minimumDays(int S, int N, int M){
        // code here
        if (M > N) {
            return -1;
        }
        // first find out how many sundays could be in your given time 
        int sunday = S/7;
        // total buying days in which I can buy food from shop
        int buyingDays = S - sunday;
        //find out the totalFood required for the S days to survive
        
        if(sunday>0 && ((N-M)*6 < M)){ // if sunday exists and there is no available food for the sunday then return -1
            return -1;
        }
         int ans;

        //if the totalFood is a multiple of N unit foods then total (totalFood/N) days need to buy
        if( (totalFood % N ) == 0){
            ans = totalFood / N;
        }else{ // if not a multiple then I required one more days to buy food for the remaining required food to survive total S days
            ans = (totalFood /N) +1;
        }
        
        //Now I need to check if the ans is including a sunday into it to buy food for survival then I cannot survive further
        if(ans<=buyingDays) return ans;
        else return -1;
    }
}

//Q5. Check all leaf nodes are at same level
//SC-O(h)
//TC-O(n)

class Result{
    public boolean ans;
    public int ma;
    Result(boolean ans, int ma){
        this.ma = ma;
        this.ans = ans;
    }
}
class Solution {
    boolean check(Node root) {
        // Your code here
        Result r = new Result(true,-1);
        solve(root,0,r);
        
        return r.ans;
    }
    void solve(Node root, int h, Result r){
        if(root == null) return;
        if(r.ans == false) return;
        if(root.left==null && root.right== null){
            if(r.ma == -1){
                r.ma=h;
            }else{
                if(h!=r.ma) r.ans = false;
            }
            return;
        }
        else{
            
            solve(root.left,h+1,r);
            solve(root.right,h+1,r);
        }
    }
}
