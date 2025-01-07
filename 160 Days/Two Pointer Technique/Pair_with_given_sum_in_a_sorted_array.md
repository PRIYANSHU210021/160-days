Problem: **Pair_with_given_sum_in_a_sorted_array**

*Intution*:
Here, **two-pointer technique** to count pairs in a sorted array whose sum equals the target. Starting with one pointer at the beginning (`start`) and the other at the end (`end`), it calculates the sum of the two elements. If the sum matches the target, it counts the pair and checks for duplicates near `start` to include all valid pairs. If the sum is too small, `start` moves right; if too large, `end` moves left. This approach is efficient, leveraging the sorted order to avoid unnecessary comparisons.

TC: O(N)
SC: O(1)

*Code*: 
```c++
int countPairs(vector<int> &arr, int target) {
        int cnt = 0,n=arr.size();
        int start=0,end=n-1;
        while(start<end)
        {
            int sum = arr[start]+arr[end];
            if(sum == target) 
            {
                cnt++;
                    int temp = start+1;
                    while(temp < end && arr[temp] == arr[temp-1])
                    {
                        cnt++;
                        temp++;
                    }
                    end--;
            }
            else if(sum<target) start++;
            else end--;
        }
        return cnt;
    }
```

*Approach*:

1. Initialize Variables:
    • cnt keeps track of the number of pairs found.
    • start starts from the beginning of the array, and end starts from the last element.

2. Iterate While start < end:
    • Calculate the sum of the elements at start and end.

3. Compare the sum with the target:
    If sum == target:
        • Increment cnt (found a valid pair).
        • Check for duplicates near start to count all pairs involving the same number.
        • Move the end pointer leftward to continue searching.
    If sum < target: Move start to the right to increase the sum.
    If sum > target: Move end to the left to decrease the sum.

4. Return cnt:

**Key Advantages** :
• Efficient: The two-pointer technique avoids a nested loop, making it faster with a time complexity of O(n).
• Handles Duplicates: By checking for duplicates near start or end, it ensures all valid pairs are counted.
