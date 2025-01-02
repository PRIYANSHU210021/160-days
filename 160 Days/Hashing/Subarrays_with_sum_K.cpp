// First I perform Brute which not pass all test cases because it TC is O(N^2)
// Then using hashing, Solve in Lirear Time Complexity.

This problem is similar to the initial topics of hashing, as seen in today's POTD (Problem of the Day). Here, we just need to hash the prefix sum. While calculating the cumulative sum, if the sum directly equals k, then that’s fine. Otherwise, we check if removing some element x from the prefix sum makes it equal to k.  
This means we need to find x in the map, where ( x = sum - k ). If we find it, we add its frequency to cnt. We also store the current prefix sum as a key in the map and assign its frequency.  
Finally, we return cnt.

Problem : Subarrays with sum K

Code:

TC : O(N)
SC : O(N)
int countSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int cnt =0,sum=0;
        for(int i=0; i<n; i++)
        {
            sum +=arr[i];
            if(sum==k) cnt++;
            if(mp.find(sum-k)!=mp.end())
            cnt +=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }

Intution:

Beauty of  prefix sum:
Agar kisi index i tak ka sum hai sum, aur pehle kisi index j tak ka sum sum-k tha, toh:
sum[i]-sum[j]=k
Matlab, j+1 se lekar i tak ka subarray ka sum exactly k hoga.

Key idea:
Har index i par hume yeh dekhna hai:
Kya ab tak ka total sum == k hai? Agar haan, toh ek valid subarray mila.
Kya sum-k pehle kabhi mila hai? Agar mila hai, toh jitni baar mila hai, utne subarrays ka sum k hoga jo i par khatam hote hain.

Hash Map Ka Role:
Jab hume sum-k milta hai hash map mein, toh iska matlab hai ki us point tak jitni baar woh sum aaya hai, utne subarrays ka sum k hoga.

Dry run krne se ye problem acche se smjh aa jata hai.
