// Here I am not explain entire steps because 95% similar to yesterday potd

TC : O(N)
SC : O(N)
Code + Explanation

int countPairs(vector<int> &arr, int target) {
    unordered_map<int,int>mp;
    int cnt = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(mp.find(target-arr[i])!=mp.end())  //Array traverse karte waqt har element arr[i] ke liye check karte hain ki target - arr[i] map mein hai ya nahi.
       
        cnt = cnt + mp[target-arr[i]]; // Agar hai, toh uska count cnt mein add kar dete hain.
        
        mp[arr[i]]++; //Phir current element arr[i] ko map mein update karte hain (mp[arr[i]]++).
    }
    return cnt;
}

// ********* readme ****************
1. Kal ka POTD:
    • Sirf target - arr[i] check karke pair milte hi return kar dete hain.

2. Aaj ka POTD:
    • Saare pairs count karne hain jo target sum banate hain.
    • Isliye map mein frequency rakhte hain aur target - current element ki frequency ko cnt mein add karte hain.

3. Logic Change:
    • Sirf ek additional step: cnt mein frequency add karna
