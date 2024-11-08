//Q1. Iterative approach of postorder with one stack 
//TC-O(N)
//SC-O(N)

class Tree
{
    //Function to return a list containing the postorder traversal of the tree.
    ArrayList<Integer> postOrder(Node root)
    {
       // Your code goes here
       ArrayList<Integer> ans = new ArrayList<>();
       
       if(root == null) return ans;
       
       Stack<Node> st = new Stack<>();
       Node curr = root;
       while(!st.isEmpty() || curr != null){
           while(curr!=null){
               st.add(curr);
               curr = curr.left;
           }
           // move to the right part
           if(st.peek().right != null){
               curr = st.peek().right;
           }else{
               Node temp = st.pop();
               ans.add(temp.data);
               while(!st.isEmpty() && st.peek().right == temp){
                    temp = st.pop();
                    ans.add(temp.data);   
               }
               
           }
       }
       
       return ans;
    }
}

//Two Stack approach
//SC-O(N)
//TC-O(N)
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        
        List<Integer> ans = new ArrayList<Integer>();
        if(root == null) return ans;
       Stack<TreeNode> st = new Stack<>();
       Stack<TreeNode> st2 = new Stack<>();
       st.add(root);
       while(!st.isEmpty()){
           TreeNode temp = st.pop();
           st2.add(temp);
           if(temp.left!=null){
               st.add(temp.left);
           }
           if(temp.right != null){
               st.add(temp.right);
           }
       }
       
       while(!st2.isEmpty()){
          TreeNode curr = st2.pop();
           ans.add(curr.val);
       }
       
       return ans;
    }
}

//Inorder Traversal using iteration 
//SC-O(N)
//TC-O(N)

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer> ();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = root;
        while(curr!= null || !stack.isEmpty()){
            while(curr!= null){
                stack.add(curr);
                curr= curr.left;
            }
            curr= stack.pop();
            ans.add(curr.val);
            curr = curr.right;
        }

        return ans;
    }
}

//Q3. Iterative approach of Preorder Traversal
//TC-O(N)
//SC-O(N)

class Solution {
    private List<Integer> ans = new ArrayList<> ();
    public List<Integer> preorderTraversal(TreeNode root) {
            if(root == null) return ans;

            Stack<TreeNode> stack = new Stack<>();
            TreeNode curr = root;
            while(curr!=null || !stack.isEmpty()){
                while(curr!=null){
                    ans.add(curr.val);
                    stack.add(curr);
                    curr = curr.left;
                }
                curr = stack.pop();
                curr = curr.right;
            }

            return ans;
    }
}