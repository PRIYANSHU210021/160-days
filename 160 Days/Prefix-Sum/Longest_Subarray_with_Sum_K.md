Standard Problem: Longest_Subarray_with_Sum_K

*Approach* 
 The approach uses a prefix sum combined with a hashmap (unordered_map) to efficiently track the prefix sums and their indices.

TC: O(N)
SC: O(N)

*Code*
``` c++
int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long,long>mp;
        long long prefix=0;
        int len=0,mxlen=0;
        for(int i=0; i<n; i++)
        {
            prefix += arr[i];
            if(prefix == k) 
            mxlen = max(mxlen,i+1);
            if(mp.find(prefix-k)!=mp.end())
            {
                len = i-mp[prefix-k];
                mxlen = max(mxlen,len);
            }
            if(mp.find(prefix)==mp.end())
            mp[prefix]=i;
        }
        return mxlen;
    }
```
*Intution*
1. prefix: This variable stores the cumulative sum of elements from the start of the array up to the current index.

2. unordered_map mp: This map stores the prefix sums and their first occurrence indices. The key is the prefix sum, and the value is the index at which this sum first occurred.

    • Loop through the array:
        • Add the current element arr[i] to the prefix sum.
        • If prefix == k, the subarray from index 0 to i has a sum of k, so mxlen is updated to i + 1.
        • Check if the prefix - k has already occurred before using the map. If it has, then the sum of the subarray  
          between the previous occurrence of prefix - k and the current index i is equal to k, and the length of this subarray is i - mp[prefix - k]. Update mxlen if this length is larger.
        • If prefix is not in the map, store the current index i as the first occurrence of that prefix sum.

3. mxlen: This variable stores the length of the longest subarray found so far whose sum is equal to k.

Time Complexity:
O(n): The code only loops through the array once, and each operation inside the loop (like updating the map) takes constant time on average.
Space Complexity:
O(n): The space complexity is mainly due to the unordered_map mp, which can store up to n prefix sums.