//  Search in a row-wise sorted matrix

// TC : O(row * log column)
// SC : O(1)

// Intuition:

// Matrix Properties:

// Each row in the matrix is sorted in ascending order.
// To find a specific element x, you can perform a binary search on each row individually, as binary search works efficiently on sorted arrays.

 
 bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int i=0;
        int j = mat[0].size()-1;
        while(i<mat.size())
        {
            int start = 0,end = j;
            while(start<=end && i<mat.size())
            {
                int mid = start +(end - start)/2;
                if(mat[i][j]>=x)
                {
                    if(mat[i][mid] == x)
                        return true;
                    if(mat[i][mid] < x)
                        start = mid+1;
                    else
                        end = mid -1;
                }
                else
                    i++;
            }
            i++;
        }
        return false;
    }



// *************************** README ********************************


// Matrix ki properties:

// Har row matrix mein sorted hai, yani har row ke elements chhoti se badi order mein hain.
// Agar hume kisi element x ko dhoondhna hai, toh hum har row pe binary search laga sakte hain, kyunki binary search sorted arrays mein fast kaam karta hai.

                                                    // Step-by-step Approach:

// 1. Start karo pehli row se: 
    // i = 0 se shuruaat hoti hai, jo pehli row ko represent karta hai.
    // Row ke andar binary search karne ke liye do pointers set karte hain:
    // start jo row ke starting index ko represent karta hai.
    // end jo row ke last column index (j) ko represent karta hai.


// 2. Binary Search Kaise Kaam Karta Hai:
    // Har row mein start aur end pointers ka use karke mid point calculate karte hain:
    // cpp
    // Copy code
    // int mid = start + (end - start) / 2;
    // Fir check karte hain:
    // Agar mat[i][mid] == x, toh element mil gaya, aur true return karte hain.
    // Agar mat[i][mid] < x, iska matlab x right side mein hoga, toh start = mid + 1 karte hain.
    // Agar mat[i][mid] > x, iska matlab x left side mein hoga, toh end = mid - 1 karte hain.

// 3. Next Row Pe Move Karna:
    // Agar current row mein x nahi milta, toh i++ karte hain, aur next row pe jaate hain.
    // Jab tak sari rows check nahi hoti (i < mat.size()), loop chalta hai.


// 4. Final Output:
    // Agar kisi row mein x milta hai, toh true return hota hai.
    // Agar puri matrix check kar li aur x nahi mila, toh false return hota hai.    
