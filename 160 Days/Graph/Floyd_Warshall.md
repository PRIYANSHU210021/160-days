# Problem: Floyd Warshall
# Code : 
```c++
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int i=0;i<n; i++)
        {
            if(dist[i][i]==-1)
            dist[i][i]=1000;
        }
        for(int via = 0; via<n; via++){
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][via]+dist[via][j] <dist[i][j])
                dist[i][j] = dist[i][via]+dist[via][j];
            }
        }
        }
        for(int i=0;i<n; i++)
        {
            if(dist[i][i]==1000)
            dist[i][i]=-1;
        }
    }
};

```

---

###  **Floyd-Warshall Intuition (Point-Wise)**

---

1. **Input**:  
   You’re given a matrix `dist[i][j]` representing the distance from node `i` to `j`. `-1` means **no path**.

---

2. **Convert -1 to large value**:  
   You’re trying to treat `-1` as "infinite" by converting it to a large number (`1000`) so it doesn't affect the minimum path calculations.  

---

1. **Run Floyd-Warshall**:
   For each node `via`, check if going from `i → via → j` is shorter than current `i → j`.  
   If yes, update `dist[i][j]`.

---

4. **Convert 1000 back to -1**:  
   After running the algorithm, you're converting `1000` back to `-1` to represent no path.

---

5. **Final Result**:  
   The matrix now has the **shortest path** from every node to every other node.

---

### Simple Intuition Paragraph:

You are using the Floyd-Warshall algorithm to find the shortest path between every pair of nodes in a graph. Initially, if there's no path between nodes (marked `-1`), you temporarily replace it with a large number so it doesn't affect minimum comparisons. Then, you update each pair of distances by checking if going through another node (`via`) gives a shorter path. Finally, you convert large numbers back to `-1` to show no direct connection. This algorithm works well for graphs with both positive and negative weights (but **no negative cycles**).

---
