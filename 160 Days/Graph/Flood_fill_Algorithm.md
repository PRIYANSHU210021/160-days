# Problem: Flood fill Algorithm
# Code:
```c++
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];
        if (startColor == newColor) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        vector<int>rows = {0,1,0,-1};
        vector<int>cols = {1,0,-1,0};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            image[x][y] = newColor;
            
            for(int i=0; i<4; i++)
            {
                int row = x+rows[i];
                int col = y+cols[i];
                
                if(row>=0 && row<n && col>=0 && col<m && image[row][col]==startColor )
                q.push({row,col});
            }
        }
        
        return image;
        
    }
};
```

---

Here I'm using **BFS** to color all connected cells (up/down/left/right) that have the **same color as the starting cell** (`startColor`) and replacing them with `newColor`.

---

###  Step-by-step:
1. **Base Check**: If `startColor == newColor`, nothing to change → return early.
2. **Start BFS** from `(sr, sc)` using a queue.
3. **Explore 4 directions** (up, down, left, right).
4. **If neighbor has same `startColor`**, push it to the queue.
5. Keep updating the color to `newColor` as you go.
6. Return the updated `image`.

---
