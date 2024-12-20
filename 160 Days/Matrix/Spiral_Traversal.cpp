// ************************************ Code ************************************

// Time Complexity: O(nxm)
// Space Complexity:O(nxm) due to take v vector

 vector<int> spirallyTraverse(vector<vector<int> > &mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<int>v;
       int top = 0, left = 0, right = m-1, bottom = n-1;
            // top (upar wali boundary): Pehli row.
            // bottom (neeche wali boundary): Last row.
            // left (left boundary): Pehla column.
            // right (right boundary): Last column.


    while(top<=bottom && left<=right) //Jab tak boundaries valid hain (top <= bottom aur left <= right), traversal repeat hota hai.
    {
        //cover left to right
        for(int i=left; i<=right; i++) 
            v.push_back(mat[top][i]);
        top++;

        // Upar ki row (top) ko traverse karte hain left se right.
        // top++ karte hain, kyunki upar ki row ka kaam ho gaya.




        //cover top to bottom
        for(int i=top; i<=bottom; i++)
            v.push_back(mat[i][right]);
        right--;

        // Ab right column (right) ko traverse karte hain top se bottom.
        // right-- karte hain, kyunki right column ka kaam ho gaya.



        //cover right to left
        if(top <= bottom)
        {
            for(int i=right; i>=left; i--)
                v.push_back(mat[bottom][i]);
            bottom--;
        }

        // Agar abhi bhi rows bachi hain (top <= bottom), to neeche ki row (bottom) ko right se left traverse karte hain.
        // bottom-- karte hain, kyunki neeche ki row ka kaam ho gaya.




        // cover bottom to top
        if(left<=right)
        {
        for(int i=bottom; i>=top; i--)
            v.push_back(mat[i][left]);
        left++;
        }

        // Agar abhi bhi columns bache hain (left <= right), to left column (left) ko bottom se top traverse karte hain.
        // left++ karte hain, kyunki left column ka kaam ho gaya.



    }
       return v;
    }

// Edge case

//     if(left <= right) aur if(top <= bottom) kyun zaroori hain?

// Jab matrix ko spiral order me traverse karte hain, to top, bottom, left, aur right boundaries ko adjust karte hain. Yeh conditions isliye lagate hain taaki:

// 1.Boundary Overlap Avoid Ho:

// Jab top > bottom ya left > right ho jaye, iska matlab hai ki saare elements traverse ho chuke hain.
// Agar yeh conditions na lagayein, to algorithm already processed rows/columns ko dubara traverse karne ki koshish karega, jo galat hoga.

// 2.Edge Cases Handle Ho:

// Agar matrix me single row ya column ho, to top == bottom ya left == right hoga shuruaat me hi.
// Aise cases me unnecessary steps ko avoid karne ke liye yeh conditions lagate hain.