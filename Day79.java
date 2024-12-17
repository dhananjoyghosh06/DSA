//Q1. Detect Cycle in a directed graph
//TC-O(m+n)
//SC-O(m+n)
class Solution {
    // Function to detect cycle in a directed graph.
    HashMap<Integer, Boolean> visited = new HashMap<>();
    HashMap<Integer, Boolean> recStack = new HashMap<>();
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        // code here
        
        for(int i=0;i<V;i++){
            visited.put(i,false);
            recStack.put(i,false);
        }
        for(int i=0;i<V;i++){
            if(!visited.get(i)){
                 if(solve(adj,i)) return true;
            }
        }
        return false;
    }
    boolean solve(ArrayList<ArrayList<Integer>> adj,int i){
        visited.put(i,true);
        recStack.put(i,true);
        for(int it : adj.get(i)){
            if(!visited.get(it)){
                if (solve(adj, it)) {
                    return true; // Cycle detected
                }
                
            }else if(recStack.get(it)) return true;
        }
        recStack.put(i,false);
        return false;
    }
}

//Q2. Topological sort using DFS
//TC-O(N+E)
//SC-O(N)
class Result{
    public HashMap<Integer, Boolean> visited;
    public Stack<Integer> st ;
    Result(){
       visited =new HashMap<>();
       st = new Stack<>();;
    }
    
}
class Solution {
    
    // Function to return list containing vertices in Topological order.
    static ArrayList<Integer> topologicalSort(ArrayList<ArrayList<Integer>> adj) {
        // Your code here\
        Result r = new Result();
        for(int i=0;i<adj.size();i++){
            r.visited.put(i, false);
        }
        
        for(int i=0;i<adj.size();i++){
            if(!r.visited.get(i)){
                dfs(adj,r,i);
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        while(!r.st.isEmpty()){
            int top = r.st.pop();
            ans.add(top);
        }
        return ans;
    }
    static void dfs(ArrayList<ArrayList<Integer>> adj, Result r , int idx){
        r.visited.put(idx, true);
        
        for(int i: adj.get(idx)){
            if(!r.visited.get(i)){
                dfs(adj,r,i);
            }
        }
        r.st.push(idx);
    }
}

//Q3. Topology Sort using Kahn's algorithm
//TC-O(n+e)
//SC-O(n)

class Solution {
    // Function to return list containing vertices in Topological order.
    static ArrayList<Integer> topologicalSort(ArrayList<ArrayList<Integer>> adj) {
        // Your code here
        int v = adj.size();
        int[] indegree = new int[v];
        for(int i=0;i<v;i++){
            for(int it : adj.get(i)){
                indegree[it]++;
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0;i<v;i++){
            if(indegree[i] == 0){
                q.offer(i);
            }
        }
        ArrayList<  Integer> ans = new ArrayList<>();
        
        while(!q.isEmpty()){
            int front = q.poll();
            ans.add(front);
            
            for(int it : adj.get(front)){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.offer(it);
                }
            }
        }
        if(ans.size() != v){
            System.out.println("Graph is Cyclic");
            return new ArrayList<>(0);
        } 
        
        return ans;
    }
}