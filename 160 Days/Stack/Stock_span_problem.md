# Problem: Stock span problem

# Code

```c++
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int>mark;
        stack<pair<int,int>>stk;
        for(int i=0; i<arr.size(); i++)
        {
            if(stk.empty())
            mark.push_back(-1);
            else if(!stk.empty() && stk.top().first>arr[i])
            {
                // stk.push({arr[i],i});
                mark.push_back(stk.top().second);
            }
            else if(!stk.empty() && stk.top().first<=arr[i])
            {
                while(!stk.empty() && stk.top().first<=arr[i])
                {
                    stk.pop();
                }
                if(!stk.empty())
                mark.push_back(stk.top().second);
                else
                mark.push_back(-1);
            }
        stk.push({arr[i],i});
        }
        vector<int>res;
        for(int i=0 ;i<arr.size() ;i++)
        {
            res.push_back(i-mark[i]);
        }
        return res;
    }
};
```


---
### **Step-by-Step Explanation:**
1. **Using a stack to keep track of previous greater elements**  
   - The stack stores pairs **(stock price, index)**.
   - This helps find how many consecutive days before the current day had stock prices **less than or equal to the current price**.

2. **Iterating through the stock prices**  
   - For each stock price `arr[i]`, you check how many consecutive previous prices were smaller.

3. **Finding the nearest greater price to the left**  
   - If the stack is empty, push `-1` (no greater element).
   - If the top of the stack has a greater price, store its index.
   - If the top of the stack has a **smaller or equal** price, pop the stack until you find a greater price.
   - If no greater price is found, push `-1`.

4. **Computing the span**  
   - The span for the current day is calculated as:  
     \[
     \text{span}[i] = i - \text{index of nearest greater price}
     \]
   - If no greater price exists, it means all previous prices were smaller, so the span is `i + 1`.

---

### **Time Complexity Analysis:**
- Each element is pushed and popped **at most once** from the stack.
- Hence, the overall complexity is **O(N)** (efficient).

---

### **Example :**
#### **Input:**  
`arr = [100, 80, 60, 70, 60, 75, 85]`  

#### **Step-by-Step Execution:**  

| Day (i) | Price (arr[i]) | Stack (Price, Index) | Nearest Greater Index | Span (i - nearest greater) |
|---------|--------------|-------------------|-------------------|----------------------|
| 0       | 100          | (100,0)           | -1                | 1                    |
| 1       | 80           | (100,0), (80,1)   | 0                 | 1                    |
| 2       | 60           | (100,0), (80,1), (60,2) | 1                 | 1                    |
| 3       | 70           | (100,0), (80,1), (70,3) | 1                 | 2                    |
| 4       | 60           | (100,0), (80,1), (70,3), (60,4) | 3                 | 1                    |
| 5       | 75           | (100,0), (80,1), (75,5) | 1                 | 4                    |
| 6       | 85           | (100,0), (85,6)   | 0                 | 6                    |

#### **Final Output:**  
`[1, 1, 1, 2, 1, 4, 6]`

---
