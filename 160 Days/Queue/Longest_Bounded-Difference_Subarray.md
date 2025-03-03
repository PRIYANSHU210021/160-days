# Problem: Longest Bounded-Difference Subarray

# Code:
```c++
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>> maxq;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minq;
        
        int i = 0, j = 0;
        int mxlen = 0;
        int start = 0;  
        while (j < n) {
            maxq.push({arr[j], j});
            minq.push({arr[j], j});
    
            while (maxq.top().first - minq.top().first > x) {
                i = min(maxq.top().second, minq.top().second) + 1;
                
                while (maxq.top().second < i) 
                maxq.pop();
                
                while (minq.top().second < i)
                minq.pop();
            }
            
            if (j - i + 1 > mxlen) {
                mxlen = j - i + 1;
                start = i;
            }
            j++;
        }
        vector<int> ans;
        for (int k = start; k < start + mxlen; k++) 
            ans.push_back(arr[k]);
        return ans;
    }
};
```

### **Intuition Behind the Code**
The goal of this code is to find the **longest contiguous subarray** in which the difference between the maximum and minimum element is at most `x`. This is done using **two priority queues (heaps)**:  
- **Max Heap (`maxq`)** → Keeps track of the largest element in the current window.  
- **Min Heap (`minq`)** → Keeps track of the smallest element in the current window.  

By maintaining these heaps, we can efficiently determine whether a subarray satisfies the condition `max - min ≤ x`.  

---

## **Step-by-Step Explanation**

### **1️⃣ Expanding the Window (`j` Expands the Range)**
- Start with two pointers:  
  - `i` → Represents the **start** of the valid subarray.  
  - `j` → Expands the **end** of the subarray.  
- Push each new element `arr[j]` into **both heaps**.  
- Now, `maxq.top().first` gives the **largest** element in the current window.  
- Similarly, `minq.top().first` gives the **smallest** element in the current window.

---

### **2️⃣ Shrinking the Window (If Condition is Violated)**
- If `max - min > x`, the window is **invalid**, and we need to shrink it by moving `i` forward.
- We update `i` to the minimum index of the elements stored in heaps (`i = min(maxq.top().second, minq.top().second) + 1`).
- Then, **remove outdated elements** from heaps:
  - Pop elements from `maxq` whose indices are **less than `i`**.
  - Pop elements from `minq` whose indices are **less than `i`**.

---

### **3️⃣ Tracking the Longest Valid Subarray**
- If the current window `j - i + 1` is longer than `mxlen`, update `mxlen` and store `start = i`.  
- Continue expanding `j` until the entire array is processed.

---

### **4️⃣ Extracting the Answer**
- The **longest valid subarray** starts at `start` and has a length of `mxlen`.  
- Extract and return the elements from `arr[start]` to `arr[start + mxlen - 1]`.

---

## **Complexity Analysis**
- **Each element** is pushed into and popped from the heap at most once → `O(n log n)`.
- The overall complexity is **O(n log n)** due to the heap operations.

---

## **Example **
### **Input**
```cpp
arr = {8, 4, 2, 6, 7}, x = 4
```

### **Execution Steps**
| `j` | `arr[j]` | `maxq` (max heap) | `minq` (min heap) | `i` | Window | `mxlen` | `start` |
|----|------|--------------------|--------------------|----|----------------|--------|---------|
| 0  | 8    | `{(8,0)}`         | `{(8,0)}`         | 0  | `{8}` ✅ | 1 | 0 |
| 1  | 4    | `{(8,0), (4,1)}`  | `{(4,1), (8,0)}`  | 0  | `{8,4}` ✅ | 2 | 0 |
| 2  | 2    | `{(8,0), (4,1), (2,2)}` | `{(2,2), (4,1), (8,0)}` | 1 | `{4,2}` ✅ | 2 | 1 |
| 3  | 6    | `{(8,0), (6,3), (4,1), (2,2)}` | `{(2,2), (4,1), (6,3), (8,0)}` | 1 | `{4,2,6}` ✅ | **3** | **1** |
| 4  | 7    | `{(8,0), (7,4), (6,3), (4,1), (2,2)}` | `{(2,2), (4,1), (6,3), (7,4), (8,0)}` | 2 | `{2,6,7}` ❌ | 3 | 1 |

### **Final Output**
```cpp
[4, 2, 6]
```
### But, This approach efficiently finds the longest valid subarray using heaps in O(n log n) time complexity. However, an even better approach exists using a deque (double-ended queue), which reduces the complexity to O(n).