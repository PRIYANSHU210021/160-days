# Program : Rotten Orange

# Code: 
```c++

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>rows = {0,1,0,-1};
        vector<int>cols = {1,0,-1,0};
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt =0;
        int mx =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==2){
                    q.push({{i,j},cnt});
                    visited[i][j] = 2;
                }
            }
        }
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cnt = q.front().second;
            
            mx = max(mx,cnt);
            q.pop();
            
            for(int i=0; i<4; i++){
                int row = x + rows[i];
                int col = y + cols[i];
                if(row >= 0 && row<n && col>=0 && col<m && mat[row][col]==1 && mat[row][col] !=2 && visited[row][col]==0){
                     q.push({{row,col},cnt+1});     
                     visited[row][col] = 2;
                     mat[row][col] = 2;
                }
            }
            
        }
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1)
                    return -1;
            }
        }
        return mx;
    }
};
```

Alright, let me explain your **Rotten Oranges** code step by step in a way that you'd explain to someone else.  

---

## **Explanation**
### **Goal**  
We have a grid (matrix) where:  
- `0` represents an **empty cell**.  
- `1` represents a **fresh orange**.  
- `2` represents a **rotten orange**.  

A **rotten orange** spreads its rot to adjacent fresh oranges (up, down, left, right) in **1 unit of time**.  
We need to determine **the minimum time required** for all oranges to rot. If some oranges **can’t rot**, return `-1`.

---

## **Step-by-Step Breakdown**  

### **1. Initialize Variables**
```cpp
int n = mat.size();
int m = mat[0].size();
vector<int> rows = {0,1,0,-1};
vector<int> cols = {1,0,-1,0};
queue<pair<pair<int,int>,int>> q;
vector<vector<int>> visited(n, vector<int>(m, 0));
int cnt = 0;
int mx = 0;
```
- `n` and `m` store the **number of rows and columns** in the matrix.  
- `rows` and `cols` store the **directions** (right, down, left, up) for **moving adjacent**.  
- `q` (a queue) stores **the position of rotten oranges** along with the time it took for them to rot other oranges.  
- `visited` keeps track of **which oranges have already rotted**.  
- `cnt` is initialized as `0` (used for time tracking).  
- `mx` keeps track of the **maximum time** needed to rot all oranges.  

---

### **2. Push Initial Rotten Oranges into Queue**
```cpp
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(mat[i][j] == 2){
            q.push({{i, j}, cnt});
            visited[i][j] = 2;
        }
    }
}
```
- We **loop through the matrix** and find all the initially **rotten oranges (`2`)**.  
- We **push them into the queue** with `cnt = 0` because they are **already rotten**.  
- We also **mark them as visited** in the `visited` array.

---

### **3. Process the Rotten Oranges Using BFS (Breadth-First Search)**
```cpp
while(!q.empty())
{
    int x = q.front().first.first;
    int y = q.front().first.second;
    int cnt = q.front().second;
    
    mx = max(mx, cnt);
    q.pop();
    
    for(int i=0; i<4; i++){
        int row = x + rows[i];
        int col = y + cols[i];
        if(row >= 0 && row<n && col>=0 && col<m && mat[row][col] == 1 && mat[row][col] != 2 && visited[row][col] == 0){
             q.push({{row, col}, cnt+1});     
             visited[row][col] = 2;
             mat[row][col] = 2;
        }
    }
}
```
- **BFS is used here** to spread the rot level by level.  
- We **dequeue a rotten orange**, check its time, and update `mx` (max time).  
- We **check all four directions** (right, down, left, up) for fresh oranges (`1`).  
- If a fresh orange is found:
  - We **add it to the queue** with time `cnt + 1`.
  - We **mark it as visited** and update `mat[row][col] = 2` to make it rotten.  

---

### **4. Check If Any Fresh Oranges Are Left**
```cpp
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(mat[i][j] == 1)
            return -1;
    }
}
return mx;
```
- After BFS, we **scan the matrix** to see if any **fresh oranges (`1`) remain**.  
- If any fresh orange is left, **return `-1`** (not all oranges can rot).  
- Otherwise, **return `mx`**, which is the **minimum time taken** for all oranges to rot.

---

## **How the Code Works**
### **Example 1**
#### **Input:**
```cpp
mat = {
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}
};
```
#### **Step-by-Step Execution**
1. **Find rotten oranges (`2`)** → Add `(0,0,0)` to queue.  
2. **Start BFS:**
   - `(0,0,0)` rots `(0,1,1)`, `(1,0,1)`.  
   - `(0,1,1)`, `(1,0,1)` rot their adjacent fresh oranges, and so on...  
3. **Matrix after rotting process:**
   ```
   {2, 2, 2},
   {2, 2, 0},
   {0, 2, 2}
   ```
4. **Time taken = 4.**  

#### **Output:**  
```cpp
4
```

---

### **Example 2 (Impossible Case)**
#### **Input:**
```cpp
mat = {
    {2, 1, 1},
    {0, 1, 1},
    {1, 0, 1}
};
```
- BFS **cannot reach** the fresh orange at `(2,0)`.  
- **Returns `-1`** because some fresh oranges never rot.

---
