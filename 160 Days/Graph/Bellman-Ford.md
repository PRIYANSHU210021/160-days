# Problem: Bellman-Ford
# Code : 
```c++
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>minDis(V,1e8);
        minDis[src] = 0;
        
        for(int i=0; i<V-1; i++)
        {
            for(auto edge:edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(minDis[u] != 1e8 && minDis[u]+w < minDis[v])
                minDis[v] = minDis[u]+w;
            }
        }
        
        for(auto edge:edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(minDis[u] != 1e8 && minDis[u]+w < minDis[v])
                return {-1};
            }
        return minDis;
   
    }
};
```

---

###  **Bellman-Ford Intuition**

1. **Initialize distances**:  
   All nodes are set to a large value (`1e8`) except the source (`0`).

2. **Relax all edges V-1 times**:  
   Try to improve the shortest path by checking every edge.

3. **Relaxation logic**:  
   If going through `u` gives a shorter path to `v`, update it:  
   `if (minDis[u] + w < minDis[v])`

4. **Repeat V-1 times**:  
   Because the longest shortest path (without a cycle) can be `V-1` edges long.

5. **Detect negative weight cycles**:  
   After V-1 passes, check once more:  
   If any distance still decreases → **negative cycle exists**.

6. **Return result**:  
   If no negative cycle, return distance array; else return `{-1}`.

---

###  Compared to Dijkstra:

1. Dijkstra uses a **priority queue** (greedy approach).  
   Bellman-Ford does **brute-force edge relaxation**.

2. Dijkstra **fails with negative weights**,  
   Bellman-Ford **handles them**.

3. Dijkstra runs faster: **O(E log V)** with a heap.  
   Bellman-Ford is slower: **O(V × E)**.

4. Bellman-Ford **detects negative weight cycles**,  
   Dijkstra **cannot**.

---
