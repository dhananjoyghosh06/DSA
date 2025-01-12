// Q1. Kruskal Algorithm 
//TC-O(nlogm)
//SC-O(n)

import java.util.*;
public class Solution {

	public static int minimumSpanningTree(ArrayList<ArrayList<Integer>> edges, int n) {
		//Your code goes here
		Comparator<ArrayList<Integer>> customComparator = new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
                return Integer.compare(a.get(2), b.get(2)); // Ascending order by weight
            }
        };
		Collections.sort(edges, customComparator); 
		ArrayList<Integer> parent  = new ArrayList<>(n);
		ArrayList<Integer> rank = new ArrayList<>(n);
		initialise(parent,rank,n);
		int ans = 0;
		for(int i=0;i<edges.size();i++){
			int u= findParent(parent, edges.get(i).get(0));
			int v= findParent(parent, edges.get(i).get(1));
			

			if(u!=v){
				ans+=edges.get(i).get(2);
				unionSet(u,v,parent,rank);
			}
		}
		return ans;
	}
	
	static int findParent(ArrayList<Integer> parent, int node){
		if(parent.get(node) == node) return node;
		int ans = findParent(parent,parent.get(node));
		parent.set(node,ans);
		return ans;
	}
	 static void unionSet(int u, int v, ArrayList<Integer> parent, ArrayList<Integer> rank){
		u = findParent(parent,u);
		v = findParent(parent,v);

		if(rank.get(u) == rank.get(v)){
			parent.set(u,v);
			rank.set(v, rank.get(v)+1);
		}else if(rank.get(u) < rank.get(v)){
			parent.set(u,v);
		}else{
			parent.set(v,u);
		}

	}
	static void initialise(ArrayList<Integer> parent, ArrayList<Integer> rank, int n){
		for(int i=0;i<n;i++){
			parent.add(i);
			rank.add(0);
		}
	}
}

//Find Bridges in graph - Brute Force Approach 
//TC-O(e*(v+e))
//SC-O(v)

// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class Pair<U,V>{
    public U first;
    public V second;
    Pair(U first, V second){
        this.first = first;
        this.second = second;
    }
     @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) o;
        return Objects.equals(first, pair.first) && Objects.equals(second, pair.second);
    }
    
    @Override
    public int hashCode() {
        return Objects.hash(first, second);
    }
}
 class Graph{
        private int v;
        private ArrayList<ArrayList<Integer>> adj;
        Graph(int v){
            this.v = v;
            adj = new ArrayList<>();
            for(int i=0;i<v;i++){
                adj.add(new ArrayList<>());
            }
        }
        void addEdge(int u, int v){
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        int DFS(int st, boolean[] visited){
            visited[st] = true;
            int count = 1;
            
                for(int it: adj.get(st)){
                    if(!visited[it]){
                        count+=DFS(it,visited);
                    }
                }
            
            return count;
        }
        List<Pair<Integer, Integer>> findBridges(){
            List<Pair<Integer, Integer>> bridges = new ArrayList<>();
            
            for(int i=0;i<v;i++){
                 ArrayList<Integer> currentNeighbors = new ArrayList<>(adj.get(i));
                 
                for(int neighbours:currentNeighbors){
                    adj.get(i).remove(Integer.valueOf(neighbours));
                    adj.get(neighbours).remove(Integer.valueOf(i));
                    
                    boolean[] visited = new boolean[v];
                    Arrays.fill(visited,false);
                    int count = 0;
                    count = DFS(i,visited);
                     adj.get(neighbours).add(i);
                    adj.get(i).add(neighbours);
                    if(count <v){
                        Pair<Integer,Integer> innerPair= new Pair<>(i,neighbours);
                        Pair<Integer,Integer> reverseInnerPair= new Pair<>(neighbours,i);
                        
                        if(!bridges.contains(reverseInnerPair)){
                            bridges.add(innerPair);
                        }
                    }
                }
            }
            
            return bridges;
        }
    }
class Main {
    
    public static void main(String[] args) {
        int v =5;
        Graph g = new Graph(5);
        g.addEdge(0,1);
         g.addEdge(1,3);
          g.addEdge(3,4);
           g.addEdge(2,4);
            g.addEdge(1,2);
            
            List<Pair<Integer,Integer>> ans = new ArrayList<Pair<Integer,Integer>>();
            ans = g.findBridges();
            
            for(Pair<Integer,Integer>it: ans ){
                System.out.println("( "+it.first+" "+it.second+" )");
            }
    }
}

//Optimal Approach or Trajan's Algorithm
//SC-O(v+e)
//TC-O(v)

import java.util.*;

public class Solution {

    public static List<List<Integer>> findBridges(int[][] edges, int v, int e) {

        // Create adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < e; i++) {
            int p = edges[i][0];
            int c = edges[i][1];
            adj.get(p).add(c);
            adj.get(c).add(p);
        }

        // Arrays for DFS
        boolean[] visited = new boolean[v];
        int[] disc = new int[v];
        int[] low = new int[v];
        Arrays.fill(disc, -1); // Initialize discovery times
        Arrays.fill(low, -1);  // Initialize low values
        int[] timer = {0};     // Single-element array to act as a timer

        List<List<Integer>> res = new ArrayList<>();

        // Perform DFS for each component
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, disc, low, res, timer);
            }
        }

        return res;
    }

    static void dfs(int idx, int parent, ArrayList<ArrayList<Integer>> adj, boolean[] visited,
                    int[] disc, int[] low, List<List<Integer>> res, int[] timer) {

        visited[idx] = true;
        disc[idx] = low[idx] = timer[0]++; // Initialize discovery and low times

        for (int neighbor : adj.get(idx)) {
            if (neighbor == parent) {
                continue; // Skip the parent edge
            }
            if (!visited[neighbor]) {
                dfs(neighbor, idx, adj, visited, disc, low, res, timer);

                // Update low value for the current node
                low[idx] = Math.min(low[idx], low[neighbor]);

                // Check if the edge is a bridge
                if (low[neighbor] > disc[idx]) {
                    res.add(Arrays.asList(idx, neighbor));
                }
            } else {
                // Update low value for back edge
                low[idx] = Math.min(low[idx], disc[neighbor]);
            }
        }
    }

    public static void main(String[] args) {
        int v = 5; // Number of vertices
        int e = 5; // Number of edges
        int[][] edges = {
                {0, 1},
                {1, 2},
                {2, 0},
                {1, 3},
                {3, 4}
        };

        List<List<Integer>> bridges = findBridges(edges, v, e);

        for (List<Integer> bridge : bridges) {
            System.out.println(bridge);
        }
    }
}

//Find the Articulation Error
//TC-O(n*(n+e))
//SC-O(n)

class Solution {
    // Function to return the articulation points of the graph.
    public ArrayList<Integer> articulationPoints(int v, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> ans = new ArrayList<>();

        for (int i = 0; i < v; i++) {
            // Mark the node as removed
            boolean[] visited = new boolean[v];
            visited[i] = true;

            int startNode = (i == 0) ? 1 : 0; // Start DFS from any other node
            int count = DFS(adj, startNode, visited);

            // If not all nodes are visited, the removed node is an articulation point
            if (count < v - 1) {
                ans.add(i);
            }
        }

        // Return the result or -1 if no articulation points exist
        if (ans.isEmpty()) {
            ans.add(-1);
        }

        return ans;
    }

    // Depth First Search function
    private int DFS(ArrayList<ArrayList<Integer>> adj, int node, boolean[] visited) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        visited[node] = true;
        int count = 0;

        while (!stack.isEmpty()) {
            int current = stack.pop();
            count++;
            for (int neighbor : adj.get(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }

        return count;
    }
}

//Optimal Approach using Tarjan's algorithm
//TC-O(n+e)
//SC-O(n)

class Solution {
    // Function to find articulation points in a graph
    public ArrayList<Integer> articulationPoints(int v, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> result = new ArrayList<>();
        HashSet<Integer> articulationSet = new HashSet<>();

        int[] timer = new int[]{0}; // Timer to track discovery times
        int[] discovery = new int[v];
        int[] lowest = new int[v];
        boolean[] visited = new boolean[v];

        Arrays.fill(discovery, -1);
        Arrays.fill(lowest, -1);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, visited, discovery, lowest, adj, articulationSet);
            }
        }

        result.addAll(articulationSet);
        Collections.sort(result); // Sort for consistent output
        if (result.size() == 0) result.add(-1);
        return result;
    }

    private void dfs(int node, int parent, int[] timer, boolean[] visited, int[] discovery, int[] lowest, ArrayList<ArrayList<Integer>> adj, HashSet<Integer> articulationSet) {
        visited[node] = true;
        discovery[node] = lowest[node] = timer[0]++;
        int childCount = 0;

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) continue; // Skip the parent node

            if (!visited[neighbor]) {
                childCount++;
                dfs(neighbor, node, timer, visited, discovery, lowest, adj, articulationSet);

                // Update the low value of the current node based on its neighbor
                lowest[node] = Math.min(lowest[node], lowest[neighbor]);

                // Check articulation point condition
                if (lowest[neighbor] >= discovery[node] && parent != -1) {
                    articulationSet.add(node);
                }
            } else {
                // Update the low value of the current node based on back edges
                lowest[node] = Math.min(lowest[node], discovery[neighbor]);
            }
        }

        // Special case for root node
        if (parent == -1 && childCount > 1) {
            articulationSet.add(node);
        }
    }
}