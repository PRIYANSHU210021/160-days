# Problem: Longest Increasing Subsequence

# Code:
```c++
class Solution {
    public:
      int lis(vector<int>& arr) {
          int n = arr.size();
          vector<int>count(n,1);
          int mini = INT_MAX;
          for(int i=0; i<n; i++)
          {
              int flag = 0;
              int max_prev_count = INT_MIN;
              for(int j=i; j>0; j--)
              {
                  if(arr[j-1]<arr[i])
                  {
                      max_prev_count = max(max_prev_count,count[j-1]);
                      flag =1;
                  }
              }
                  if(flag==1)
                  count[i] += max_prev_count;
          }
          int ans=0;
          for(int i=0; i<count.size(); i++)
          {
          ans  = max(ans,count[i]);
          }
          return ans;
      }
  };
```

### ** Thought Process**  
1. **Initialize `count[i] = 1`**  
   - Each element itself is at least a subsequence of length `1`.

2. **Iterate Through Each Element `i`**  
   - For each `arr[i]`, check all previous elements `arr[j-1]` to find **a smaller value**.
   - If `arr[j-1] < arr[i]`, `arr[j-1]` can be part of the LIS ending at `arr[i]`.

3. **Find Maximum LIS Before `i`**  
   - Maintain `max_prev_count` to track the longest LIS ending at some `j-1` that can extend to `arr[i]`.
   - If `arr[j-1] < arr[i]`, update `max_prev_count` with `max(max_prev_count, count[j-1])`.

4. **Update `count[i]`**  
   - If a valid `arr[j-1]` exists (`flag == 1`), update `count[i] = count[i] + max_prev_count`.

5. **Keep Track of Maximum LIS**  
   - Maintain `ans` to store the largest LIS found in `count[]`.

### **Key Observations in Your Code**
- **You use a flag (`flag`)** to check if at least one valid `arr[j-1]` exists.
- **You iterate in reverse order (`j = i; j > 0; j--`)** to find previous elements.
- **You maintain `max_prev_count`** to track the best LIS that `arr[i]` can extend.

 - **The outer loop runs O(N), and the inner loop runs O(N), so the total complexity is O(N²).**

- **But this can be improved using Binary Search + DP (O(N log N)).**