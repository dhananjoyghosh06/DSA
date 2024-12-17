//Q1. Construct Binary tree from String with bracket representation 
//TC-O(n)
//SC-O(n)
class Solution {
    public static Node treeFromString(String s) {
        // code here
        int [] idx = new int[]{0};
        return helper(idx, s);
    }
    private static Node helper(int[] idx, String s){
        int n= s.length();
        int val = 0;
        if((n <= idx[0]) || (s.charAt(idx[0]) == ')')){
            idx[0]++;
            return null;
        } 
        while(idx[0] < n && Character.isDigit(s.charAt(idx[0]))){
            val = val*10+(s.charAt(idx[0])-'0');
            idx[0]++;
            
        }
        Node root = new Node(val);
        if(idx[0] < n && s.charAt(idx[0]) == '('){
            idx[0]++;
            root.left = helper(idx, s);
        }
        if(idx[0]<n && s.charAt(idx[0]) == '('){
            idx[0]++;
            root.right = helper(idx, s);
        }
        
         if (idx[0] < n && s.charAt(idx[0]) == ')') {
            idx[0]++;
        }
        return root;
    }
}

//Q2. Convert binary tree with doubly linked list
//SC-O(n)
//TC-O(n)

class Solution
{
    // Function to convert binary tree to doubly linked list and return it.
    Node bToDLL(Node root)
    {
        // ArrayList to store inorder traversal of the binary tree.
        ArrayList<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        
        // The head of the doubly linked list
        Node ans = null;
        ans = constructDLL(arr);
        
        return ans;
    }
    
    // Function to construct the doubly linked list from the inorder traversal
    Node constructDLL(ArrayList<Integer> arr)
    {
        int n = arr.size();
        if (n == 0) return null;

        // Initializing the head of the doubly linked list.
        Node head = null;
        Node curr = null;

        // Iterate through the inorder array and create the doubly linked list.
        for (int i = 0; i < n; i++)
        {
            Node newNode = new Node(arr.get(i));

            if (head == null) // The first node in the DLL
            {
                head = newNode;
                curr = head;
            }
            else // Link the nodes together.
            {
                curr.right = newNode;
                newNode.left = curr;
                curr = curr.right;
            }
        }
        
        return head; // Return the head of the doubly linked list
    }

    // Inorder traversal to fill the ArrayList with the tree's elements
    void inorder(Node root, ArrayList<Integer> arr)
    {
        if (root == null) return;
        
        inorder(root.left, arr); // Traverse left subtree
        arr.add(root.data); // Add the current node data to the list
        inorder(root.right, arr); // Traverse right subtree
    }
}

//Optimal Approach 
//SC-O(n)
//TC-O(h)

class Result{
    Node head;
    Node tail;
    Result(Node head, Node tail){
        this.head=head;
        this.tail=tail;
    }
}
class Solution
{
    // Function to convert binary tree to doubly linked list and return it.
    Node bToDLL(Node root)
    {
        // ArrayList to store inorder traversal of the binary tree.
       if(root ==  null) return null;
       
       Result res = convertToDLL(root);
        return res.head;
    }
    
    private Result convertToDLL(Node root){
        if (root == null) return new Result(null, null);
        
        Result leftResult = convertToDLL(root.left);
        Result rightResult = convertToDLL(root.right);
        
        if (leftResult.tail != null) {
            leftResult.tail.right = root;
            root.left = leftResult.tail;
        }


        // Link the current node with right DLL.
        if (rightResult.head != null) {
            rightResult.head.left = root;
            root.right = rightResult.head;
        }
        
        Node head = (leftResult.head != null) ? leftResult.head : root;
        Node tail = (rightResult.tail != null) ? rightResult.tail : root;

        return new Result(head, tail);
        
    }
}





//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            String[] arr1Str = sc.nextLine().split(" ");
            int[] arr = Arrays.stream(arr1Str).mapToInt(Integer::parseInt).toArray();
            Solution ob = new Solution();
            int ans = ob.minSwaps(arr);
            System.out.println(ans);

            System.out.println("~");
        }
    }
}
// } Driver Code Ends


//Q3. Find minimum swaps required to Convert a binary tree into BST
//TC-O(nlogn)
//SC-O(n)
class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}
class Solution {
    
    public static int minSwaps(int[] arr) {
        // code here
          ArrayList<Integer> in = new ArrayList<>();
        inorder(arr,0,in);
        ArrayList<Pair<Integer,Integer>> p = new ArrayList<>();
        int n = arr.length;
        for(int i=0;i<n;i++){
            Pair<Integer, Integer> newPair = new Pair(in.get(i),i);
            p.add(newPair);
        }
        Collections.sort(p, new Comparator<Pair<Integer,Integer>>(){
            @Override
            public int compare(Pair<Integer,Integer> p1, Pair<Integer,Integer> p2){
                return Integer.compare(p1.first, p2.first);
            }
        });
        int swaps = 0;
        for(int i=0;i<n;++i){
           while (p.get(i).second != i) { // Keep swapping until the element is in its correct position
                swaps++;
                Collections.swap(p, i, p.get(i).second); // Swap the current element with its target position
            }
        }
        return swaps;
    }
    public static void inorder(int[] arr, int i, ArrayList<Integer> in ){
        if(i>=arr.length) return;
        inorder(arr,2*i+1,in);
        in.add(arr[i]);
        inorder(arr,2*i+2,in);
    }
}