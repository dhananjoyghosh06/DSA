//Q1. Construct binary tree using preorder  and inorder traversal 
//TC-O(n*n)
//SC-O(n)

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import javax.swing.tree.TreeNode;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 class Result{
    public int index;
    Result(int idx ){
        this.index = idx;
    }
 }
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        int preOrderIndex = 0;
        Result r = new Result(preOrderIndex);
        return solve(preorder, inorder, n, r, 0, n-1);
    }
    private TreeNode solve(int[] preorder, int[] inorder, int n, Result r, int inorderSt,int inorderEnd){
        if( (r.index>=n) || (inorderSt>inorderEnd ) ){
            return null;
        }

        int element = preorder[r.index++] ;
        TreeNode root = new TreeNode(element);
        int position = findPosition(inorder,element,n);
        if(position == -1) return null;
        root.left = solve(preorder, inorder, n,r,inorderSt,position-1);
        root.right = solve(preorder,inorder,n,r,position+1, inorderEnd);

        return root;
    }
    private int findPosition(int[] inorder, int element, int n){
        for(int i=0;i<n;i++){
            if(inorder[i] == element){
                return i;
            }
           
        }
         return -1;
    }
}

//Optimised Approach using mapping
//TC-O(Nlogn)
//SC-O(N)


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

 class Result{
    public int index;
    public HashMap<Integer,Integer>mpp;
    Result(int idx ){
        this.index = idx;
        this.mpp = new HashMap<>();
    }
 }
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        int preOrderIndex = 0;
        Result r = new Result(preOrderIndex);
        createMap(inorder,r,n);
        return solve(preorder, inorder, n, r, 0, n-1);
    }
    private TreeNode solve(int[] preorder, int[] inorder, int n, Result r, int inorderSt,int inorderEnd){
        if( (r.index>=n) || (inorderSt>inorderEnd ) ){
            return null;
        }

        int element = preorder[r.index++] ;
        TreeNode root = new TreeNode(element);
        int position = r.mpp.get(element);
        if(position == -1) return null;
        root.left = solve(preorder, inorder, n,r,inorderSt,position-1);
        root.right = solve(preorder,inorder,n,r,position+1, inorderEnd);

        return root;
    }
    private void createMap(int[] inorder, Result r, int n){
        for(int i=0;i<n;i++){
           r.mpp.put(inorder[i], i);  
        }
    }
}


//Q2. Construct binary tree using Postorder and inorder traversal 
//TC-O(Nlogn)
//SC-O(n)

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Result2{
    public int index;
    public HashMap<Integer,Integer>mpp;
    Result(int idx ){
        this.index = idx;
        this.mpp = new HashMap<>();
    }
 }
class Solution2 {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
         int n = postorder.length;
        int preOrderIndex = n-1;
        Result r = new Result(preOrderIndex);
        createMap(inorder,r,n);
        return solve(postorder, inorder, n, r, 0, n-1);
    }
    private TreeNode solve(int[] postorder, int[] inorder, int n, Result r, int inorderSt,int inorderEnd){
        if( (r.index<0) || (inorderSt>inorderEnd ) ){
            return null;
        }

        int element = postorder[r.index--] ;
        TreeNode root = new TreeNode(element);
        int position = r.mpp.get(element);
        if(position == -1) return null;
        root.right = solve(postorder,inorder,n,r,position+1, inorderEnd);
        root.left = solve(postorder, inorder, n,r,inorderSt,position-1);
        

        return root;
    }
    private void createMap(int[] inorder, Result r, int n){
        for(int i=0;i<n;i++){
           r.mpp.put(inorder[i], i);  
        }
    }
}

//Q3. Minimum time to burn a tree 
//TC-O(N)
//SC-O(N)

class Solution5
{
    public static int minTime(Node root, int target) 
    {
        // Step 1: Create a map to store parent pointers and a map for visited nodes
        HashMap<Node, Node> nodeToParent = new HashMap<>();
        HashMap<Node, Boolean> isVisited = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        
        Node targetNode = null;
        q.offer(root);
        nodeToParent.put(root, null);
        
        // Step 2: Perform BFS to find the target node and set parent pointers
        while (!q.isEmpty()) {
            Node front = q.poll();
            
            if (front.data == target) {
                targetNode = front;
            }
            if (front.left != null) {
                nodeToParent.put(front.left, front);
                q.offer(front.left);
            }
            if (front.right != null) {
                nodeToParent.put(front.right, front);
                q.offer(front.right);
            }
        }
        
        // Step 3: BFS to simulate the burning process
        int timeElapsed = 0;
        q.offer(targetNode);
        isVisited.put(targetNode, true);
        
        while (!q.isEmpty()) {
            int n = q.size();
            boolean hasBurnedNewNode = false;
            
            for (int i = 0; i < n; i++) {
                Node front = q.poll();
                
                // Check left child
                if (front.left != null && !isVisited.getOrDefault(front.left, false)) {
                    hasBurnedNewNode = true;
                    q.offer(front.left);
                    isVisited.put(front.left, true);
                }
                
                // Check right child
                if (front.right != null && !isVisited.getOrDefault(front.right, false)) {
                    hasBurnedNewNode = true;
                    q.offer(front.right);
                    isVisited.put(front.right, true);
                }
                
                // Check parent node
                Node parentNode = nodeToParent.get(front);
                if (parentNode != null && !isVisited.getOrDefault(parentNode, false)) {
                    hasBurnedNewNode = true;
                    q.offer(parentNode);
                    isVisited.put(parentNode, true);
                }
            }
            
            // Increment time if new nodes were burned
            if (hasBurnedNewNode) {
                timeElapsed++;
            }
        }
        
        return timeElapsed;
    }
}

//Q4. Morris Traversal for Inorder 
//TC-O(n*n)
//SC-O(1)

static List<Integer> inOrder(Node root) {
    List<Integer> result = new ArrayList<>();
    Node curr = root;

    while(curr!=null){
        if(curr.left != null){
            Node predecessor = curr.left;
            while(predecessor.right !=null && predecessor.right !=curr){
                predecessor = predecessor.right;
            }
            if(predecessor.right == null){
                predecessor.right = curr;
                
                curr = curr.left;
            }else{
                predecessor.right = null;
                result.add(curr.data);
                curr = curr.right;
            }
        }else{
            result.add(curr.data);
            curr = curr.right;
        }
    }

    return result;
}

//Q5. Flatten binary tree a linkedlist 
//TC-O(N)
//SC-O(1) --- When we get that we need to do something with binary tree with O(1) TC then we should use of look upon Morris Traversal

class SolutionR
{
    public static void flatten(Node root)
    {
        //code here
        Node curr = root;
        while(curr != null){
            if(curr.left != null){
                Node pred = curr.left;
                while(pred.right != null && pred.right != curr.right){
                    pred = pred.right;
                }
                pred.right = curr.right;
                curr.right = curr.left;
                curr.left = null;
            }
            curr = curr.right;
        }
        
    }
}
