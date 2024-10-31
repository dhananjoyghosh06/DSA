//Q1. Sum of Nodes on the longest path from root to leaf node
//TC-O(N)
//SC-O(H)

class Solution {
    class Result {
        int maxLen;
        int maxSum;
        
        Result() {
            maxLen = 0;
            maxSum = Integer.MIN_VALUE;
        }
    }
    
    public int sumOfLongRootToLeafPath(Node root) {
        Result result = new Result();
        solve(root, 0, 0, result);
        return result.maxSum;
    }
    
    private void solve(Node root, int len, int sum, Result result) {
        if (root == null) {
            // Update result based on max length or max sum if lengths are equal
            if (len > result.maxLen) {
                result.maxLen = len;
                result.maxSum = sum;
            } else if (len == result.maxLen) {
                result.maxSum = Math.max(sum, result.maxSum);
            }
            return;
        }
        
        // Add current node's value to sum
        sum += root.data;
        
        // Recurse for left and right subtrees
        solve(root.left, len + 1, sum, result);
        solve(root.right, len + 1, sum, result);
    }
}


//Q2. Lowest Common Ancestor
//TC-O(N)
//SC-O(N)

class Solution2
{
    //Function to return the lowest common ancestor in a Binary Tree.
	Node lca(Node root, int n1,int n2)
	{
		// Your code here
		if(root == null) return null;
		if(root.data ==  n1 || root.data == n2){
		    return root;
		} 
		
		Node left = lca(root.left,n1,n2);
		Node right = lca(root.right,n1,n2);
		
		if(left != null && right !=null) return root;
		else if(left!=null) return left;
		else if(right!=null) return right;
		else return null;
	}
}

//Q3. K sum Paths
//TC-O(N*N)
//SC-O(h)

class Solution3 {
    class Result {
        int ans;
        
        Result() {
            this.ans = 0;
        }
    }
    public int sumK(Node root, int k) {
        // code here
        List<Integer> path = new ArrayList<>();
        
        Result r = new Result();
        
        solve(root,k,path,r);
        
        return r.ans;
    }
    private void solve(Node root, int k, List<Integer>path, Result r){
        if(root == null){
            return ;
        }
        path.add(root.data);
        solve(root.left,k,path,r);
        solve(root.right,k,path,r);
        
        int len = path.size();
        int sum = 0;
        for(int i= len-1; i>=0;i--){
            sum+=path.get(i);
            if(sum==k) r.ans +=1;
        }
        
        path.remove(len-1);
    }
}

//Q4.Find K'th ancestor in a binary tree
//Approach 1
//TC-O(N)
//SC-O(H + N(recursive stack))

void solve(Node* root, int k, int node, vector<int>&path, int &ans){
    if(root == nullptr) return ;
    
    path.push_back(root->data);
    if(root->data == node){
        int size = path.size();
        int idx = size-k-1;
         if (idx >= 0) { // Ensure idx is within bounds
            ans = path[idx];
        } else {
            ans = -1; // No kth ancestor exists
        }
        return;
    }
    
    solve(root->left,k,node,path,ans);
    solve(root->right,k,node,path,ans);
    
    path.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    if(root == nullptr) return -1;
    vector<int> path;
    int ans;
    solve(root,k,node,path,ans);
    return ans;
}

//optimised approach
//TC-O(n)
//SC-O(h)


class Solution
{
    class Result{
        public int k;
        Result(int k){
            this.k = k;
        }
    }
        Node solve(Node root, Result r , int node){
        if(root == null) return null;
        if(root.data == node ){
            return root;
        }
        
        Node left = solve(root.left,r,node);
        Node right = solve(root.right,r,node);
        
        
        if(left!=null && right ==null){
            r.k--;
            if(r.k<= 0) {
                r.k=Integer.MAX_VALUE;
                return root;
            }
            return left;
        } 
         if(left==null && right !=null){
            r.k--;
            if(r.k<= 0) {
                r.k=Integer.MAX_VALUE;
                return root;
            }
            return right;
        } 
         return null;
        
        
}
    public int kthAncestor(Node root, int k, int node)
    {
        //Write your code here
        Result r = new Result(k);
        Node ans = solve(root,r,node);
        if(ans.data == node || ans == null){
            return -1;
        }
        return ans.data;
    }
}