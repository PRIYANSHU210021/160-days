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
# Explain:
So, we have a row of houses, and each house has some money. But there's a **condition**:  
 **We can’t loot two consecutive houses**, otherwise, we’ll get caught.  

Now, we need to **maximize the total money** we can steal.  

### **How we are thinking?**
At every house, we have **two choices**:  
1. **Loot the current house** → But then we must **skip the next house** and move to `i+2`.  
2. **Skip the current house** → Move to `i+1` and check further.  

Now, our task is to **find the best option** at every house.

---

### **Breaking Down the Code**
We wrote a recursive function **`getMax(arr, i, dp)`**, which tells us **how much maximum money we can loot starting from house `i`**.

```cpp
int getMax(vector<int>& arr, int i, vector<int>& dp) {
    if (arr.size() <= i) return 0; 

    if (dp[i] != -1) return dp[i];  

    int pick = arr[i] + getMax(arr, i + 2, dp); 
    int nonpick = getMax(arr, i + 1, dp); 

    return dp[i] = max(pick, nonpick);  
}
```
 **If we pick the house**, we add its money and move to `i+2` (because we can’t loot the next house).  
 **If we skip the house**, we move to `i+1` and check the best we can get from there.  
 **We store the result in `dp[i]`** so that we don’t calculate it again (memoization).  

---

### **Main Function**
```cpp
int findMaxSum(vector<int>& arr) {
    vector<int> dp(arr.size() + 2, -1);  // Create a DP array and initialize with -1
    return getMax(arr, 0, dp);  // Start from the first house
}
```
 We create a `dp` array to store answers for each house.  
 We start looting from **house 0** and call `getMax(arr, 0, dp)`.  

---

### **Example Walkthrough**
#### **Input:**  
```cpp
arr = [6, 7, 1, 30, 8, 2, 4]
```
#### **How the function works step-by-step**
```
getMax(0) → Start from first house
    pick = 6 + getMax(2)  → Take house 0, skip house 1
    nonpick = getMax(1)   → Skip house 0, check house 1

getMax(1) → Start from second house
    pick = 7 + getMax(3)  → Take house 1, skip house 2
    nonpick = getMax(2)   → Skip house 1, check house 2

getMax(2) → Start from third house
    pick = 1 + getMax(4)  → Take house 2, skip house 3
    nonpick = getMax(3)   → Skip house 2, check house 3
```
This continues until the base case is reached.  
 **We store already calculated values in `dp[i]`**, so that we don’t repeat work.

#### **Final Output:** `41`  
(The maximum money we can loot from these houses.)

---

### **Why This Works?**
 **We explore all possibilities (recursive calls).**  
 **Memoization ensures we don’t calculate the same thing multiple times.**  
 **We always take the best possible loot at every step.**  
