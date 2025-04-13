# Problem: Clone an Undirected Graph
### Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

###  Your task is to complete the function cloneGraph( ) which takes a starting node of the graph as input and returns the copy of the given node as a reference to the cloned graph.
###  Note: If you return a correct copy of the given graph, then the driver code will print true; and if an incorrect copy is generated or when you return the original node, the driver code will print false.

###  Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

# Code:
# Using DFS
```c++
class Solution {
  public:
    Node* cloneGraph(Node* node){
        if(node == NULL) return NULL;
        unordered_map<Node*,Node*>mp;
        Node* cloneNode = new Node(node->val);
        mp.clear();   
        mp[node] = cloneNode;
        queue<pair<Node*, Node*>>q;
        q.push({node,cloneNode});
        
       while(!q.empty())
       {
           Node* orgNode = q.front().first;
           Node* cloneNode = q.front().second;
           
           q.pop();
           for(Node* n:orgNode->neighbors)
           {
               if(mp.find(n)==mp.end())
               {
                   Node* newNode = new Node(n->val);
                   mp[n] = newNode;
                   cloneNode->neighbors.push_back(newNode);
                   q.push({n,newNode});
               }
               else
               {
                   cloneNode->neighbors.push_back(mp[n]);
               }
           }
       }
       return cloneNode;
    }
};

```
---
Imagine you're cloning a **social network** — you start with 1 person, clone them, then move level by level cloning their friends, their friends’ friends, and so on.

BFS helps you explore the graph **level-by-level**, just like you’d search the shortest path in a maze.

###  Step-by-step:

1. If the input node is `NULL`, return `NULL`.
2. Create the clone of the starting node.
3. Store that pair `(original, clone)` in both:
   - a `map` → to track who’s cloned
   - a `queue` → to process neighbors
4. While the queue isn't empty:
   - Get the current original node and its clone.
   - For each neighbor:
     - If that neighbor hasn’t been cloned yet:
       - Create the clone.
       - Add the mapping.
       - Push it into the queue.
       - Link this new clone to the current clone's neighbors.
     - If it's already cloned:
       - Just link the existing clone.

---



# Using BFS
```c++

class Solution {
  public:
       unordered_map<Node*,Node*>mp;
  
    void solveDfs(Node* node, Node* cloneNode)
    {
        for(Node* n:node->neighbors){
            if(mp.find(n)==mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                cloneNode->neighbors.push_back(clone);
                solveDfs(n,clone);
            }
            else
                cloneNode->neighbors.push_back(mp[n]);
        }
    }
    Node* cloneGraph(Node* node) {
       if(node == NULL) return NULL;
       Node* cloneNode = new Node(node->val);
      mp.clear();   
       mp[node] = cloneNode;
       solveDfs(node,cloneNode);
       return cloneNode;
    }
};

```
---
1. Again, check if node is `NULL`. If yes, return `NULL`.
2. Create a clone of the start node.
3. Store that in the map.
4. Start DFS:
   - For each neighbor:
     - If not cloned:
       - Create a new node.
       - Map it.
       - Connect it to the current node's clone.
       - **Recursively** call DFS to go deeper.
     - If already cloned:
       - Just connect the already cloned node.
---

