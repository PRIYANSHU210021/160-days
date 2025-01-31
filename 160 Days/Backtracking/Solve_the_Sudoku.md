Problem: Solve the Sudoku

```c++

class Solution {
  public:
    // Function to find a solved Sudoku.
     bool checker(int t,int r,int c,vector<vector<int>>& mat,int n){
         for(int j=0;j<n;j++){
             if(mat[r][j]==t) return 0;
         }
         for(int i=0;i<n;i++){
             if(mat[i][c]==t) return 0;
         }
         
         int x=r-(r%3);
         int y=c-(c%3);
         
         for(int i=x;i<x+3;i++){
             for(int j=y;j<y+3;j++){
                 if(mat[i][j]==t) return 0;
             }
         }
         
         return 1;
    }
    bool helper(int row,int col,vector<vector<int>>& mat,int n){
       
       if(row==9) return true;
       if(col==n){
          return helper(row+1,0,mat,n);   
       }
       if(mat[row][col]!=0){
           return helper(row,col+1,mat,n);
       }
       
       
       for(int k=1;k<=9;k++){
           if(checker(k,row,col,mat,n)){
               mat[row][col]=k;
               bool ans=helper(row,col+1,mat,n);
               if(ans){
                   return true;
               }else 
               mat[row][col]=0;
           }
       }
           
        return false;   
    }
    void solveSudoku(vector<vector<int>> &mat) {
       helper(0,0,mat,mat.size());
    }
};

```
