Problem: Indexes_of_Subarray_Sum
*Intution*:
The problem requires finding a continuous subarray with a sum equal to a target. Using the sliding window technique, we maintain a dynamic window defined by two pointers (start and end). If the current sum is less than the target, expand the window by moving end and adding the element. If the sum exceeds the target, shrink the window by moving start and subtracting the element. This process continues until the sum matches the target or the array is exhausted. The approach efficiently narrows down the subarray without recalculating sums repeatedly.


TC: O(N)
SC: O(1)

```c++
vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int start = 0,end=0,sum =0;
        while(start<=end)
        {
            if(sum == target)
            return {start+1,end};
            else if(sum < target && end<n)
            {
                sum += arr[end];
                end++;
            }
            else
            {
                sum = sum - arr[start];
                start++;
                if(start>n-1)
                return {-1};
            }
        }
        return {-1};
    }
    ```


*Approach*:
1. Initialize Variables:
    • start and end both point to the beginning of the array.
    • sum = 0 to keep track of the current window's sum.

2. Iterate Until Subarray is Found or End of Array is Reached:
    Case 1: If sum == target:
        The current window's sum equals the target. Return {start + 1, end} (1-based indices).
    Case 2: If sum < target:
        Add the current arr[end] to the sum and move end forward to expand the window.
    Case 3: If sum > target:
        Subtract arr[start] from the sum and move start forward to shrink the window.

3. Handle Edge Cases:
    • If end reaches the end of the array and no matching subarray is found, return {-1}.
    • If start > n - 1 while shrinking, return {-1}.


