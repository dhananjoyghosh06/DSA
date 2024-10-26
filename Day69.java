//Q1. Diameter of a tree
//TC-O(n*n)
//SC-O(n*n)


class SolutionH {
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0;
        int op1 = diameterOfBinaryTree(root.left);
        int op2 = diameterOfBinaryTree(root.right);
        int op3 = height(root.left)+ height(root.right);
        int op4 =  Math.max(op1,op2);
        return Math.max(op3,op4);
    }
    private int height(TreeNode root){
        if(root == null) return 0;

        int left = height(root.left);
        int right = height(root.right);

        return Math.max(left,right)+1;
    }
}



//Optimal Approach
//TC-O(n)
//TC-O(h)


class SolutionG {
    public int diameterOfBinaryTree(TreeNode root) {
        int[] ans = new int[2];
        ans = solve(root);

        return ans[0];
    }
    private int[] solve(TreeNode root){
        if(root == null) return new int[]{0,0};

        int [] left =  new int[2];
        int [] right =  new int[2];

        left = solve(root.left);
        right = solve(root.right);
        int total = left[1]+right[1];
        
        int diameter = Math.max(total,Math.max(left[0], right[0]));
       int height = Math.max(left[1],right[1])+1;

    
        return new int[]{diameter, height};
    }
}

//Q2. Check for a balanced tree 
//TC-O(n*n)
//SC-O(h)


class SolutionD {
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;

       return  isBalanced(root.left) && isBalanced(root.right) && Math.abs( getHeight(root.left) - getHeight(root.right) )<= 1;

    }
    private int getHeight(TreeNode root ){
        if(root ==  null) return 0;

        int left = getHeight(root.left);
        int right  = getHeight(root.right);

        return Math.max(left,right)+1;
    }
}

//Optimal  Approach
//SC-O(n)
//TC-O(n)


class SolutionF {
    public boolean isBalanced(TreeNode root) {
        return getHeight(root) != -1;
    }
    private int getHeight(TreeNode root){
        if(root == null) return 0;

        int left = getHeight(root.left);
        if(left == -1) return -1;
        int right = getHeight(root.right);
        if(right == -1) return -1;

        int height = Math.abs(left- right);
        if(height>1) return -1;

        return Math.max(left, right)+1;
    }
}

//Q3. Check weather two given tree is identical or not ?
//TC-O(n)
//SC-O(n)
class Solution0
{
    
	boolean isIdentical(Node root1, Node root2)
	{
	    // Code Here
	    if(root1 == null && root2== null){
	        return true;
	    }
	    else if(root1==null){
	        return false;
	    }else if(root2 == null){
	        return false;
	    }
	    
	    return isIdentical(root1.left, root2.left) && isIdentical(root1.right, root2.right) && (root1.data == root2.data);
	}
	
}

//Q4. Check a binary tree is Sumtree or not ?
//TC-O(n)
//SC-O(n)

class Solution1 {
    boolean isSumTree(Node root) {
        
        return helper(root) != -1;
    }
    int helper(Node root){
        if(root == null) return 0;
        if(root.left == null && root.right ==  null) return root.data;
        
        
        int leftSum = helper(root.left);
        if(leftSum == -1) return -1;
        int rightSum = helper(root.right);
        if(rightSum == -1) return -1;
        
        int totalSum = leftSum + rightSum;
        if(totalSum == -1) return -1;
        
        if(totalSum == root.data) return totalSum+root.data;
        else return -1;
    }
}

//Q5. Zigzag Level Order traversal 
//TC-O(n)
//SC-O(n)

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean l2r = true;
        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> temp = new ArrayList<>(size);
            
            for(int i=0;i<size;i++){
                TreeNode front = q.poll();
                //int idx = (l2r==true) ? i : size-i-1; -> this logic is used for c++.here in java let's use something else because of some arrList feature
                if(l2r == true)
                temp.add( front.val);
                else temp.add(0,front.val);
                if(front.left != null){
                    q.offer(front.left);
                }
                if(front.right != null){
                    q.offer(front.right);
                }
            }
            l2r =!l2r;
            ans.add(temp);
        }


        return ans;
    }
}

//Q6. Boundary level Traversal in tree
//TC-O(n)
//SC-O(height)

class SolutionBLT
{
	ArrayList <Integer> boundary(Node root)
	{
	    ArrayList<Integer> ans = new ArrayList<Integer>();
	    if(root == null) return ans;
	    if(root.left == null && root.right == null){
	         ans.add(root.data);
	         return ans;
	     }
	    
	    ans.add(root.data);
	    leftPart(root.left, ans);
	    leafNodes(root, ans);
	    rightPart(root.right,ans);
	    
	    return ans;
	 }
	 void leftPart(Node root, ArrayList<Integer>ans){
	     if(root == null) return;
	     if(root.left == null && root.right == null){
	         return ;
	     }
	     ans.add(root.data);
	     if(root.left != null)
	      leftPart(root.left, ans);
	     else leftPart(root.right, ans);
	 }
	 void leafNodes(Node root, ArrayList<Integer>ans){
	     if(root==null) return;
	     if(root.left== null && root.right == null){
	         ans.add(root.data);
	         return;
	     }
	     
	     leafNodes(root.left, ans);
	     leafNodes(root.right, ans);
	 }
	 void rightPart(Node root, ArrayList<Integer>ans){
	     if((root == null) || (root.left == null && root.right == null)){
	         return ;
	     }
	     
	     if(root.right != null)
	      rightPart(root.right, ans);
	     else rightPart(root.left, ans);
	     ans.add(root.data);
	 }
}
