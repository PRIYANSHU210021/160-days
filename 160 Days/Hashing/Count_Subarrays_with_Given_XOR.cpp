Problem : Count_Subarrays_with_Given_XOR

Same as Yesterday potd (Subarrays with sum K)

Notable: suppose a = 3, b = 5 and x = ? , when we perfor 3 ^ x = 5, so for what value of x we got 5 as result , here
we perform sequence like, x = 5 ^ 3 (or x = b^a) , x = 6, it means if we put x = 6, we got 5. 


Code + Explanation:

TC: O(N)
SC: O(N)

 long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int>mp;
        int sum=0,cnt =0;
        for(int i=0;i<arr.size();i++)
        {
            sum ^= arr[i];  // work as prefix XOR
            if(sum == k) cnt++; // if direct prefix equal to k than cnt++
            if(mp.find(sum^k) != mp.end()) // other wise we check in map if suppose(k=6) and   4 ^ x = 6 , so here if we put x = 2 than 4 ^2 = 6 and best thing is that if we perform 4^6 = 2 (x=2) it means thats we if we got sum^k in previos prefix than include its frequency )
            cnt += mp[sum^k];
            mp[sum]++; // update prefix in map with frequency as well.
        }
        return cnt;
    }

