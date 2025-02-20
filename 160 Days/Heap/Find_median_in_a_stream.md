# Problem : Find median in a stream


# CODE:

```c++
class Solution {
  public:
  
        priority_queue<int,vector<int>,greater<int>>right_min;
        priority_queue<int>left_max;
        void solve(int &x)
        {
            if(left_max.empty() || x < left_max.top())
            {
                left_max.push(x);
            }
            else
            {
                right_min.push(x);
            }
            
             if(left_max.size() > right_min.size()+1)
            {
                right_min.push(left_max.top());
                left_max.pop();
            }
            else if(left_max.size()<right_min.size())
            {
                left_max.push(right_min.top());
                right_min.pop();
            }
        }
        vector<double> getMedian(vector<int> &arr) {
        vector<double>res;
        for(int i=0; i<arr.size(); i++ )
        {
            solve(arr[i]);
            if(left_max.size()==right_min.size())
                res.push_back((left_max.top()+right_min.top())/2.0);
            else
            res.push_back(left_max.top());
        }
        
        return res;
    }
};
```

---

### **Concept Behind the Approach**
To efficiently find the median in a stream of numbers, we use:
1. **Max Heap (`left_max`)** → Stores the smaller half of the numbers.
2. **Min Heap (`right_min`)** → Stores the larger half of the numbers.

These two heaps help us maintain a balanced partition of numbers, ensuring that:
- If the total number of elements is **even**, the median is the **average** of the top elements of both heaps.
- If the total number of elements is **odd**, the median is simply the **top element of the max heap (`left_max`)**.

---

### **Code Breakdown**
```cpp
class Solution {
  public:
        priority_queue<int,vector<int>,greater<int>>right_min; // Min heap for the right half
        priority_queue<int>left_max; // Max heap for the left half
```
- `right_min`: A **min heap** storing the larger half of the numbers.
- `left_max`: A **max heap** storing the smaller half of the numbers.

---
### **Function: `solve(int &x)`**
This function **inserts a number into one of the heaps** while ensuring balance.

```cpp
void solve(int &x) {
    if (left_max.empty() || x < left_max.top()) {
        left_max.push(x);
    } else {
        right_min.push(x);
    }
```
- If `left_max` is **empty** or `x` is **less than the top of `left_max`**, push it into `left_max`.
- Otherwise, push `x` into `right_min`.

```cpp
if (left_max.size() > right_min.size() + 1) {
    right_min.push(left_max.top());
    left_max.pop();
}
else if (left_max.size() < right_min.size()) {
    left_max.push(right_min.top());
    right_min.pop();
}
```
- If `left_max` has more than **one extra element**, move the top element to `right_min` to maintain balance.
- If `right_min` has **more elements**, move the top element to `left_max`.

---

### **Function: `getMedian(vector<int> &arr)`**
This function processes each element and calculates the running median.

```cpp
vector<double> getMedian(vector<int> &arr) {
    vector<double> res;
    for (int i = 0; i < arr.size(); i++) {
        solve(arr[i]);
```
- Iterate through each number and insert it into the heaps using `solve()`.

```cpp
if (left_max.size() == right_min.size())
    res.push_back((left_max.top() + right_min.top()) / 2.0);
else
    res.push_back(left_max.top());
```
- If both heaps have **equal size**, the median is the **average** of their tops.
- Otherwise, the median is just the **top of `left_max`** (since it contains one extra element in the odd case).

```cpp
return res;
```
- Return the computed list of medians.

---

### **Example Execution**
#### **Input:**
```cpp
arr = [5, 15, 1, 3]
```
#### **Step-by-Step Processing:**
| Step | Number | left_max (Max Heap) | right_min (Min Heap) | Median |
|------|--------|-----------------|-----------------|--------|
| 1    | 5      | [5]             | []              | 5      |
| 2    | 15     | [5]             | [15]            | (5+15)/2 = 10.0 |
| 3    | 1      | [1, 5]          | [15]            | 5      |
| 4    | 3      | [3, 1]          | [5, 15]         | (3+5)/2 = 4.0 |

#### **Output:**
```cpp
[5, 10.0, 5, 4.0]
```

---

### **Time Complexity Analysis**
For each number:
- **Insertion into a heap** takes **O(log N)**.
- **Balancing the heaps** takes **O(log N)**.
- Since we process **N** numbers, the total complexity is **O(N log N)**.

---
