Problem: Trapping Rain Water


*Intution*: 
The intuition is that the water trapped above a block depends on the shorter of the tallest blocks on its left and right. Using two pointers, we dynamically track the left and right maximum heights (lmx and rmx). By comparing the heights at the pointers, we calculate the water trapped at each step and move inward from the side with the shorter height, ensuring an efficient and space-optimized solution.

Initially, I solved the problem using a space-heavy approach by precomputing left_max and right_max arrays, which stored the maximum heights to the left and right of each block. While simple, this required O(n) extra space.
Later, I optimized it using a dynamic two-pointer approach. Instead of extra arrays, I used two variables, lmx and rmx, to track the maximum heights dynamically. This reduced the space complexity to O(1) while keeping the time complexity at O(n).

TC: O(N)
SC: O(1)

*Code*: 
```c++
int maxWater(vector<int> &arr) {
        int n = arr.size();
        int start = 0,end = n-1;
        int lmx=0,rmx=0,ans = 0;
        while(start<end)
        {
            lmx = max(lmx,arr[start]);
            rmx = max(rmx,arr[end]);
            
            if(arr[start]<=arr[end])
                ans += (lmx-arr[start]),
                start++;
            else
                ans += (rmx-arr[end]),
                end--;
        }
        return ans;
    }
```




*Approach*:
1. Two Pointers:
    • Use two pointers: start (left) and end (right).
    • Maintain two variables:
        • lmx (left maximum): The tallest block encountered so far from the left.
        • rmx (right maximum): The tallest block encountered so far from the right.

2. Water Calculation:
    • Compare the heights at the start and end pointers:
        • If the block at start is shorter (arr[start]≤arr[end]):
            • Update lmx to be the maximum of lmx and arr[start].
            • Add lmx−arr[start] to the total water (because water depends on the shorter side).
            • Move the start pointer to the right.
        Otherwise:
            • Update rmx to be the maximum of rmx and arr[end].
            • Add rmx−arr[end] to the total water.
            • Move the end pointer to the left.

3. Stop Condition:
    • Stop when start crosses end.


Why It Works:
    • The height of water trapped above a block depends on the shorter of the tallest blocks on the left and right.
    • By comparing the heights at start and end, we dynamically decide which side's boundary to use for calculating water.
    • This prevents the need to precompute arrays for left_max and right_max.
