
// Search in a Row-Column sorted matrix
// T.C: (n + m)
// S.C: O(1)

 bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n = mat.size();
        int m = mat[0].size();
        
        int i=0, j = m-1; 
        while(i<n && j>=0)
        {
            if(mat[i][j]==x)
            return true;
            if(mat[i][j]>x)
            j--;
            else
            i++;
        }
        return false;        
    }

// ****************************** README *******************************
// 1. Input Details:

// Ek 2D matrix (mat[][]) di gayi hai jo sorted hai:
// Har row increasing order me sorted hai.
// Har column bhi increasing order me sorted hai.
// Ek number x diya gaya hai jo aapko matrix me dhoondhna hai.

// 2. Approach:

// Matrix ke top-right corner (row 0, column m-1) se search start karte hain:
// Agar mat[i][j] == x, to element mil gaya, aur true return karte hain.
// Agar mat[i][j] > x, iska matlab hai ki x is column me ho hi nahi sakta, to column left side me shift karte hain (j--).
// Agar mat[i][j] < x, iska matlab hai ki x is row me ho hi nahi sakta, to row niche shift karte hain (i++).
// Ye process tab tak chalti hai jab tak ya to element mil jaye, ya matrix ke boundaries cross ho jayein.