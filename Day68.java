//  Q1. Implementation of Binary tree
//Subquestions->
/*
    1. Build tree by recursion 
    2. levelOrder Traversal
    3. Inorder Traversal
    4. PreOrder Traversal
    5. PostOrder Traversal
*/

// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
 class Node{
     int data ;
     Node left;
     Node right;
    Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Day68 {
   
    public static void main(String[] args) {
        Node root = null;
        root = buildTree(root);
        levelOrderTraversal(root);
        inOrder(root);
        System.out.println();
        preOrder(root);
        System.out.println();
        postOrder(root);
    }
     private static Node buildTree(Node root){
        System.out.println("Enter the data");
        int data;
        Scanner sc = new Scanner(System.in);
        data =sc.nextInt();
        root = new Node(data);
        if(data == -1){
            return null;
        }
       System.out.println("Enter data for the left node of "+ data);
        
        root.left = buildTree(root.left);
       System.out.println("Enter data for the right node of "+ data);
        
        root.right = buildTree(root.right);
        
        return root;
    }
    private static void levelOrderTraversal(Node root){
        if(root == null) System.out.println("Tree is empty");
        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);
        queue.offer(null);
        while(!queue.isEmpty()){
            Node temp = queue.poll();
           if(temp == null){
               System.out.println();
               if(!queue.isEmpty()){
                   queue.offer(null);
               }
           }
           else{
                if(temp.left != null){
                    queue.offer(temp.left);
                }
                if(temp.right !=null){
                    queue.offer(temp.right);
                }
                System.out.print(temp.data + " ");
           }
        }
        System.out.println("->Ended");
    }
    private static void inOrder(Node root){
        if(root==null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.data+" ");
        inOrder(root.right);
        
    }
    private static void preOrder(Node root){
        if(root == null){
            return;
        }
        System.out.print(root.data+" ");
        preOrder(root.left);
        preOrder(root.right);
    }
    private static void postOrder(Node root){
        if(root==null) return ;
        
        
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data+ " ");
    }
}

//Q2. Count the leaves in a binary tree 
//TC-O(n)
//SC-O(n) -- recursive stack

class Tree
{
    int countLeaves(Node root) 
    {
         // Your code  
         //1 10 39 5
         int count = 0;
         if(root.left == null && root.right == null){
             
             return 1;
         }
         if(root.left !=null){
             count+=countLeaves(root.left);
         }
         if(root.right !=null){
             count+=countLeaves(root.right);
         }
        
         return count;
    }
}

//Q3. Height of a tree
//TC-O(n)
//TC-O(n)

class Solution {
    //Function to find the height of a binary tree.
    int height(Node node) 
    {
        // height is the longest path between root and leaves
        if(node == null) return 0;
        int heightLeftSides = height(node.left);
        int heightRightSides = height(node.right);
        
        int ans = Math.max(heightLeftSides,heightRightSides)+1;
        
        return ans;
    }
}