# Problem: Stickler Thief
### **You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.Determine the maximum amount the thief can steal.   •••   Note: Since the houses are in a circle, the first and last houses are also considered adjacent.**

# Code: 
```c++
  class Solution {
  public:
    int getMax(vector<int>&arr,int i,int n, vector<int>&dp){
      
      if(n<=i)
      return 0;
      
      if(dp[i]!=-1)
      return dp[i];
      
      int pick = arr[i] + getMax(arr,i+2,n,dp);
      int nonpick = getMax(arr,i+1,n,dp);
      
      return dp[i] = max(pick,nonpick);
    }
    int maxValue(vector<int>& arr) {
        vector<int>dp1(arr.size()+2 , -1);
        vector<int>dp2(arr.size()+2 , -1);
        
        return max(getMax(arr,0,arr.size()-1,dp1),getMax(arr,1,arr.size(),dp2));
    }
};

```

---
# Explain (Similar to the Previous Day):
### **🧠 Intuition Behind the Solution**
Let's think about the problem **step by step** before jumping into the code.  

---

## ** Step 1: Understanding the Constraint (Why is it different from a normal House Robber problem?)**
In a **normal House Robber** problem (without a circular arrangement), we simply **skip adjacent houses** and find the maximum possible sum.  

**But here, the first and last houses are also adjacent!**  
- This means if we rob the **first house**, we **cannot rob the last house**.  
- If we rob the **last house**, we **cannot rob the first house**.  

### **So what do we do?**  
We solve the problem **twice**:
1. **Case 1**: Ignore the **last house** and find the maximum sum.
2. **Case 2**: Ignore the **first house** and find the maximum sum.

---

## ** Step 2: Breaking the Problem into Subproblems**
At any house `i`, we have **two choices**:  
1. **Rob this house**  → But skip the next house (move to `i+2`).
2. **Skip this house**  → Move to the next house (`i+1`).

To **avoid redundant calculations**, we use **Memoization** (`dp` array).  

---

## ** Step 3: Why Do We Solve it Twice?**
Since houses are **circular**, we **cannot** rob both `arr[0]` and `arr[n-1]`.  
So, we solve it for **two cases** separately:  
- **Case 1**: Rob from **house 0 to n-2** (excluding the last house).
- **Case 2**: Rob from **house 1 to n-1** (excluding the first house).  
- **Final Answer** = **Maximum of both cases**.

---
