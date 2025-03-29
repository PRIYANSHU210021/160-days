# Problem : Job Sequencing Problem

# Code: 

```c++
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int,int>>p;
        int maxProfit = 0;
        int curr = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<n ;i++)
        {
            p.push_back({deadline[i],profit[i]});
        }
        sort(p.begin(),p.end());
        
        for(int i=0; i<n; i++)
        {
            if(p[i].first > curr)
            {
                maxProfit += p[i].second;
                curr++;
                pq.push(p[i].second);
            }
            else if(p[i].second > pq.top())
            {
                maxProfit -= pq.top();
                pq.pop();
                maxProfit += p[i].second;
                pq.push(p[i].second);
            }
        }
            int total = 0;
            int size = pq.size();
        while(!pq.empty())
        {
            total += pq.top();
            pq.pop();
        }
                
    
        return {size, total};
    }
};
```

### **Intuition Behind the Job Sequencing Algorithm**

The goal is to **schedule jobs** within their given deadlines in such a way that we **maximize the total profit**. However, we can only schedule **one job per unit of time**, so we need a strategy to select the most profitable jobs within the given constraints.

---

### **Step-by-Step Thought Process**

1. **Understanding the Deadline Constraint**  
   - Each job has a **deadline** (i.e., the last time slot in which it can be scheduled).
   - If a job has a deadline `d`, we can schedule it **anytime from 1 to d**, provided that no other job has already taken that slot.

2. **Sorting the Jobs for Efficient Selection**  
   - We first **sort** all the jobs in ascending order based on their **deadline**.
   - This helps us **process jobs in the order of when they need to be completed**, ensuring we do not miss earlier deadlines.

3. **Using a Min-Heap to Keep the Most Profitable Jobs**  
   - We use a **priority queue (min-heap)** to keep track of the jobs that we have scheduled.
   - This heap helps us maintain only the most profitable jobs.

4. **Greedy Job Selection**  
   - **If a job’s deadline is greater than the number of jobs scheduled so far**, we have a free slot. We add the job to our schedule and push its profit into the heap.
   - **If all slots are full** and the current job has a higher profit than the lowest-profit job in our schedule (the top of the min-heap), we remove the least profitable job and replace it with the current one.
   - This ensures that at any given time, we are always keeping the most profitable set of jobs.

5. **Final Result Calculation**  
   - The **size of the heap** gives the **total number of jobs scheduled**.
   - The **sum of profits in the heap** gives the **maximum profit possible**.

---

### **Example Walkthrough**
#### Given:  
```cpp
deadline = [2, 1, 2, 1, 3]
profit   = [100, 19, 27, 25, 15]
```
#### Step 1: Sorting Jobs by Deadline
```
(1, 19), (1, 25), (2, 27), (2, 100), (3, 15)
```
#### Step 2: Processing Jobs
1. **Job (1,19)** → Added to heap → Heap = [19]  
2. **Job (1,25)** → Replaces 19 (since 25 > 19) → Heap = [25]  
3. **Job (2,27)** → Added to heap → Heap = [25, 27]  
4. **Job (2,100)** → Replaces 25 (since 100 > 25) → Heap = [27, 100]  
5. **Job (3,15)** → Added to heap → Heap = [15, 27, 100]  

#### Final Output:
- **Jobs Scheduled = 3**
- **Total Profit = 15 + 27 + 100 = 142**

---
