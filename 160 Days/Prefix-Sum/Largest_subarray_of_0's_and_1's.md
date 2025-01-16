Problem: Largest_subarray_of_0's_and_1's

*Approach same as yesterday*  (Longest_Subarray_with_Sum_K)

Key Differences
1. Problem Context
    Today's Code:
        • Targets finding the largest subarray with equal numbers of 0s and 1s.
        • Converts 0s to -1s to treat the problem as finding the longest subarray with a sum of 0.
    Yesterday's Code:
        • Targets finding the longest subarray with a given sum K.
        • Works directly with the given array and finds subarrays with the specified sum.

2. Array Modification
    Today's Code:
        •Converts all 0s to -1s before processing to represent the problem as a sum of 0 for equal 0s and 1s.
        •This transformation is critical to solve the problem.
    Yesterday's Code:
        •Does not modify the array. It works directly with the input values, as the problem doesn't require this        
         transformation.

```c++
int maxLen(vector<int> &arr) {
       int n = arr.size();
       unordered_map<int,int>mp;
       
       for(int i=0; i<n; i++)
       if(arr[i] == 0) arr[i] = -1;
       int sum = 0,mxlen = 0;
       for(int i=0; i<n; i++)
       {
           sum += arr[i];
           if(sum == 0) mxlen = max(mxlen,i+1);
           if(mp.find(sum)!=mp.end())
           {
               mxlen = max(mxlen , i-mp[sum]);
           }
           if(mp.find(sum)==mp.end())
           mp[sum]=i;
       }
       return mxlen;
    }
```

*Loop Understanding*
1. Update the Cumulative Sum
    • At each iteration, add the current element (arr[i]) to a cumulative sum (sum).
    • Since 0 was converted to -1, a cumulative sum of 0 indicates equal numbers of 1s and 0s.
2. Check for Subarray Starting from Index 0
    • If sum == 0, it means the subarray from index 0 to the current index i has a balanced count of 1s and 0s.
    • Update the maximum length (mxlen) to i + 1.
3. Look for the Current Sum in the Hash Map
    • If the cumulative sum (sum) was seen before in the hash map:
        • It indicates a subarray exists between the previous index + 1 and the current index i with a sum of 0.
        • Calculate this subarray’s length and update mxlen if it’s longer than the current maximum.
4. Store the First Occurrence of the Sum
    • If the cumulative sum (sum) is not in the hash map, store it along with the current index (i).
    • This ensures that the earliest occurrence of a sum is used for future subarray length calculations.
5. Repeat for All Indices
    • The loop continues for all elements of the array, ensuring every possible subarray is checked for balance.
    • At the end of the loop, mxlen contains the length of the largest subarray with equal numbers of 1s and 0s.