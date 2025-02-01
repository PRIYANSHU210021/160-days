Problem: Word Search

*code:*

```c++

class Solution {
  public:
  int m,n;
  vector<vector<int>> path{{1,0},{-1,0},{0,1},{0,-1}};
  bool solve(vector<vector<char>>&mat, int i,int j, string &word,int idx){
      if(idx == word.length())
      return true;
      if(i<0 || j<0 || i>=n || j>=m || mat[i][j]=='$'|| mat[i][j]!=word[idx])
      return false;
      char backup = mat[i][j];
      mat[i][j] = '$';
      for(int p = 0; p<path.size(); p++)
      {
          int new_i = i+path[p][0];
          int new_j = j+path[p][1];
          if(solve(mat,new_i,new_j,word,idx+1))
              return true;
      }
      mat[i][j] = backup;
      return false;
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
       n = mat.size(), m = mat[0].size();
       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(mat[i][j]==word[0] && solve(mat,i,j,word,0))
               return true;
           }
       }
           return false;
    }
};

```


*Approach*
This code is solving the **Word Search** problem using **Depth First Search (DFS)** with **backtracking**. Let's break down the logic step by step.

---

## **Understanding the Problem Statement**
- You are given a 2D matrix `mat[][]` of size `n*m` containing English alphabets.
- You need to check whether a given `word` exists in the matrix.
- The word can be formed by moving **horizontally or vertically** to adjacent cells.
- **Each cell can only be used once** in a single search path.

---

## **Logic and Explanation of the Code**
The solution uses **DFS (Depth First Search) with Backtracking** to explore all possible paths in the matrix.

### **1. Class Variables and Direction Vectors**
```cpp
class Solution {
public:
    int n, m;
    vector<vector<int>> path{{1,0}, {-1,0}, {0,1}, {0,-1}};
```
- `n, m`: Stores the size of the matrix.
- `path` vector defines the four possible directions of movement:
  - `{1,0}` → Move **down**.
  - `{-1,0}` → Move **up**.
  - `{0,1}` → Move **right**.
  - `{0,-1}` → Move **left**.

---

### **2. The Recursive `solve` Function (DFS)**
```cpp
bool solve(vector<vector<char>>& mat, int i, int j, string &word, int idx) {
    if (idx == word.length())
        return true; // Found the complete word
    
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == '$' || mat[i][j] != word[idx])
        return false; // Out of bounds or character mismatch
    
    char backup = mat[i][j];  // Store the original character
    mat[i][j] = '$';  // Mark as visited
    
    for (int p = 0; p < path.size(); p++) {
        int new_i = i + path[p][0];
        int new_j = j + path[p][1];
        
        if (solve(mat, new_i, new_j, word, idx + 1)) // Explore next character
            return true;
    }
    
    mat[i][j] = backup; // Restore the cell (Backtracking)
    return false;
}
```
### **Step-by-Step Explanation**
1. **Base Case:** If `idx == word.length()`, it means we have found the word, so return `true`.
2. **Boundary Check:** If `i, j` go out of bounds, or the cell is already visited (`'$'`), or the character doesn't match `word[idx]`, return `false`.
3. **Mark the cell as visited** (`'$'`) to avoid reusing it.
4. **Move in 4 directions** using the `path` array.
5. **If a valid path is found, return `true` immediately**.
6. **Backtracking:** If no valid path is found, restore the original character and return `false`.

---

### **3. The Main Function (`isWordExist`)**
```cpp
bool isWordExist(vector<vector<char>>& mat, string& word) {
    n = mat.size(), m = mat[0].size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == word[0] && solve(mat, i, j, word, 0))
                return true;
        }
    }
    
    return false;
}
```
### **Step-by-Step Explanation**
1. **Get Matrix Size**: Store `n` and `m`.
2. **Loop Through Each Cell**:
   - If a cell matches `word[0]`, start DFS (`solve` function).
   - If `solve` returns `true`, return `true` immediately.
3. **If No Match Found**: Return `false`.

---

## **Example Walkthrough**
### **Example 1**
```
mat[][] = 
[['T', 'E', 'E'],
 ['S', 'G', 'K'],
 ['T', 'E', 'L']]
word = "GEEK"
```
### **Execution**
1. Start searching from each cell where the first letter `'G'` appears.
2. `'G'` is found at `(1,1)`. Start DFS:
   - Move **right** to `'E'` (Valid).
   - Move **right** to `'E'` (Valid).
   - Move **down** to `'K'` (Valid).
   - Word `"GEEK"` is found → return `true`.

---

## **Time Complexity Analysis**
- Each cell is visited at most **once per search path**.
- In the worst case, we explore **all 4 directions recursively**.
- Approximate **O(N * M * 4^L)** complexity, where:
  - `N` and `M` are matrix dimensions.
  - `L` is the length of the word.
  - `4^L` is the worst-case branching factor.

---

## **Final Thoughts**
- ✅ **DFS with Backtracking ensures an optimal solution**.
- ✅ **Restoring matrix state after exploration avoids unnecessary memory usage**.
- ✅ **Efficient approach for word search problems**.
