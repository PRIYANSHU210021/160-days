Problem: N-Queen Problem


code:

```c++
class Solution {
  public:
    void solve(int row,int n, vector<int> temp, vector<vector<int>> &res,vector<int> &upCol,vector<int> &rightDiag,vector<int> &leftDiag){
        if(row==n){
            res.push_back(temp);
            return;
        } 
        for(int i=0;i<n;i++){
            if(upCol[i]==0 && leftDiag[n-1+row-i]==0 && rightDiag[row+i]==0){
                upCol[i]=1;
                leftDiag[n-1+row-i]=1 ;
                rightDiag[row+i]=1;
                temp.push_back(i+1);
                solve(row+1,n,temp,res,upCol,rightDiag,leftDiag);
                upCol[i]=0;
                leftDiag[n-1+row-i]=0 ;
                rightDiag[row+i]=0;
                temp.pop_back();
            }
        }
    }
    
    bool check(int row,int col,vector<vector<int>> grid){
        int n= grid.size();
        //check col
        for(int i=0;i<row;i++){
            if(grid[i][col]==1)
            return false;
        }
        //check left diagonally
        int r=row-1,c=col-1;
        while(r>=0 && c>=0){
            if(grid[r][c]==1)
            return false;
            r--;
            c--;
        }
        //right diagonally
        r=row-1,c=col+1;
        while(r>=0 && c<n){
            if(grid[r][c]==1)
            return false;
            r--;
            c++;
        }
        return true;
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> upCol(n, 0);
        vector<int> rightDiag(2 * n - 1, 0);
        vector<int> leftDiag(2 * n - 1, 0);
        solve(0,n,temp,res,upCol,rightDiag,leftDiag);
        return res;
    }
};
```


*Approach*

Your code is an implementation of the **N-Queens problem** using **backtracking** and an optimized approach with auxiliary arrays. Here's a breakdown of how it works:

### **Key Functions and Logic**

#### **1. `solve` Function (Recursive Backtracking)**
- This function attempts to place queens **row by row**.
- If `row == n`, it means a valid arrangement is found, and it's stored in `res`.
- The **for loop** iterates through each column (`i`) to check if a queen can be placed.
- The **three auxiliary arrays** are used to check for conflicts:
  - `upCol[i]`: Ensures no other queen is in column `i`.
  - `leftDiag[n-1+row-i]`: Ensures no queen is on the left diagonal (\).
  - `rightDiag[row+i]`: Ensures no queen is on the right diagonal (/).
- If placing a queen is valid, it is **marked (1)**, added to `temp`, and `solve` is called for the next row.
- After the recursive call, the queen is **removed (backtracking step)** to explore other possibilities.

#### **2. `check` Function (Unused)**
- This function checks whether a queen can be placed at `grid[row][col]` using **loops**:
  - It checks the **column** above.
  - It checks the **left diagonal (\)**.
  - It checks the **right diagonal (/)**.
- However, this function is **not used** in your actual `nQueen` function.

#### **3. `nQueen` Function (Main Driver)**
- Initializes:
  - `res` (to store results).
  - `temp` (to store a single valid arrangement).
  - `upCol`, `rightDiag`, and `leftDiag` arrays (for conflict tracking).
- Calls `solve(0, n, temp, res, upCol, rightDiag, leftDiag)`.
- Returns `res`, which contains all valid solutions.

### **Complexity Analysis**
- **Time Complexity:** **O(N!)** (since we try placing queens row by row and backtrack)
- **Space Complexity:** **O(N)** (for auxiliary arrays and recursive stack)

### **Summary**
Your code efficiently solves the N-Queens problem using backtracking and **auxiliary arrays** for fast conflict checking. However, the `check` function is **redundant** and can be removed.