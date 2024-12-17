//Q1. Matrix Representation of a Undirected Graph
//TC-O(n*n)
//SC-O(n*n)

import java.util.*;


public class Day78 {
    private static void addEdge(int[][] arr, int i, int j){
        arr[i][j] = 1;
        arr[j][i] =1 ;
    }
    private static void displayEdges(int[][] arr){
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
                    System.out.print(arr[i][j] +" ");
            }
            System.out.println();
        }
        
    }
    public static void main(String[] args){
        System.out.println("Hello Java");

        int[][] arr = new int[4][4];

        addEdge(arr, 0, 1);
        addEdge(arr, 0, 2);
        addEdge(arr, 2, 3);
        addEdge(arr, 1, 3);

        displayEdges(arr);
    }
}

// Q2. BFS traversal of a graph
//TC-O(N+E)
//SC-O(N+E)


import java.util.*;

class Main {
        private static void addEdge(ArrayList<ArrayList<Integer>>arr, int i, int j){
            arr.get(i).add(j);
            arr.get(j).add(i);
        }
         private static void bfs(ArrayList<ArrayList<Integer>>arr, int stNode){
        Queue<Integer> q = new LinkedList<>();
        boolean[] isVisited = new boolean[arr.size()];
        q.add(stNode);
        isVisited[stNode] = true;
    
        while(!q.isEmpty()){
            int front = q.poll();
           
            System.out.print(front+" ");
            ArrayList<Integer> frontInner = arr.get(front);
            for(int it: frontInner){
                 if(!isVisited[it]){
                       q.add(it);
                        isVisited[it] = true;
                 }
              
            }
            
        }
}
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        int vertices =5;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i=0;i<vertices;i++){
            arr.add(new ArrayList<>());
        }
        addEdge(arr,0,2);
        addEdge(arr,0,3);
        addEdge(arr,3,1);
        addEdge(arr,1,4);
        addEdge(arr,2,4);
        
        bfs(arr,0);
    }
}

//Q3. DFS traversal of a graph

// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;

class Main {
    private static HashMap<Integer, Boolean>  visited = new HashMap<>();
    private static void addEdge(ArrayList<ArrayList<Integer>>arr, int i, int j){
        arr.get(i).add(j);
        arr.get(j).add(i);
    }
    private static void dfsRec(ArrayList<ArrayList<Integer>>arr, int stIdx){
        System.out.print(stIdx+" ");
         visited.put(stIdx,true);
        for(int it : arr.get(stIdx)){
             if (!visited.get(it)) 
            dfsRec(arr,it);
        }
    }
    private static void dfs(ArrayList<ArrayList<Integer>>arr,int stIdx){
         for (int i = 0; i < arr.size(); i++) {
            visited.put(i, false);
        }
        dfsRec(arr,stIdx);
    }    
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        int vertices =5;
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for(int i=0;i<vertices;i++){
            arr.add(new ArrayList<>());
        }
        addEdge(arr,0,2);
        addEdge(arr,0,3);
        addEdge(arr,3,1);
        addEdge(arr,1,4);
        addEdge(arr,2,4);
        
        dfs(arr,0);
    }
}

// Q4. Cycle detection of a graph 
//TC-O(M+N)
//SC-O(M+N)

import java.util.*;

public class Solution {
    public static HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
     public static HashMap<Integer, Boolean> visited = new HashMap<>();
    public static String cycleDetection(int[][] edges, int n, int m) {
        // Write your code here.
          for(int i=1;i<=n;i++){
            adj.put(i, new ArrayList<>()); 
            visited.put(i,false);
        }
        for(int i= 0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);

        }
      
        String sol = "No";
        for(int i=1;i<=n;i++){
            if(!visited.get(i)){
                boolean ans = isCyclic(i,-1);
                if(ans == true) sol="Yes";
            }
        }
        return sol;
    }
    private static boolean isCyclic(int child, int parent){
            visited.put(child,true);

            for(int i : adj.get(child)){
                 if (!visited.get(i)) {
                // If the neighbor is not visited, recursively call DFS
                    if (isCyclic(i, child)) {
                        return true;
                    }
                 } else if (i != parent) {
                // If the neighbor is visited and not the parent, a cycle is detected
                    return true;
                }
            }
            return false;
    }
}