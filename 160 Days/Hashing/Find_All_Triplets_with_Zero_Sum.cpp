// Find_All_Triplets_with_Zero_Sum


// Naive Approach is very easy by taking 3 loop , which takes n^3 complexity 

// We perform in O(n^2) here 

Intution :

// Is code ka intuition yeh hai ki hume array ke andar aise unique triplets dhoondhne hain jinka sum zero ho. Har do elements ka sum leke, teesra element (jo negative of sum hoga) dhoondhte hain.

// Har element ko ek hash map (mp) me store karte hain, jo element ka value aur index track kare.
// Nested loops ke through, pehle do elements ka sum nikalte hain aur teesra element (target) hash map me dhoondhte hain.
// Agar target mile aur indices unique ho, to triplet banake store karte hain (duplicate avoid karne ke liye set use hota hai).
// Final unique triplets ko ek vector me convert karke return kar dete hain.


Code : 
TC:O(n^2)
SC:O(n^2)

 vector<vector<int>> findTriplets(vector<int> &arr) {
       int n = arr.size();
       unordered_map<int,int>mp;0
       set<vector<int>>st;
       
       for(int i=0; i<n; i++)
        mp[arr[i]] = i; 
       
       for(int i=0;i<n-1;i++)
       {
           for(int j=i+1; j<n; j++)
           {
               int target = -1*(arr[i]+arr[j]);
               if(mp.find(target) != mp.end() && (i!=mp[target] && j!=mp[target]))
               {
                    vector<int>v{i,j,mp[target]};
                    sort(v.begin(),v.end());
                    st.insert(v);
               }
           }
       }
       vector<vector<int>>ans(st.begin(),st.end());
       return ans;
       
    }

// ******************** Readme *************************

1. Input aur Initialization:
    arr ek integer array hai, aur n uska size hai. Ek unordered_map<int, int> banaya hai jo array ke elements ko unke indices ke saath map karega. set<vector<int>> unique triplets store karne ke liye use hota hai.

2. Mapping Elements:
Pehle loop me, har element ka index mp map me store kiya gaya hai (mp[arr[i]] = i).

3. Finding Triplets:
Nested loops i aur j ke liye chal rahe hain:
• i aur j ke sum ka negative (-1 * (arr[i] + arr[j])) target banate hain.
• Agar mp me target exist karta hai aur target ka index i aur j se alag hai, to ek triplet (i, j, mp[target]) milta hai.
• Triplet ko sort karke set me insert kar dete hain, taaki duplicate triplets avoid ho jayein.

4. Set ke elements ko vector<vector<int>> me convert karke return karte hain.