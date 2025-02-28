# Problem : Evaluation of Postfix Expression


# Code: 
```c++
class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int>stk;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == "+" || arr[i] == "-" || arr[i] == "/" || arr[i] == "*")
            {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                if(arr[i] == "+")
                {
                    int c = a+b;
                    stk.push(c);
                }
                else if(arr[i] == "-")
                {
                    int c = b-a;
                    stk.push(c);    
                }
                else if(arr[i] == "*")
                {
                    int c = a*b;
                    stk.push(c);
                }
                else
                {
                    int c = b/a;
                    stk.push(c);
                }
            }
            else
            {
                int t = stoi(arr[i]);
                stk.push(t);
            }
        }
        return stk.top();
    }
};
```

This program evaluates a mathematical expression written in **Reverse Polish Notation (Postfix Notation)** using a stack. Let's break it down step by step.

---

### **Understanding the Code**
1. **Stack Usage**  
   - The program uses a stack `stk` to store numbers while processing the expression.

2. **Loop Through the Expression**  
   - The expression is given as a **vector of strings** (`arr`).
   - The program **loops through each element** in the vector.

3. **Processing Each Element**  
   - **If the element is a number** → Convert it to an integer using `stoi()` and push it onto the stack.
   - **If the element is an operator (`+`, `-`, `*`, `/`)**:
     - Pop the **top two numbers** from the stack (`a` and `b`).
     - Perform the corresponding **operation** (`b op a`).
     - Push the **result** back into the stack.

4. **Final Answer**  
   - After processing the whole expression, the final result is on the top of the stack.

---

### **Example **
#### **Input:**  
```cpp
vector<string> arr = {"2", "1", "+", "3", "*"};
```
This represents the expression:  
 **(2 + 1) * 3** in Postfix notation.

#### **Execution Steps:**
| Step | Stack | Operation |
|------|-------|-----------|
| `"2"`  | `[2]` | Push 2 |
| `"1"`  | `[2, 1]` | Push 1 |
| `"+"`  | `[3]` | 2 + 1 = 3, push 3 |
| `"3"`  | `[3, 3]` | Push 3 |
| `"*"`  | `[9]` | 3 * 3 = 9, push 9 |

**Final Stack:** `[9]`  
**Output:** `9`

---

### **Key Points**
 Uses **stack** to handle numbers and operators.  
 **Follows Postfix notation rules** (operator comes **after** operands).  
 `b-a` and `b/a` maintain correct operand order (since stack is **LIFO**).  
 `stoi()` converts string numbers to integers.