# Problem: Histogram_Rectangular_Area

# Code:

```c++
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int ans= 0;
        int n= arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>stk;
        
        for(int i=0; i<n; i++)
        {
            while(!stk.empty() && arr[stk.top()]>arr[i])
            {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            right[stk.top()] = n;
            stk.pop();
        }
        
        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && arr[stk.top()]>arr[i])
            {
                left[stk.top()]=i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty())
        {
            left[stk.top()] = -1;
            stk.pop();
        }
        for(int i=0; i<n; i++)
        ans = max(ans,arr[i]*(right[i]-left[i]-1));
        
        return ans;
    }
};
```



---

## **Approach**

1️⃣ **Find the Next Smaller Element on the Right**  
2️⃣ **Find the Next Smaller Element on the Left**  
3️⃣ **Calculate the Maximum Rectangle Area**  

---

## **Step-by-Step Explanation**

### **Step 1: Finding the Right Smaller Elements**
```cpp
for(int i=0; i<n; i++) {
    while(!stk.empty() && arr[stk.top()] > arr[i]) {
        right[stk.top()] = i;
        stk.pop();
    }
    stk.push(i);
}
while(!stk.empty()) {
    right[stk.top()] = n;
    stk.pop();
}
```
- This loop **finds the next smaller element on the right** for each histogram bar.  
- **Logic:**  
  - If the top of the stack has a height greater than `arr[i]`, it means `arr[i]` is the next smaller element for that bar.  
  - Store its index in `right[]` and pop the stack.  
  - Otherwise, push `i` into the stack.  
- If no smaller element is found, store `n` (out of bounds) in `right[]`.  

---

### **Step 2: Finding the Left Smaller Elements**
```cpp
for(int i=n-1; i>=0; i--) {
    while(!stk.empty() && arr[stk.top()] > arr[i]) {
        left[stk.top()] = i;
        stk.pop();
    }
    stk.push(i);
}
while(!stk.empty()) {
    left[stk.top()] = -1;
    stk.pop();
}
```
- This loop **finds the next smaller element on the left** for each bar.  
- **Logic:**  
  - If the top of the stack has a height greater than `arr[i]`, it means `arr[i]` is the previous smaller element for that bar.  
  - Store its index in `left[]` and pop the stack.  
  - Otherwise, push `i` into the stack.  
- If no smaller element is found, store `-1` in `left[]`.  

---

### **Step 3: Calculating the Maximum Area**
```cpp
for(int i=0; i<n; i++)
    ans = max(ans, arr[i] * (right[i] - left[i] - 1));
```
- This calculates the area for each histogram bar using the formula:  
  **`width = right[i] - left[i] - 1`**  
  **`area = height * width`**  
- The **maximum area is stored in `ans`**.  

---
### **Example**  
#### **Input:**  
```cpp
arr = [2, 1, 5, 6, 2, 3]
```

#### **Step 1: Finding the Right Smaller Elements (`right[]`)**  
- We traverse from **left to right** and find the **next smaller element** for each bar.  
- If no smaller element exists, we set it to `n` (out of bounds).  

| Index | Height (arr[i]) | Next Smaller on Right | right[i] |
|--------|-------|----------------------|---------|
| 0      | 2     | 1 (index 1)         | 1       |
| 1      | 1     | None                 | 6       |
| 2      | 5     | 2 (index 4)         | 4       |
| 3      | 6     | 2 (index 4)         | 4       |
| 4      | 2     | None                 | 6       |
| 5      | 3     | None                 | 6       |

Thus, `right[] = [1, 6, 4, 4, 6, 6]`

---

#### **Step 2: Finding the Left Smaller Elements (`left[]`)**  
- We traverse from **right to left** and find the **previous smaller element** for each bar.  
- If no smaller element exists, we set it to `-1` (out of bounds).  

| Index | Height (arr[i]) | Next Smaller on Left | left[i] |
|--------|-------|----------------------|---------|
| 0      | 2     | None                 | -1      |
| 1      | 1     | None                 | -1      |
| 2      | 5     | 1 (index 1)         | 1       |
| 3      | 6     | 5 (index 2)         | 2       |
| 4      | 2     | 1 (index 1)         | 1       |
| 5      | 3     | 2 (index 4)         | 4       |

Thus, `left[] = [-1, -1, 1, 2, 1, 4]`

---

#### **Step 3: Calculating Maximum Area**  
We use the formula:  
**`area = height * (right[i] - left[i] - 1)`**  

| Index | Height (arr[i]) | Width (`right[i] - left[i] - 1`) | Area |
|--------|-------|--------------------------|------|
| 0      | 2     | (1 - (-1) - 1) = 1       | 2    |
| 1      | 1     | (6 - (-1) - 1) = 6       | 6    |
| 2      | 5     | (4 - 1 - 1) = 2          | 10   |
| 3      | 6     | (4 - 2 - 1) = 1          | 6    |
| 4      | 2     | (6 - 1 - 1) = 4          | 8    |
| 5      | 3     | (6 - 4 - 1) = 1          | 3    |

 **Maximum area = 10** 

---

### **Final Output**
```cpp
10
``` 

### **Time Complexity**
- **O(N)** → Each element is pushed/popped from the stack at most once.  

### **Space Complexity**
- **O(N)** → Due to the `left[]`, `right[]`, and `stack`.  
