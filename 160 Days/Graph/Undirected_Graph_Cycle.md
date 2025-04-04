# Problem: Undirected Graph Cycle

# Code: 
```c++
class Solution {
  public:
  bool solveDfs(int node, vector<vector<int>> &adj, vector<int>&visited, int parent)
  {
      visited[node] =1;
        for(int i =0; i<adj[node].size(); i++)
        {
            if(parent == adj[node][i])
            continue;
            if(visited[adj[node][i]]==1)
            {
                // visited[adj[node][i]] = 1;
                return 1;
            }
            if(solveDfs(adj[node][i], adj, visited, node))
            return 1;
        }
        return 0;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(V,0);  
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i] && solveDfs(i,adj,visited,-1))
            return 1;
        }
        return 0;
    }
};
```


Sure! Here's your code explained in **bullet points** — clean and clear:

---

###  **Goal: Detect Cycle in an Undirected Graph**

---

### 🔧 **Function: `isCycle(int V, vector<vector<int>>& edges)`**

- Takes:
  - `V`: number of vertices.
  - `edges`: list of edges (each is a pair of nodes).

####  Step 1: Build Adjacency List
```cpp
vector<vector<int>> adj(V);
for(auto it : edges) {
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
}
```
- Represent the graph using an adjacency list.
- Since it's undirected, add both directions for each edge.

####  Step 2: Initialize Visited Array
```cpp
vector<int> visited(V, 0);
```
- Keeps track of whether a node has been visited or not.

####  Step 3: Traverse All Nodes
```cpp
for(int i = 0; i < V; i++) {
    if(!visited[i] && solveDfs(i, adj, visited, -1))
        return true;
}
```
- Loop through all nodes to cover disconnected components.
- Start DFS if the node hasn't been visited.
- If `solveDfs()` finds a cycle, return `true`.

---

### 🔧 **Function: `solveDfs(int node, ...)` — DFS Helper**

####  Step 1: Mark Node as Visited
```cpp
visited[node] = 1;
```

####  Step 2: Check All Neighbors
```cpp
for(int i = 0; i < adj[node].size(); i++) {
```

##### ➤ If neighbor is the parent → **Skip**
```cpp
if(parent == adj[node][i]) continue;
```

##### ➤ If neighbor is visited (not parent) → **Cycle Detected**
```cpp
if(visited[adj[node][i]] == 1) return true;
```

##### ➤ Else → **Recurse DFS on unvisited neighbor**
```cpp
if(solveDfs(adj[node][i], adj, visited, node)) return true;
```

####  Step 3: No Cycle Found → Return False
```cpp
return false;
```

---


-  DFS is used to traverse the graph.
-  If a visited node is encountered again **not via parent**, it means a cycle exists.
-  The function covers **all disconnected components**.
-  Returns `true` if cycle is found, else `false`.

---
