# Problem: Get Min from Stack

# Code:

```c++
class Solution {
  public:
    Solution() {
        // code here
    }
    stack<int>stk2;
    stack<int>stk;
    // Add an element to the top of Stack
    void push(int x) {
        stk.push(x);
        if(stk2.empty() || stk2.top()>=x )
        stk2.push(x);
    }
    // Remove the top element from the Stack
    void pop() {
        if (stk.empty()) return;
        if (stk.top() == stk2.top()) {
            stk2.pop();
        }
        stk.pop();
    }
    // Returns top element of the Stack
    int peek() {
        // code here
        if(stk.empty()) return -1;
        return stk.top();
    }
    // Finds minimum element of Stack
    int getMin() {
        if(stk2.empty())  return -1;
        return stk2.top();
    }
};
```
This is an implementation of a **Min Stack**, which is a special stack that supports retrieving the **minimum element** in constant time **O(1)**, along with standard stack operations like `push`, `pop`, and `peek`.

---

## **Class Structure Explanation**
### **1. Data Members (Stacks Used)**
```cpp
stack<int> stk2;  // Min stack (stores the minimum values)
stack<int> stk;   // Main stack (stores all values)
```
- `stk`: Stores all elements normally (like a regular stack).  
- `stk2`: A special stack that always keeps track of the **minimum element** at any point.  

---

## **2. `push(int x)` → Insert an element**
```cpp
void push(int x) {
    stk.push(x);  // Push to the main stack
    if (stk2.empty() || stk2.top() >= x)  
        stk2.push(x);  // Push to min stack if it is empty or x is smaller
}
```
- Push the element `x` onto the main stack `stk`.  
- If `stk2` is empty **or** `x` is smaller than the current minimum (`stk2.top()`), **push it to `stk2`** as well.  
- This ensures that `stk2` **always stores the minimum element at the top**.

### **Example**
```cpp
push(5);
push(3);
push(7);
push(2);
push(6);
```
After these operations:
```
stk  = [5, 3, 7, 2, 6]  
stk2 = [5, 3, 2]  (Only stores the minimum elements)
```

---

## **3. `pop()` → Remove the top element**
```cpp
void pop() {
    if (stk.empty()) return;  // If stack is empty, do nothing

    if (stk.top() == stk2.top()) {  
        stk2.pop();  // If the top of both stacks match, pop from stk2
    }
    stk.pop();  // Pop from main stack
}
```
- First, check if the stack is empty.  
- If the top of `stk` **matches** the top of `stk2`, pop it from `stk2` (because the minimum is being removed).  
- Finally, pop from the main stack `stk`.

### **Example**
```
stk  = [5, 3, 7, 2, 6]  
stk2 = [5, 3, 2]
```
If we call `pop()`, `6` is removed from `stk`, but `stk2` remains unchanged.
If we call `pop()` again, `2` is removed from both stacks.

---

## **4. `peek()` → Get the top element**
```cpp
int peek() {
    if (stk.empty()) return -1;  // Return -1 if stack is empty
    return stk.top();  // Otherwise, return the top element
}
```
- If `stk` is empty, return `-1`.  
- Otherwise, return the top element of `stk`.

### **Example**
```
stk = [5, 3, 7, 2, 6]
peek() → returns 6
```

---

## **5. `getMin()` → Retrieve the minimum element**
```cpp
int getMin() {
    if (stk2.empty()) return -1;  // If min stack is empty, return -1
    return stk2.top();  // Otherwise, return the top of stk2
}
```
- If `stk2` is empty, return `-1`.  
- Otherwise, return the top element of `stk2`, which **stores the current minimum value**.

### **Example**
```
stk  = [5, 3, 7, 2, 6]
stk2 = [5, 3, 2]
getMin() → returns 2
```

---

## **Overall Complexity**
| Operation  | Time Complexity | Space Complexity |
|------------|---------------|----------------|
| `push(x)`  | **O(1)**       | **O(N)** (Extra stack for min values) |
| `pop()`    | **O(1)**       | **O(1)** |
| `peek()`   | **O(1)**       | **O(1)** |
| `getMin()` | **O(1)**       | **O(1)** |

