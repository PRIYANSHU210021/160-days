# Problem : Breadth-First Search (BFS)

# Code: 
```c++
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        
        queue<int>q;
        vector<int>ans;
        vector<bool>visited(n,0);
        
        q.push(0);
        visited[0] = 1;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            
            for(int i=0; i<adj[curr].size(); i++)
            {
                if(visited[adj[curr][i]]==0)
                {
                    visited[adj[curr][i]] = 1;
                    q.push(adj[curr][i]);
                }
            }
        }
        return ans;
    }
};
```


Here's how this BFS (Breadth-First Search) works:

1. **Think of the graph as a friend network**  
   - Each person (node) is connected to other people (nodes) through friendships (edges).  

2. **We start from the first friend (node 0)**  
   - We use a **queue** (just like a line where people wait for their turn) to keep track of the friends we need to visit.  
   - We also maintain a **visited list** to ensure we don’t visit the same friend twice.

3. **Process each friend one by one**  
   - Take the first person from the queue.  
   - Add them to the answer list (so we know we visited them).  
   - Check all their friends. If a friend is not visited yet, mark them as visited and push them into the queue (so we visit them later).

4. **Repeat until no one is left in the queue**  
   - This ensures we visit all friends level by level, just like calling all direct friends first before moving to their friends.

