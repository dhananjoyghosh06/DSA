
import java.util.*;


class Methods{
    public void printArray(ArrayList<Integer> arr){
        for(int it : arr){
            System.out.print(it + " ");
        }
        System.out.println();
    }
}
class Node
{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
}    
public class Test {
    private static ArrayList<Integer> levelOrderTraversal(Node root){
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
       
        while(!q.isEmpty()){
            Node front = q.poll();
            ans.add(front.data);
            if(front.left !=null) q.offer(front.left);
            if(front.right != null) q.offer(front.right);
        }
        return ans;
    }
    private static ArrayList<Integer> inorderTraversal(Node root){
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Stack<Node> st = new Stack<>();
        Node curr = root;
        
        while(!st.isEmpty() || curr != null){
            while(curr!=null){
                st.push(curr);
                curr = curr.left;
            }
            curr = st.pop();
            ans.add(curr.data);
            curr = curr.right;
        }
        return ans;
    }
    private static ArrayList<Integer> preorderTraversal(Node root){
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Stack<Node> st = new Stack<>();
        Node curr = root;
        
        while(!st.isEmpty() || curr != null){
            while(curr!=null){
                st.push(curr);
                ans.add(curr.data);
                curr = curr.left;
            }
            curr = st.pop();
            curr = curr.right;
        }
        return ans;
       
    }
    private static ArrayList<Integer> postorderTraversal(Node root){
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Stack<Node> st = new Stack<>();
        Stack<Node> stt = new Stack<>();
        st.push(root);
        while(!st.isEmpty()){
            Node temp = st.pop();
            stt.push(temp);
            if(temp.left!=null){
                st.push(temp.left);
            }
            if(temp.right != null){
                st.push(temp.right);
            }
        }
        while (!stt.isEmpty()) {
            Node top = stt.pop();
            ans.add(top.data);
        }

        return ans;
    }
    private static ArrayList<Integer> postorderTraversalByOneStack(Node root){
        ArrayList<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        Stack<Node> st = new Stack<>();
        Node curr = root;
        while(!st.isEmpty() || curr != null){
            while(curr!=null){
                st.push(curr);
                curr=curr.left;
            }
            if(st.peek().right!= null){
                curr= st.peek().right;
            }else{
                Node temp = st.pop();
                ans.add(temp.data);
                while(!st.isEmpty() && st.peek().right == temp ){
                    temp = st.pop();
                    ans.add(temp.data);
                }
            }
        }

        return ans;
    }
    public static void main(String[] args){
        Node root = new Node(10);
        root.left = new Node(20);
        root.right = new Node(30);
        root.left.left = new Node(40);
        root.left.right = new Node(50);
        root.right.left = new Node(60);
        root.right.right = new Node(70);
        
        ArrayList<Integer> arr = levelOrderTraversal(root);
        Methods m = new Methods();
        m.printArray(arr);
        ArrayList<Integer> arr2 = inorderTraversal(root);
        m.printArray(arr2);
        ArrayList<Integer> arr3 = preorderTraversal(root);
        m.printArray(arr3);
        ArrayList<Integer> arr4 =postorderTraversal(root);
        m.printArray(arr4);
        ArrayList<Integer> arr5 = postorderTraversalByOneStack(root);
        m.printArray(arr5);
    }
}

