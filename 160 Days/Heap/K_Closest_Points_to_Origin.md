# Problem : K Closest Points to Origin
# CODE
```c++
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, 
        vector<int>>>, greater<pair<int, vector<int>>>> pq;
        
        for(auto x:points)
        {
            int p1 = x[0];
            int p2 = x[1];
            int d = p1*p1+p2*p2;
            // pq.push({d,{p1,p2}});
            pq.push({d,x});
        }
        
        vector<vector<int>> res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
```


### **Explanation of Your Code**
.

```cpp
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
```
- You define a class `Solution` with a function `kClosest` that takes:
  - A **2D vector `points`**, where each point is represented as `[x, y]`.
  - An integer `k`, which specifies how many closest points to return.

---

### **Step 1: Creating a Min-Heap**
```cpp
        priority_queue<pair<int, vector<int>>, vector<pair<int, 
        vector<int>>>, greater<pair<int, vector<int>>>> pq;
```
- This **priority queue (min-heap)** stores pairs:
  - The **first value** in the pair is the **square of the Euclidean distance** from `(0,0)`, calculated as `x² + y²`.
  - The **second value** is the actual point `[x, y]`.
- `greater<pair<int, vector<int>>>` ensures that the **smallest distance** is at the top (min-heap).

---

### **Step 2: Pushing Points into the Min-Heap**
```cpp
        for(auto x:points)
        {
            int p1 = x[0];
            int p2 = x[1];
            int d = p1*p1+p2*p2;
            pq.push({d, x});
        }
```
- You **iterate** through all points.
- For each point `[x, y]`:
  - Calculate the squared **Euclidean distance**:
    \[
    d = x^2 + y^2
    \]
  - Push `{distance, point}` into the **min-heap**.

---

### **Step 3: Extracting the k Closest Points**
```cpp
        vector<vector<int>> res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
```
- You **extract the top `k` elements** from the min-heap:
  - `pq.top().second` gives the **point `[x, y]`** with the smallest distance.
  - `pq.pop()` removes the point from the heap.
  - Store the point in the `res` vector.

---

### **Step 4: Returning the Result**
```cpp
        return res;
    }
};
```
- The function returns the `k` closest points.

---

### **Example Walkthrough**
#### **Input:**
```cpp
points = {{1,3}, {-2,2}, {5,8}, {0,1}}
k = 2
```
#### **Step 1: Computing Squared Distances**
| Point  | Distance (d = x² + y²) |
|--------|------------------------|
| (1,3)  | **1² + 3² = 10** |
| (-2,2) | **(-2)² + 2² = 8** |
| (5,8)  | **5² + 8² = 89** |
| (0,1)  | **0² + 1² = 1** |

#### **Step 2: Min-Heap After Insertion**
```
Min-Heap (Sorted by Distance)
---------------------------------
(1,  [0,1])
(8,  [-2,2])
(10, [1,3])
(89, [5,8])
```

#### **Step 3: Extracting k Closest Points**
- **Extract `pq.top()` (smallest distance) → `[0,1]`**
- **Extract `pq.top()` (next smallest) → `[-2,2]`**

#### **Final Output:**
```cpp
res = {{0,1}, {-2,2}}
```


