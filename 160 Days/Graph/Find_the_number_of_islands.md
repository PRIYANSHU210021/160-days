# Problem: Find the number of islands

# Code: 
```c++
    class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        
    int n = grid.size();
    int m = grid[0].size();
    
    vector<int>rows={0,1,0,-1,-1,1,1,-1};
    vector<int>cols={1,0,-1,0,1,1,-1,-1};
    vector<vector<int>>visited(n,vector<int>(m,0));
    
    int cnt = 0;
    queue<pair<int,int>>q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j] == 0 && grid[i][j]=='L')
            {
                q.push({i,j});
                visited[i][j]==1;
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
            
                    q.pop();
                    for(int i=0; i<8; i++)
                    {
                        int row = x+rows[i];
                        int col = y+cols[i];
                        
                        if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0 &&
                        grid[row][col]=='L')
                        {
                            visited[row][col] = 1;
                            q.push({row,col});
                        }
                    }
                }
                cnt++;
            }
        }
    }
    
    return cnt;
    }
};
```

"Imagine we’re looking at a map STL wala nhi bhai) made of small squares. Some squares are **land** (marked as `'L'`), and some are **water** (marked as `'W'`).

Now, our job is to **count how many islands** are there.  
An island means land that’s connected — it could be touching **sideways or even diagonally**.

So, here’s what I do:

1. I go through each square on the map.
2. If I find a land (`'L'`) that I haven’t visited yet, I say,  
    *'Oh! This could be a new island!'*
3. Then I start looking around that land in all directions to see how big the island is.
4. I keep marking all the land I visit, so I don’t count it again.
5. Once I finish exploring that whole group of land, I count it as **one island**.
6. Then I keep moving through the rest of the map and do the same for any new unvisited land.

At the end, the number of times I found and explored new land groups — that’s the number of islands."

---
