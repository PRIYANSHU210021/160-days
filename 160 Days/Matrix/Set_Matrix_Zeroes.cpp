// Set Matrix Zeroes


// First Solve with taking space:
// TC: O(n*m)
// SC: O(n+m)

// Code + Explanation

void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int>col(m,0); // ye as a marker le liye hai 
        vector<int>row(n,0);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0) // agar koi bhi cell mera zero hua to ...
                {
                    col[j] = 1;  // ... to hmm usi ke correspoding bnaye hue column or row vector me 1 mark kar denge
                    row[i] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(col[j] || row[i])
                {
                    mat[i][j]=0; // Agar row ya column 1 mark hai, to element ko 0 kar do
                }
            }
        }
    }







    // ************************ Optimal **************************
    // First Solve with taking space:
    // TC: O(n*m)
    // SC: O(1)

    // !Dekho !Dekho yaha hmm naya vector lene ke bajaye apne first row or column ko as a marker use karne wale hai 

    void setMatrixZeroes(vector<vector<int>> &mat) {

        int n = mat.size(), m = mat[0].size();

        int col_flg = 0, row_flg = 0; 
        
        for(int i=0; i<n; i++)
        {
            if(mat[i][0] == 0)
            {
                col_flg = 1; break;
            }
        }

        for(int i=0; i<m; i++)
        {
            if(mat[0][i] == 0)
            {
                row_flg = 1; break;
            }
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    mat[i][0] = 0; mat[0][j] = 0;
                }
            }
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                if(mat[i][0] == 0 || mat[0][j]==0)
                mat[i][j]=0;
            }
        }

        if(col_flg)
        {
            for(int i=0; i<n; i++) 
            mat[i][0] =0;
        }

        if(row_flg)
        {
            for(int i=0; i<m; i++) 
            mat[0][i] = 0;
        }
    }

// ************************** readme optimal way *************************


Code ka Overall Idea Tagde Me 😊; 

Step 1:
1. First Row aur First Column ko Markers ki tarah Use Karna:

    mat[0][j] aur mat[i][0] ko use karke yeh track kiya ja raha hai ki kaunsa column aur row baad me zero hona chahiye.
    Extra space row[] aur col[] arrays ka use karne ki jagah matrix ke first row aur column ko hi marker ki tarah use kiya ja raha hai.

2. Flags (Markers) for First Row aur First Column:

    Ek special check kiya gaya hai ki first row aur first column ko modify karna hai ya nahi (alag markers, row_flg aur col_flg, use karke).
3. 
    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 0) {
            col_flg = 1; break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (mat[0][i] == 0) {
            row_flg = 1; break;
        }
    }
    First Column (mat[i][0]): Check karte hain ki kya first column me koi zero hai. Agar hai, to col_flg = 1 set kar dete hain.
    First Row (mat[0][j]): Check karte hain ki kya first row me koi zero hai. Agar hai, to row_flg = 1 set karte hain.



Step 2: Baaki Matrix ke liye First Row aur Column ko Marker ki tarah Use Karna  
for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        if (mat[i][j] == 0) {
            mat[i][0] = 0; // Mark row
            mat[0][j] = 0; // Mark column
        }
    }
}

Aap matrix ko traverse karte hain (first row aur column ko chhod kar).  
Agar koi element mat[i][j] zero hai:  
First Column: mat[i][0] = 0, is row ke liye marker.  
First Row: mat[0][j] = 0, is column ke liye marker.  

---

Step 3: Matrix ko Zero Karna Marker ke Basis Par
for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
        if (mat[i][0] == 0 || mat[0][j] == 0) {
            mat[i][j] = 0; // Row ya Column mark hone par zero kar do
        }
    }
}

Ab traverse karke check karte hain:  
Agar row ke marker (mat[i][0] ) ya column ke marker mat[0][j] zero hai, to  mat[i][j] ko 0 kar dete hain.



Step 4: First Row aur First Column ko Modify Karna
if (col_flg) {
    for (int i = 0; i < n; i++) mat[i][0] = 0;
}
if (row_flg) {
    for (int i = 0; i < m; i++) mat[0][i] = 0;
}
First Column Modify: Agar col_flg = 1, to poore first column ko zero kar dete hain.  
First Row Modify: Agar row_flg = 1, to poore first row ko zero kar dete hain.