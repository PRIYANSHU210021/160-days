# Problem: Dijkstra Algorithm

# Code:
```c++
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<pair<int,int>> adj[V];
        for(auto x: edges){
            adj[x[0]].push_back({x[1] , x[2]});
            adj[x[1]].push_back({x[0] , x[2]});
        }
        
        vector<int>minDis(V,1e9);
        
        minDis[src]=0;
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src}); // 1st distance khud se , or from given src
        
        while(!pq.empty()){
            int wgt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            // for(int i=0; i<adj[node].size(); i++)
            for(auto x: adj[node])
            {
                 if( wgt+x.second < minDis[x.first] )
                 {
                     minDis[x.first] = wgt+x.second;
                     pq.push({minDis[x.first], x.first});
                 }
            }
            
            
        }
       return minDis;
    }
};
```
Sure! Let's break it down **step-by-step**, with a **clear explanation + intuition** for the `dijkstra` function you shared.

---

## 🧠 **Intuition**
Dijkstra's algorithm finds the **shortest path from a source node to all other nodes** in a **weighted graph** (no negative weights).  
It works by **greedily choosing the node with the smallest known distance**, updating its neighbors, and repeating until all nodes are covered.

Think of it like **spreading out from the source** in all directions, always choosing the closest point you haven’t visited yet.

---


## 🔍 Code Explanation with Intuition

### Step 1: Create the adjacency list
```cpp
vector<pair<int,int>> adj[V];
for(auto x: edges){
    adj[x[0]].push_back({x[1] , x[2]});
    adj[x[1]].push_back({x[0] , x[2]});
}
```

**What’s happening?**  
We’re converting the edge list into an **adjacency list** for easier lookup.  
We store `adj[u]` as a list of `{v, weight}`.

➡️ Example:  
Edge `[0, 1, 4]` becomes  
`adj[0] = {{1, 4}}` and `adj[1] = {{0, 4}}` (since the graph is undirected)

---

### Step 2: Initialize distances
```cpp
vector<int>minDis(V,1e9); // start with INF (infinite distance)
minDis[src]=0; // source to itself is 0
```

We assume all nodes are unreachable (distance = 1e9).  
Only the source node has distance 0 from itself.

---

### Step 3: Set up min-heap (priority queue)
```cpp
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({0,src});
```

This is a **min-heap** that always gives the next node with the smallest known distance.  
We push the source node with weight `0`.

➡️ Format: `{distance, node}`

---

### Step 4: Run Dijkstra’s main loop
```cpp
while(!pq.empty()){
    int wgt = pq.top().first;
    int node = pq.top().second;
    pq.pop();
```

We extract the closest node (the one with current smallest distance) and explore its neighbors.

---

### Step 5: Explore neighbors and update distances
```cpp
for(auto x: adj[node]){
    if( wgt + x.second < minDis[x.first] )
    {
        minDis[x.first] = wgt + x.second;
        pq.push({minDis[x.first], x.first});
    }
}
```

For each neighbor:
- If going through the current node gives a **shorter path**, update the distance.
- Push that neighbor into the queue with the new shorter distance.

➡️ We’re **greedily updating** the shortest known path.

---

### Step 6: Return the result
```cpp
return minDis;
```

After processing all nodes, `minDis[i]` contains the shortest distance from `src` to node `i`.

---

## 🧪 Example
Input:
```cpp
V = 4, src = 0
edges = {
  {0, 1, 1},
  {0, 2, 4},
  {1, 2, 2},
  {1, 3, 6},
  {2, 3, 3}
}
```

Output:
```cpp
minDis = [0, 1, 3, 6]
```

