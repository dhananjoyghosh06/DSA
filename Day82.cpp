//Q1. Find Strongly connected Components using Kosraju's algorithm
//TC-O(v+e)
//SC-O(v)
/*  1. What is Strongly Connected Graph?
      A strongly connected component (SCC) is a subgraph in a directed graph
      where every vertex is reachable from every other vertex.
      A component containing a single vertex is always a strongly connected component.
    2. Kosaraju's algorithm
    step1: Do Topological sort for the vertices of the graph
    step2: create a transpose of the graph
    step3: then again call an another dfs call and track count of each component
*/
class Solution {
    void revDfs(int top,vector<bool>&visited,vector<vector<int>>&adj)
    {
        visited[top] =1;
        for(auto it : adj[top]){
            if(!visited[it]) revDfs(it,visited,adj);
        }
    }
    void dfs(int i,vector<bool>&visited , stack<int> &st ,vector<vector<int>>& adj){
        visited[i] =  true;
        for(int it: adj[i]){
            if(!visited[it]){
                dfs(it,visited,st,adj);
              
            }
        }
          st.push(i);
    }
 
  public:
      int kosaraju(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
        
        //toposort
        stack<int> st ; //v
        vector<bool>visited(v,false); //v
        
        for(int i=0;i<v;i++){ // O(v)
            
                if(!visited[i])
                    dfs(i, visited, st, adj);
              
        }
        
        // transpose 
       vector<vector<int>> transpose(v); //v
       for(int i=0;i<v;i++){ //v
           visited[i] = false;
           for(auto it : adj[i]){
               transpose[it].push_back(i);
           }
       }
       
       // processing the stack 
       int count = 0;
       
       while(!st.empty()){ //O(V)
           int top = st.top();
           st.pop();
           if(!visited[top]){
               count++;
               revDfs(top,visited,transpose);
           }
       }
       
       return count;
    }
    
};

//Q2. Bellmenford algorithm for find the negetive cycle . If NC is not present in the graph then find the Shortest path.
//TC-O(v-1 * e)
//SC-O(v)

class Solution {
    static int[] bellmanFord(int v, int[][] edges, int src) {
        // Write your code here
        //adj list
        // ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        // for(int i=0;i<v;i++){
        //     adj.add(new ArrayList<>());
        // }
        // for(int i=0;i<edges.size().length;i++){
        //     int u = edges[i][0];
        //     int v = edges[i][1];
            
        //     adj.get(u).add(v);
        //     adj.get(v).add(u);
        // }
        
        int[] dist = new int[v];
        Arrays.fill(dist,(int)1e8);
        
        dist[src] = 0;
        
        for(int i=1;i<v;i++){
            for(int j=0;j<edges.length;j++){
                int u = edges[j][0];
                int vt = edges[j][1];
                int w = edges[j][2];
                
                if(dist[u]!=1e8 && dist[u]+w <dist[vt]){
                    dist[vt] = dist[u]+w;
                }
            }
        }
        
       
        for(int j =0 ;j< edges.length;j++){
             int u = edges[j][0];
                int vt = edges[j][1];
                int w = edges[j][2];
                
                 if(dist[u]!=1e8 && dist[u]+w <dist[vt]){
                    return new int[]{-1};
                }
        }
        
       
        return dist;
    }
}