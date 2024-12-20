//Rotate by 90 degree

// Naive Approach 
// T.C = O(N*N)
// S.C = O(N)

void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int>v;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                v.push_back(mat[j][i]);
            }
        }
        int k = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                mat[i][j] = v[k];
                k++;
            }
        }
        
}

// Optimal in Term of space
// T.C = O(N*N)
// S.C = O(1)

void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i=0; i<n; i++)
            reverse(mat[i].begin(),mat[i].end());

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(i!=j)
                swap(mat[i][j],mat[j][i]);
            }
        }
    }


// *************************** README *******************************

// Intuition

// To rotate a matrix by 90 degrees anti-clockwise in-place (without using extra space), we can break the problem into two steps:

// Horizontal Reverse: Reverse the order of elements in each row. This operation essentially mirrors the matrix along a vertical axis.
// Transpose: Swap the elements [i][j] and [j][i] for all elements above the diagonal (wherei<j). This converts rows into columns and results in a 90-degree rotation.
// By combining these two steps, the matrix is rotated 90 degrees anti-clockwise without needing any extra space.

// 1. Pehla Step: Row Reverse

// • Har ek row ka order reverse kar dete hain.
// • Yeh kaam reverse(mat[i].begin(), mat[i].end()) karta hai.
// • Is step ke baad matrix ka structure mirror ho jaata hai (vertical axis ke along).

// 2. Dusra Step: Transpose

// • Har element [i][j] aur [j][i] ko swap karte hain, sirf diagonal ke upar wale elements ke liye (jahaan i<j).
// • Yeh step rows ko columns mein convert karta hai.
// • Jaise-jaise swap karte hain, matrix rotate hone lagta hai.

// Iss Points Ko note kar lo, thats it:

// Pehle reverse karo row-wise.
// Fir transpose karke elements ko swap karo.
// In dono steps ke baad matrix 90 degrees anti-clockwise rotate ho jaata hai.

