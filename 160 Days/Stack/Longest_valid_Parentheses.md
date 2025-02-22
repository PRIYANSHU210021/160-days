# Problem: Longest valid Parentheses

# Code:

```c++
class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<int>stk;
        int n= s.size();
        int i=0;
        while(n--)
        {
            if(s[i] == '[' || s[i]=='{' || s[i]=='(')
            {
                stk.push(s[i]);
            }
            else
            {
                if(s[i]==']' || s[i]=='}' || s[i]==')')
                stk.pop();
            }
            i++;
        }
        if(stk.size()) return false;
        return true;
    }
};

```
---

### **Step-by-Step Explanation of Your Approach:**
1. **Initialize Variables:**
   - `stack<int> stk;` → To store **indices** of unmatched `(`.
   - `int cnt = 0;` → Stores the **maximum length** of a valid substring.
   - `int index = -1;` → Stores the **last unmatched `)` index**.

2. **Iterate Over the String:**
   - If `s[i] == '('`, push its index onto the stack.
   - If `s[i] == ')'`, check the stack:
     - **If the stack is not empty (`(` exists for pairing)**:
       - Pop the last `(` from the stack.
       - If the stack is **still not empty**, calculate the valid substring as:  
         ```cpp
         cnt = max(cnt, i - stk.top());
         ```
         (Difference between the current `)` and the last unmatched `(`).
       - If the stack is **empty after popping**, calculate the valid substring as:  
         ```cpp
         cnt = max(cnt, i - index);
         ```
         (Difference between the current `)` and the last unmatched `)` stored in `index`).
     - **If the stack is empty (no matching `(`)**:
       - Update `index = i;` to mark the last unmatched `)`.

3. **Return the Maximum Length of Valid Parentheses Substring (`cnt`).**

---

### **Key Idea Behind Your Approach:**
- The **stack stores indices** of unmatched `(`.
- The **`index` variable tracks** the last unmatched `)`, which acts as a reset point.
- **Whenever a `)` is found**, it tries to form a valid substring using the top index from the stack.

---

### **Example :**
#### **Input:** `"()(()))"`

| Index | Char | Stack (`stk`) | `index` | Calculation (`cnt`) |
|--------|------|-------------|---------|--------------------|
| 0      | `(`  | `[0]`       | `-1`     | -                  |
| 1      | `)`  | `[]` (pop)  | `-1`     | `cnt = max(0, 1 - (-1)) = 2` |
| 2      | `(`  | `[2]`       | `-1`     | -                  |
| 3      | `(`  | `[2,3]`     | `-1`     | -                  |
| 4      | `)`  | `[2]` (pop) | `-1`     | `cnt = max(2, 4 - 2) = 2` |
| 5      | `)`  | `[]` (pop)  | `-1`     | `cnt = max(2, 5 - (-1)) = 6` |

**Final Output:** `6` (Substring `"()(()))"`)

---

### **Complexity Analysis:**
- **Time Complexity:** `O(n)` (we traverse the string once)
- **Space Complexity:** `O(n)` (worst case: storing all `(` indices)

