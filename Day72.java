// Q1. Maximum sum of Non-adjacent nodes
//TC-O(N)
//SC-O(H)

class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}
class Solution
{
    //Function to return the maximum sum of non-adjacent nodes.
    static int getMaxSum(Node root)
    {
        // add your code here
        Pair<Integer, Integer> ans = new Pair(0,0);
        ans = solve(root);
        
        return Math.max(ans.second, ans.first);
    }
    static Pair<Integer,Integer> solve(Node root){
        Pair<Integer, Integer> ans = new Pair(0,0);
        if(root == null){
            return ans;
        }
        Pair<Integer, Integer> left = solve(root.left);
        Pair<Integer, Integer>right = solve(root.right);
        
        ans.first = root.data + left.second + right.second;
        ans.second = Math.max(left.first, left.second) + Math.max(right.first, right.second);
        
        return ans;
    }
}
