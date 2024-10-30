// Q1. Vertical Order Traversal
//TC-O(NlogN)
//SC-O(N)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        if(!root)
        return ans;
        
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<TreeNode*,int> p = q.front();
            q.pop();
            
            TreeNode *curr = p.first;
            int hd = p.second;
            
            mp[hd].push_back(curr->val);
            
            if(curr->left)
            q.push(make_pair(curr->left,hd-1));
            if(curr->right)
            q.push(make_pair(curr->right,hd+1));
        }

        }
        return ans;
    }
};

//Q2. Top View of a tree
//TC-O(NLogN)
//SC-O(N)

class Pair<U,V>{
    public U first;
    public V second;
    public Pair(U first, V second){
       this.first = first ;
       this.second = second;
    }
}
class Solution {
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    static ArrayList<Integer> topView(Node root) {
        // add your code
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        if(root ==  null) return ans;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        Queue<Pair<Node,Integer>> q= new LinkedList<>();
        
        Pair<Node,Integer> rootPair = new Pair<>(root,0);
        q.offer(rootPair);
        
        while(!q.isEmpty()){
            Pair<Node, Integer> front = q.poll();
            Node frontNode = front.first;
            int hd = front.second;
            
            //maintain 1 to 1 mapping
            if(!map.containsKey(hd)){
                map.put(hd,frontNode.data);
            }
            
            if(frontNode.left!=null){
                Pair<Node, Integer>leftPair= new Pair<>(frontNode.left,hd-1);
                q.offer(leftPair);
            }
            if(frontNode.right!=null){
                Pair<Node, Integer>rightPair= new Pair<>(frontNode.right,hd+1);
                q.offer(rightPair);
            }
        }
        
        ArrayList<Integer> hds = new ArrayList<Integer>(map.keySet());
        Collections.sort(hds);
        for(int it : hds){
            int val = map.get(it);
            ans.add(val);
        }
        
        return ans;
    }
}

//Q3. Bottom View of a tree
//SC-O(NLOGN)
//TC-O(N)



//User function Template for Java

class Pair<U, V> {
    public U first;
    public V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }
}

class Solution
{
    //Function to return a list containing the bottom view of the given tree.
    public ArrayList <Integer> bottomView(Node root)
    {
        // Code here
         ArrayList<Integer> ans = new ArrayList<>();

        if (root == null) return ans;

        // To store the first node at each horizontal distance
        HashMap<Integer, Integer> map = new HashMap<>();
        Queue<Pair<Node, Integer>> q = new LinkedList<>();

        // Starting with the root node at horizontal distance 0
        Pair<Node, Integer> rootPair = new Pair<>(root, 0);
        q.offer(rootPair);

        while (!q.isEmpty()) {
            Pair<Node, Integer> front = q.poll();
            Node frontNode = front.first;
            int hd = front.second;

            // Maintain 1 to 1 mapping
           
                map.put(hd, frontNode.data);
            

            // Add left child with horizontal distance -1
            if (frontNode.left != null) {
                Pair<Node, Integer> leftPair = new Pair<>(frontNode.left, hd - 1);
                q.offer(leftPair);
            }
            // Add right child with horizontal distance +1
            if (frontNode.right != null) {
                Pair<Node, Integer> rightPair = new Pair<>(frontNode.right, hd + 1);
                q.offer(rightPair);
            }
        }

        // Get the horizontal distances and sort them
        ArrayList<Integer> hds = new ArrayList<>(map.keySet());
        Collections.sort(hds);

        // Collect the corresponding values from the map
        for (int it : hds) {
            int val = map.get(it);
            ans.add(val);
        }

        return ans;
    }
}

//Q4. Left view of a binary tree
//TC-O(NLogN)
//SC-O(N)

class Pair<U,V>{
    public U first;
    public V second;
    public Pair(U first, V second)
    {
        this.first = first;
        this.second = second;

    }
}
class Solution {
    // Function to return list containing elements of left view of binary tree.
    ArrayList<Integer> leftView(Node root) {
        // code here
        
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        Queue<Pair<Node,Integer>> q = new LinkedList<>();
        
        Pair<Node, Integer> topPair = new Pair<>(root,0);
        q.offer(topPair);
        
        while(!q.isEmpty()){
            Pair<Node, Integer> front = q.poll();
            int level = front.second;
            Node frontNode = front.first;
            
            if(!map.containsKey(level)){
                map.put(level, frontNode.data);
            }
            
            if(frontNode.left != null){
                Pair<Node, Integer> leftPair = new Pair<>(frontNode.left, level+1);
                q.offer(leftPair);
            }
             if(frontNode.right != null){
                Pair<Node, Integer> rightPair = new Pair<>(frontNode.right, level+1);
                q.offer(rightPair);
            }
        }
        
        ArrayList<Integer> levels =  new ArrayList<>(map.keySet());
        Collections.sort(levels);
        
        for(int it: levels){
            int val = map.get(it);
            ans.add(val);
        }
        
        return ans;
    }
}

//Q5. Right view of a tree
//SC-O(N)
//TC-O(NlogN)

 
class Pair<U,V>{
    public U first;
    public V second;
    public Pair(U first, V second)
    {
        this.first = first;
        this.second = second;

    }
}
class Solution {
    // Function to return list containing elements of right view of binary tree.
    ArrayList<Integer> rightView(Node root) {
     ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        Queue<Pair<Node,Integer>> q = new LinkedList<>();
        
        Pair<Node, Integer> topPair = new Pair<>(root,0);
        q.offer(topPair);
        
        while(!q.isEmpty()){
            Pair<Node, Integer> front = q.poll();
            int level = front.second;
            Node frontNode = front.first;
            
           
                map.put(level, frontNode.data);
            
            
            if(frontNode.left != null){
                Pair<Node, Integer> leftPair = new Pair<>(frontNode.left, level+1);
                q.offer(leftPair);
            }
             if(frontNode.right != null){
                Pair<Node, Integer> rightPair = new Pair<>(frontNode.right, level+1);
                q.offer(rightPair);
            }
        }
        
        ArrayList<Integer> levels =  new ArrayList<>(map.keySet());
        Collections.sort(levels);
        
        for(int it: levels){
            int val = map.get(it);
            ans.add(val);
        }
        
        return ans;
    }
}