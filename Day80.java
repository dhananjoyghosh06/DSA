//Q1. Cycle Detection using BFS -- IF kahn's algo is satisfied then it is acyclic(accoriding to kahn's algo) and if not then cyclic.
//TC-O(n+e)
//SC-O(n+e)


class Solution {
    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int n, ArrayList<ArrayList<Integer>> adj) {
        // code here
        
       int[] indegree = new int[n]; //O(n)
        
        HashMap<Integer, Boolean> visited = new HashMap<>(); // O(n)
        for(int i=0;i<n;i++){
            visited.put(i,false);
        }
        for(int i=0;i<n;i++){
            for(int it: adj.get(i)){
                indegree[it]++;
            }
        }
         Queue<Integer> q = new LinkedList<>();// (n+e)
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                if(visited.get(i) == false){
                    q.offer(i);
                    visited.put(i,true);
                }
            }
        }
        int count = 0;
        while(!q.isEmpty()){
            int front = q.poll();
            count++;
           
            for(int it : adj.get(front)){
                if(visited.get(it) ==  false){
                    indegree[it]--;
                    if(indegree[it] == 0){
                        q.offer(it);
                        visited.put(it,true);
                    }
                }
            }
        }
        
       if(count == n) return false;
       else return true;
    }
}

//Q2. Shortest Path in a Unweighted Graph
//TC-O(N+E)
//SC-O(N+E)

public class Solution {

	public static LinkedList<Integer> shortestPath(int[][] edges, int n, int m, int s, int t) {
		// Write your code here.
		HashMap<Integer, List<Integer>> adj = new HashMap<>();
		for(int i=1;i<=n;i++){
			adj.put(i,new ArrayList<>());
		}
		for(int i=0;i<m;i++){
			int u = edges[i][0];
			int v = edges[i][1];
			adj.get(u).add(v);
			adj.get(v).add(u);
		}
		int[] parent = new int[n+1];
		boolean[] visited = new boolean[n+1];
		for(int i=1;i<=n;i++){
			visited[i]=false;
		}

		Queue<Integer> q = new LinkedList<>();
		q.offer(s);
		parent[s] =-1;
		visited[s]=true;
		while(!q.isEmpty()){
			int front = q.poll();
			for(int it: adj.get(front)){
				if(!visited[it]){
					parent[it]=front;
					visited[it] = true;
					q.offer(it);
				}
			}
		}
		LinkedList<Integer> head = new LinkedList<>();

		head.addFirst(t);
		while(t!=s){
				head.addFirst(parent[t]);
				t=parent[t];

		}
		return head;
	}

}

// Q3. Shortest Path in Weighted Acyclic Directed Graph
//TC-O(N+E)
//SC-O(N)
/*
 * Store the nodes in stack using the toplogical sort or DFS
 * Then untill the stack is being empty, travese the adjacency and store the minimum path or shortest
 */
import java.util.*;

class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
}
class Graph{
    public  HashMap<Integer, ArrayList<Pair<Integer,Integer>>> adj;
    private int v;
    private Stack<Integer> st;
    public boolean[] visited ;
    public int[] dist ;
    Graph(int v){
        adj = new HashMap<>();
        this.v = v;
        for(int i=0;i<v;i++){
           adj.put(i, new ArrayList<>());
        }
        this.st = new Stack();
        this.visited = new boolean[v];
        Arrays.fill(visited,false);
        this.dist = new int[v];
        Arrays.fill(dist, Integer.MAX_VALUE);
    }
    void addEdge(int u, int v, int w){
        Pair<Integer,Integer> newPair= new Pair<>(v,w);
        adj.get(u).add(newPair);
    }
    void print(){
        for(int i=0;i<v;i++){
            for(Pair<Integer,Integer> it : adj.get(i)){
                System.out.println(i + "-> "+it.first+", "+it.second);
            }
        }
    }
    void dfs(int node){
        visited[node]= true;
        
        for(Pair<Integer,Integer> it : adj.get(node)){
            if(!visited[it.first]){
                dfs(it.first);
            }
        }
        st.push(node);
    }
    void shortestPath(int src){
        dist[src] = 0;
        while(!st.isEmpty()){
            int top = st.pop();
           if(dist[top] != Integer.MAX_VALUE){
                for(Pair<Integer,Integer> it: adj.get(top)){
                    int neighbour = it.first;
                    int weight = it.second;
                    if(dist[top] + it.second <dist[it.first]){
                        dist[it.first] = dist[top] + it.second;
                    }
                }
           }
        }
    }
}
class Main {
    public static void main(String[] args) {
        int v = 6;
        Graph g= new Graph(6);
        g.addEdge(0,1,5);
        g.addEdge(0,2,3);
        g.addEdge(1,3,6);
        g.addEdge(1,2,2);
        g.addEdge(2,3,7);
        g.addEdge(2,4,4);
        g.addEdge(2,5,2);
        g.addEdge(4,5,-2);
        g.addEdge(3,4,-1);
        g.print();
        
        
        for(int i=0;i<v;i++){
            if(g.visited[i] == false){
                g.dfs(i);
            }
        }
        int src =1;
        g.shortestPath(src);
        for(int i=0;i<g.dist.length;i++){
            System.out.print(g.dist[i]+" ");
        }
        
        
    }
}


//Q4. Dijkstra's Algorithm for find the shortest path
//TC-O(E(LOG(V))
//SC-O(N)
import java.util.* ;
import java.io.*; 
class Pair<U,V>{
	public U first;
	public V second;
	Pair(U first, V second){
		this.first = first;
		this.second = second;
	}
}
public class Solution {
	
	public static ArrayList < Integer > dijkstra(ArrayList< ArrayList < Integer > > vec, int v, int e, int s){
		// Write your code here.
		HashMap<Integer, ArrayList<Pair<Integer,Integer>>> adj= new HashMap<>();
		for(int i=0;i<v;i++){
			adj.put(i, new ArrayList<>());
		}
		for(int i=0;i<e;i++){
			int u = vec.get(i).get(0);
			int vEnd =  vec.get(i).get(1);
			int w =  vec.get(i).get(2);
			Pair<Integer,Integer> newPair = new Pair<>(vEnd,w);
			Pair<Integer,Integer> newPair2 = new Pair<>(u,w);
			adj.get(u).add(newPair);
			adj.get(vEnd).add(newPair2);
		}
		HashSet<Pair<Integer,Integer>> set = new HashSet<>();
		int[] dist = new int[v];
		for(int i=0;i<v;i++){
			dist[i] = Integer.MAX_VALUE;
		}
		dist[s] = 0;
		Pair<Integer,Integer> newPair = new Pair<>(0,s);
		set.add(newPair);

		while(set.isEmpty() == false){
			 Pair<Integer, Integer> top = null;

        	for (Pair<Integer, Integer> pair : set) {
            	if (top == null || pair.first < top.first) {
                	top = pair;
            	}
        	}

			int nodeDistance = top.first;
			int topNode = top.second;

			set.removeIf(Pair->Pair.second == topNode);

			for(Pair<Integer,Integer> it : adj.get(topNode)){
				 int neighbor = it.first;
                	int weight = it.second;
				 if (nodeDistance + weight < dist[neighbor]) {
                    dist[neighbor] = nodeDistance + weight;
                    set.add(new Pair<>(dist[neighbor], neighbor));
                }
			}

		}
		ArrayList<Integer> ans = new ArrayList<>();
        for(int i=0;i<v;i++){
            ans.add(dist[i]);
        }

        return ans;
	}
}

//Q5. Prim's Algorithm to find the Minimum spanning tree on a weighted Undirected Graph
//TC-O(N*N)
//SC-O()
/*
 * What is Spanning Tree - > A spanning tree is a subgraph of an undirected connected graph that includes all the vertices of the original graph but with the minimum possible number of edges.
 * Key Characteristics ->
 *    1. A spanning tree ensures that there is a path between any two vertices in the graph.That's means every two nodes in the graph should be connected anyhow(directly or indirectly)
 *    2. A spanning tree does not contain any cycles.
 *    3. If the graph has vertices, a spanning tree will have exactly V−1 edges.  
 *    4. It is derived from the original graph by removing some edges while retaining the connectedness of the graph.
 * 
 * Prim's Algorithm
 * 1. Take 3 Arrays. One is for track the minimum weight to
 *  reach that vertex (here I take name key), second one
 *  is to track the node is included int the mst or not.
 *  (it should a boolean type of array).Third one is to track the parent
 *  of the node from the node shlould be reached with minimum cost.
 * 
 * 2. Initialise the mst array with false , key with Integer.MAX_VALUE and parent -1 
 * 3. Before we go make the key[startingNode] = 0;
 * 4. Traverse all the nodes and Find the minimum weight from key array and
 *  initialise a u with i and mini with key[i];
 * 
 * 5. Now make the mst[u] = true;
 * 6. Now go for the adjacency nodes if it's mst is not true && key[u]<mini then replace the key[u] = minimum and update the parent[neighbour] = u;
 * 7. Now we got the parent array. Traverse from one index ahead from start and store the index, value and key[i] and return the ans
 */
//

 import java.util.* ;
import java.io.*; 
import java.util.ArrayList;
class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first= first;
        this.second = second;
    }
}
public class Solution 
{
    public static ArrayList<ArrayList<Integer>> calculatePrimsMST(int n, int m, ArrayList<ArrayList<Integer>> vec)
    {
        // Write your code here.
        HashMap<Integer, ArrayList<Pair<Integer, Integer>>> adj = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            adj.put(i, new ArrayList<>());
        }
        for(int i=0;i<m;i++){
            int u = vec.get(i).get(0);
            int v = vec.get(i).get(1);
            int w = vec.get(i).get(2);
            
            adj.get(u).add(new Pair<>(v,w));
            adj.get(v).add(new Pair<>(u,w));
        }

        int[] key = new int[n+1];
        Arrays.fill(key,Integer.MAX_VALUE);
        boolean[] mst = new boolean[n+1];
         Arrays.fill(mst,false);
        int[] parent = new int[n+1];
         Arrays.fill(parent,-1);

         key[1] = 0;

         for(int i=1;i<=n;i++){
             int mini = Integer.MAX_VALUE;
             int u = -1;
             for(int v =1;v<=n;v++){
                 if(mst[v] == false && key[v]<mini){
                     mini = key[v];
                     u= v;
                 }
             }
                if (u == -1) break;
             //mark mini node as true;
             mst[u] = true;

             //check for adjacent nodes
             for(Pair<Integer,Integer>it : adj.get(u)){
                 int v = it.first;
                 int w = it.second;
                 if( (mst[v]  ==  false) && (key[v] > w)){
                        key[v] = w;
                       parent[v] = u;
                 }
             }

         }   
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        for(int i=2;i<=n;i++){
            int u = parent[i];
            int v = i;
            int w = key[v];
             ArrayList<Integer> edge = new ArrayList<>();
            edge.add(u);
            edge.add(v);
            edge.add(w);
            ans.add(edge);
        }
        return ans;
    }
}

//OPTIMAL APPROACH
//TC-O(NLogN)
//SC-O(N+M)

import java.util.* ;
import java.io.*; 
import java.util.ArrayList;
class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first= first;
        this.second = second;
    }
}
public class Solution 
{
    public static ArrayList<ArrayList<Integer>> calculatePrimsMST(int n, int m, ArrayList<ArrayList<Integer>> vec)
    {
        // Write your code here.
        HashMap<Integer, ArrayList<Pair<Integer, Integer>>> adj = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            adj.put(i, new ArrayList<>());
        }
        for(int i=0;i<m;i++){
            int u = vec.get(i).get(0);
            int v = vec.get(i).get(1);
            int w = vec.get(i).get(2);
            
            adj.get(u).add(new Pair<>(v,w));
            adj.get(v).add(new Pair<>(u,w));
        }

        int[] key = new int[n+1];
        Arrays.fill(key,Integer.MAX_VALUE);
        boolean[] mst = new boolean[n+1];
         Arrays.fill(mst,false);
        int[] parent = new int[n+1];
         Arrays.fill(parent,-1);
         PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.first));
         key[1] = 0;
        pq.add(new Pair<>(0, 1)); // (key, node)
        while (!pq.isEmpty()) {
            // Extract the node with the smallest key
            int u = pq.poll().second;

            // If the node is already in MST, skip
            if (mst[u]) continue;

            // Mark the node as part of the MST
            mst[u] = true;

            // Process adjacent nodes
            for (Pair<Integer, Integer> it : adj.get(u)) {
                int v = it.first;
                int w = it.second;

                // Update key and parent if a better edge is found
                if (!mst[v] && key[v] > w) {
                    key[v] = w;
                    parent[v] = u;
                    pq.add(new Pair<>(key[v], v)); // Push updated key and vertex into the Min-Heap
                }
            }
        }
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        for(int i=2;i<=n;i++){
            int u = parent[i];
            int v = i;
            int w = key[v];
             ArrayList<Integer> edge = new ArrayList<>();
            edge.add(u);
            edge.add(v);
            edge.add(w);
            ans.add(edge);
        }
        return ans;
    }
}
