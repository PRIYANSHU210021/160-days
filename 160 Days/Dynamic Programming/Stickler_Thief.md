# Problem: Stickler Thief


# Code:
```c++
    class Solution {
  public:
    int getMax(vector<int>&arr,int i, vector<int>&dp){
      
      if(arr.size()<=i)
      return 0;
      
      if(dp[i]!=-1)
      return dp[i];
      
      int pick = arr[i] + getMax(arr,i+2,dp);
      int nonpick = getMax(arr,i+1,dp);
      
      return dp[i] = max(pick,nonpick);
    }
    int findMaxSum(vector<int>& arr) {
        vector<int>dp(arr.size()+2 , -1);
        return getMax(arr,0,dp);
    }
};
```

---

### **Understanding **
You are trying to find the maximum amount the thief can loot under the constraint that **he cannot rob two consecutive houses**.

1. **Recursive Function (`getMax`)**
   - You define `getMax(arr, i, dp)`, which returns the maximum money that can be looted starting from index `i`.
   - If `i` exceeds the array size, return `0` (base case).
   - If the result is already computed (`dp[i] != -1`), return `dp[i]` (memoization step).
   - There are two choices for the thief:
     - **Pick the current house** → Add `arr[i]` and jump to `i+2` (since adjacent houses can't be robbed).
     - **Skip the current house** → Move to `i+1` without adding `arr[i]`.
   - Store the maximum of both choices in `dp[i]` and return it.

2. **Main Function (`findMaxSum`)**
   - Creates a `dp` array initialized with `-1` for memoization.
   - Calls `getMax(arr, 0, dp)` to start recursion from the **first house**.

---

### **Example Walkthrough**
#### **Input:**
```cpp
arr = [6, 7, 1, 30, 8, 2, 4]
```
#### **Dry Run of Recursion**
```
getMax(arr, 0)
    pick = arr[0] + getMax(arr, 2)  -> 6 + ?
    nonpick = getMax(arr, 1)        -> ?

getMax(arr, 1)
    pick = arr[1] + getMax(arr, 3)  -> 7 + ?
    nonpick = getMax(arr, 2)        -> ?

getMax(arr, 2)
    pick = arr[2] + getMax(arr, 4)  -> 1 + ?
    nonpick = getMax(arr, 3)        -> ?

getMax(arr, 3)
    pick = arr[3] + getMax(arr, 5)  -> 30 + ?
    nonpick = getMax(arr, 4)        -> ?
```
- The recursion continues until the base case is reached.
- Memoization helps avoid recomputation.

#### **Final Output:** `41` (Maximum money the thief can loot)

---

- **Time Complexity:** \(O(N)\)
- **Space Complexity:** \(O(N)\) (Can be optimized to \(O(1)\))
