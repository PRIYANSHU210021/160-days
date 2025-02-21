# Problem: Parenthesis Checker

# Code:

```c++
class Solution {
  public:
    bool isBalanced(string& s) {
       stack<int>stk;
       
       int n = s.size();
       for(int i=0; i<n; i++)
       {
           if(s[i]=='[' || s[i]=='{' || s[i]=='(')
           stk.push(s[i]);
           else
           {
               if(stk.empty())
               return false;
               char c = stk.top();
               if(c=='(' && s[i]==')')
               stk.pop();
               else if(c=='{' && s[i]=='}')
               stk.pop();
               else if(c=='[' && s[i]==']')
               stk.pop();
               else
               return false;
           }
       }
     return stk.empty();
    }
};
```


---

### **Understanding the Code**
#### **1. Stack for Tracking Opening Brackets**
The function uses a **stack** (`stk`) to keep track of unmatched opening brackets.

#### **2. Iterating Through the String**
- If the current character is an **opening bracket** (`'('`, `'{'`, `'['`), it gets **pushed** onto the stack.
- If the current character is a **closing bracket** (`')'`, `'}'`, `']'`):
  - If the stack is **empty**, return `false` (there's no matching opening bracket).
  - Check the **top element** of the stack:
    - If it forms a valid pair (`()` / `{}` / `[]`), pop the top of the stack.
    - Otherwise, return `false` (mismatched bracket).

#### **3. Final Check**
After processing all characters, if the stack is empty, return `true` (all brackets were matched). Otherwise, return `false`.

---

#### **Example 1: Valid Input**
```cpp
string s = "{[()]}";
```
Stack operations:
| Step | Character | Stack | Action |
|------|----------|-------|--------|
| 1    | `{`      | `{`   | Push `{` |
| 2    | `[`      | `{[`  | Push `[` |
| 3    | `(`      | `{[(` | Push `(` |
| 4    | `)`      | `{[`  | `(` matches `)`, so Pop |
| 5    | `]`      | `{`   | `[` matches `]`, so Pop |
| 6    | `}`      | ` `   | `{` matches `}`, so Pop |

Stack is **empty**, so return `true`.

---

#### **Example 2: Invalid Input**
```cpp
string s = "{[(])}";
```
Stack operations:
| Step | Character | Stack | Action |
|------|----------|-------|--------|
| 1    | `{`      | `{`   | Push `{` |
| 2    | `[`      | `{[`  | Push `[` |
| 3    | `(`      | `{[(` | Push `(` |
| 4    | `]`      | `{[(` | **Mismatch!** Expected `)`, but got `]` → Return `false` |

The function returns **`false`**, as brackets are mismatched.

---

### **Time & Space Complexity**
- **Time Complexity:** **O(n)** (Each character is processed once)
- **Space Complexity:** **O(n)** (Stack stores at most `n` elements in the worst case)
