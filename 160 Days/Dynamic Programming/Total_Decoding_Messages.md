# Problem: Total Decoding Messages
```
A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.

Examples:

Input: digits = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).
```


# Code:
```c++
class Solution {
  public:
  
    int solve(string &s,int i, int n, vector<int>&dp){
        if(i==n)
        return 1;
        if(s[i]=='0')
        return 0;
        
        if(dp[i]!=-1)
        return dp[i];
        
        int onedigit = solve(s,i+1,n,dp);
        int twodigit = 0;
        
        if(i+1 < n)
        {
        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))
        twodigit = solve(s,i+2,n,dp);  
        }
        //71452782359335209241135238
        return dp[i] = onedigit+twodigit;
    }
    int countWays(string &digits) {
        int n = digits.size();
        vector<int>dp(n+1,-1);
        return solve(digits,0,n,dp);
    }
};
```


### **Understanding the Problem Intuitively**
You are given a string of numbers, and you need to find out how many ways it can be decoded into letters based on the given mapping:
- 'A' → 1, 'B' → 2, ..., 'Z' → 26.

#### **Example 1**
**Input:** `"12"`  
Possible decodings:
1. `"1 2"` → `"AB"`
2. `"12"` → `"L"`

So, there are **2 ways** to decode `"12"`.  

#### **Example 2**
**Input:** `"226"`  
Possible decodings:
1. `"2 2 6"` → `"BBF"`
2. `"22 6"` → `"VF"`
3. `"2 26"` → `"BZ"`

So, there are **3 ways** to decode `"226"`.

---

### **First Intuition: Breaking the Problem Down**
If you were solving this manually, how would you do it?  
You would start from the first number and:
1. Try to take **one digit** at a time.
2. If possible, also try to take **two digits** together.

Let's take `"226"` and analyze it.

- Start at `'2'`:  
  - Take **'2'** → Remaining `"26"`
  - Take **'22'** → Remaining `"6"`

- For `"26"`:
  - Take **'2'** → Remaining `"6"`
  - Take **'26'** → Nothing left (valid case)

- `"6"` is just one way (`"F"`).


---

### **Building the Recursion**
For **each position** in the string, you have two choices:
1. Decode **one digit** → Move to the next character.
2. Decode **two digits** (if valid) → Move two steps forward.

That's why we write a recursive function `solve(i)`, which:
- **Base Case:** If `i == n`, we successfully reached the end → return `1`.
- **Invalid Case:** If a number starts with `'0'`, it is not valid → return `0`.
- **Recursive Case:**  
  - Decode one digit and recurse `solve(i+1)`.
  - Decode two digits (if valid) and recurse `solve(i+2)`.

---

### **Why Do We Need Memoization (DP)?**
Since the same subproblems get solved multiple times (e.g., `"6"` appears in different branches), we store results in `dp[]` to avoid redundant calculations. This makes the solution efficient.

---
