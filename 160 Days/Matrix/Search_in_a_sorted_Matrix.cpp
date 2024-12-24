// Intuition:

//  here code is to treat the 2D matrix as if it were a single sorted 1D array. 
// Since the matrix is strictly sorted (each row is sorted, and the last element of one row is smaller than the first element of the next row), 
// you can use binary search to find the target element efficiently. 
// Instead of searching row by row, the code calculates a middle index (mid) as if the matrix were flattened into a 1D array. 
// Then, it maps this mid index back to a specific row and column in the matrix. 
// By comparing the element at this position with the target, it decides whether to search in the left half or the right half of the matrix, narrowing down the search space until the element is found or the search ends. 
// This approach makes the search very fast, with a time complexity of O(log(n*m)).


// Code:

 bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        int start = 0,end = n*m-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            int r = mid / m;
            int c=  mid % m;
            if(mat[r][c] == x)
            return true;
            if(mat[r][c] > x)
            end = mid-1;
            else
            start = mid+1;
        }
        return false;
    }


// 1 Binary Search on 2D Matrix:

// int start = 0, end = n * m - 1;

// • Matrix ko ek 1D array jaisa treat karte hain.
// • start = 1D array ka starting index (0).
// • end = 1D array ka last index (n * m - 1).

// 2 Converting 1D Index to 2D Row & Column

// int r = mid / m; // Row ka index
// int c = mid % m; // Column ka index

// • Ek 1D index ko 2D row aur column me convert karte hain:
// • Row: mid / m (total columns se divide karke row milta hai).
// • Column: mid % m (total columns ka remainder column deta hai).

// 3 Adjust Search Range

// if (mat[r][c] > x)
//     end = mid - 1;
// else
//     start = mid + 1;

// Agar mat[r][c] > x hai, iska matlab x left side me hoga. end ko adjust karte hain: end = mid - 1.
// Agar mat[r][c] < x hai, toh x right side me hoga. start ko adjust karte hain: start = mid + 1.

// Why Binary Search? //
// Binary search ka time complexity O(log(n*m)) hota hai, jo 2D matrix ko efficiently traverse karne ka best method hai.

// baitha lo dimag me bhai "Concept of binary search in matrix ko "

