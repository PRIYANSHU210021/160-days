# Problem: Next Greater Element

# Code: 
```c++
 vector<int> nextLargerElement(vector<int>& arr) {
        stack<int>stk;
        int n = arr.size();
        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && stk.top()<=arr[i])
            stk.pop();
            
            int k = arr[i];
            if(stk.empty())
            arr[i]=-1;
            else
            {
                arr[i] = stk.top();
            }
            stk.push(k);
        }
        return arr;
    }
```
### **Explanation**

1. **Process elements from right to left**  
   - You start from the last element because for each element, the next greater element (NGE) lies **to its right**.  

2. **Use a stack to keep track of potential next greater elements**  
   - Since you're moving from right to left, the stack stores elements in a way that helps you quickly find the next greater element.  

3. **Remove useless elements from the stack**  
   - If the top of the stack is **smaller than or equal** to the current element, it **cannot** be the NGE, so you remove it.  

4. **Check the stack for the next greater element**  
   - If the stack is empty, it means **no greater element exists**, so store `-1`.  
   - Otherwise, the **top of the stack** is the **NGE** for the current element.  

5. **Push the current element to the stack**  
   - This ensures that it will be available to help find the NGE for the next elements to its left.  


---

### **Example **
#### **Input:**
```cpp
arr = [4, 5, 2, 10, 8]
```
#### **Step-by-Step Execution:**
| `i` | `arr[i]` | Stack Before | Stack After Processing | `arr[i]` After Update |
|----|------|--------------|------------------|------------------|
| 4  | 8    | []           | [8]              | -1               |
| 3  | 10   | [8]          | [10]             | -1               |
| 2  | 2    | [10]         | [10, 2]          | 10               |
| 1  | 5    | [10, 2]      | [10, 5]          | 10               |
| 0  | 4    | [10, 5]      | [10, 5, 4]       | 5                |

#### **Final Output:**
```cpp
[5, 10, 10, -1, -1]
```

### **Time Complexity Analysis**
- Each element is **pushed and popped** from the stack at most **once** → **O(N)**.
- The total time complexity is **O(N)** (efficient solution).
