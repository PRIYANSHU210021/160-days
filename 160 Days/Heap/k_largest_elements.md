## Problem:  k largest elements


# Code
```c++
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0; i<k; i++)
            pq.push(arr[i]);
            
        for(int i=k; i<arr.size(); i++)
        {
            if(pq.top()<arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        vector<int>res(k);
        int i=1;
      while(!pq.empty())
      {
          res[k-i] = pq.top();
          i++;
          pq.pop();
      }
      return res;
    }
};

```

 approach efficiently finds the **k largest elements** in an **unsorted array** using a **Min-Heap** (`priority_queue<int, vector<int>, greater<int>>`).

---

## **Understanding Approach**
1. **Use a Min-Heap (priority queue) of size `k`**  
   - A **Min-Heap** ensures that the **smallest element among the `k` largest elements** is always at the top.

2. **Insert the first `k` elements** into the Min-Heap.
   - This initializes the heap with `k` elements.
   - The smallest among them remains at the top.

3. **Iterate through the remaining elements (`k` to `n-1`)**:
   - If the current element (`arr[i]`) is **greater** than the smallest element (`pq.top()`),  
     - **Remove (`pop()`) the smallest element** (pq's top).
     - **Insert (`push()`) the current element**, ensuring the heap always contains `k` largest elements.

4. **Extract elements from the Min-Heap into a result vector (`res`)**:
   - Since `priority_queue` does not return elements in sorted order,  
     - We **store elements in reverse order** in the result vector (`res[k-i]`).
     - This ensures that the result is in **descending order**.

---

## **Time & Space Complexity**
### **Time Complexity:**
- **Building the Min-Heap** for `k` elements: **O(k log k)**
- **Processing the remaining (`n-k`) elements**: **O((n-k) log k)**  
  - Each `pop()` and `push()` operation takes **O(log k)**.
- **Extracting `k` elements from the heap**: **O(k log k)**
  
🔹 **Total Complexity: O(n log k)**  
(Efficient compared to sorting the array, which would take **O(n log n)**).

---

### **Space Complexity:**
- **Min-Heap (priority_queue)** stores `k` elements → **O(k)**.
- **Result vector** stores `k` elements → **O(k)**.
  
🔹 **Total Space Complexity: O(k)**.

---

## **Example Walkthrough**
### **Input:**
```cpp
arr = {7, 10, 4, 3, 20, 15};
k = 3;
```
### **Step-by-Step Execution**
#### **Step 1: Insert first `k=3` elements into the Min-Heap**
```
Heap: [4, 7, 10]  (Min-Heap, smallest element at top)
```
#### **Step 2: Process remaining elements (`20`, `15`)**
- **Current element = `20`**
  - `pq.top()` (smallest in heap) = `4`
  - Since `20 > 4`, replace `4` with `20`
  ```
  Heap: [7, 10, 20]
  ```
- **Current element = `15`**
  - `pq.top()` = `7`
  - Since `15 > 7`, replace `7` with `15`
  ```
  Heap: [10, 15, 20]
  ```

#### **Step 3: Extract elements from Min-Heap into `res[]`**
```
res[2] = 20
res[1] = 15
res[0] = 10
```
#### **Final Output:**
```cpp
res = {10, 15, 20}
```

---

## **Summary**
✅ **Efficient Approach**: Uses **Min-Heap** to maintain `k` largest elements.  
✅ **Time Complexity:** **O(n log k)** (better than sorting `O(n log n)`).  
✅ **Space Complexity:** **O(k)** (only storing `k` elements).  
✅ **Returns `k` largest elements in descending order**.  

---

### **Alternative Approach (Using Sorting)**
If you sort the array and take the last `k` elements:
```cpp
vector<int> kLargest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end(), greater<int>());
    return vector<int>(arr.begin(), arr.begin() + k);
}
```
- **Time Complexity:** **O(n log n)** (due to sorting)
- **Space Complexity:** **O(1)** (modifies the input array)

 **heap-based approach (O(n log k))** is **better for large `n` and small `k`**. 

