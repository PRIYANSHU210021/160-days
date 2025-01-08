Problem: **Count_the_number_of_possible_triangles**

*Intution*:
To solve the problem, first sort the array to make it easier to apply the triangle inequality condition. Then, for each
element in the array, consider it as the largest side of a potential triangle. Use two pointers, one starting from the
beginning (`start`) and the other just before the current largest side (`end`). Check if the sum of the two sides (`arr
[start] + arr[end]`) is greater than the largest side (`arr[idx]`). If it is, all pairs between `start` and `end` are
valid, so add `end - start` to the count. Move the `end` pointer left to explore smaller pairs. If the condition is
not met, move the `start` pointer right. Repeat this process for all possible largest sides and return the total count.

TC: O(N*N)
SC: O(1)

*Code*: 
```c++
int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int idx =  n-1;
        int ans = 0;
        int start = 0, end = n-2;
        while(idx>1)
        {
            while(start<end)
            {
                int sum = arr[start]+arr[end];
                if(sum>arr[idx] )
                {
                    ans += end-start;
                    end--;
                }
                else start++;
            }
            start=0;
            idx--;
            end = idx-1;
        }
        return ans;
    }
```

*Approach*:
1. (Generally) Sort the array: When the array is sorted, the largest number in a triplet will always appear at the end (or later index). This makes checking the triangle condition easier.

    • For arr[i], arr[j], arr[k] (where i < j < k):
        • If arr[i] + arr[j] > arr[k], then its guaranteed that arr[i] + arr[k] > arr[j] and 
        arr[j] + arr[k] > arr[i] (because of sorting).

2. Fix the largest side (arr[idx]):
    • Start with the largest side (arr[idx]) and use two pointers (start and end) to find valid pairs (arr[start] and 
    arr[end]) that satisfy:
        • arr[start] + arr[end] > arr[idx].

3. Count pairs:
    • If arr[start] + arr[end] > arr[idx], all pairs from 'start' to 'end' are valid (because increasing start will 
    only increase the sum, still satisfying the condition).

4. Move pointers:

    • If the pair is valid, decrease 'end' to explore smaller pairs. Otherwise, increase 'start' to increase the sum.

5. Repeat for all possible idx:
    • Move idx to the left to consider smaller largest sides.
