//Q1. Level Order traversal - Brtute force
//TC-O(N*N)
//tc-o(H)

import java.util.ArrayList;

class Day74 {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static class Tree {
        private static int getHeight(Node root) {
            if (root == null)
                return 0;
            int leftH = getHeight(root.left);
            int rightH = getHeight(root.right);

            return Math.max(leftH, rightH) + 1;
        }

        static void helper(Node root, int currH, int reqH, ArrayList<Integer> ans) {
            if (root == null)
                return;
            if (currH == reqH) {
                ans.add(root.data);
                return;
            }

            helper(root.left, currH + 1, reqH, ans);
            helper(root.right, currH + 1, reqH, ans);
        }

        public static ArrayList<Integer> reverseLevelOrder(Node node) {
            int height = getHeight(node);
            ArrayList<Integer> ans = new ArrayList<>();
            for (int i = height; i >= 1; i--) {
                helper(node, 1, i, ans);
            }

            return ans;
        }
    }

    public static void main(String[] args) {
        // create hard-coded tree
        //      1
        //     / \
        //    2   3
        //   / \
        //  4   5
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        ArrayList<Integer> ans = Tree.reverseLevelOrder(root);
        for (int it : ans) {
            System.out.println(it);
        }
    }
}

//Optimal Approach
//TC-O(N)
//SC-O(N)

class Tree
{
    public ArrayList<Integer> reverseLevelOrder(Node root) 
    {
        // code here
        ArrayList<Integer>ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        if(ans == null) return ans;
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            Node front = q.poll();
            st.push(front.data);
             if(front.right != null) q.offer(front.right);
            if(front.left != null) q.offer(front.left);
           
        }
        
        while(!st.isEmpty()){
            ans.add(st.peek());
            st.pop();
        }    
        
        return ans;
    }
}

//Q2. Mirror of a binary tree
//SC-O(n)
//TC-O(n)

void mirror(Node root) {
    // Your code here
     if(root == null) return ;
    mirror(root.left);
    mirror(root.right);
    
    Node temp = root.left;
    root.left = root.right;
    root.right = temp;
}

//Iterative approach
//TC-O(N)
//SC-O(N)

void mirror2(Node node) {
    // Your code here
    Queue<Node> q = new LinkedList<>();
    q.offer(node);
    
    while(!q.isEmpty()){
        Node front = q.poll();
        
       
        Node temp = front.left;
        front.left = front.right;
        front.right = temp;
        if(front.left != null) q.offer(front.left);
        if(front.right != null) q.offer(front.right);
    }
    

}