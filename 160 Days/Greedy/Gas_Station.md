# Problem : Gas Station

# Code: Brute

```c++


class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
      int n = gas.size();
      
      for(int i=0; i<n; i++)
      {
          if(gas[i] < cost[i])
          continue;
          
          int j = (i+1)%n;
          
          int costForMoving = cost[i];
          int earnGas = gas[j];
          
          int currGas = gas[i] - costForMoving + earnGas;
          
          while(i!=j)
          {
            if(currGas < cost[j])
            break;
            
            int costForMovingFromj = cost[j];
            j = (j+1)%n;
            
            int earnGasForj = gas[j];
            
            currGas = currGas - costForMovingFromj + earnGasForj;
          }
          if(i==j)
          return i;
      }
      return -1;
      
    }
};


// But it Gives TLE so move for optimal 
```



# Code: Optimal
```c++
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        
        int totalGas=0, totalCost=0, total = 0, index = 0;
        
        for(int i=0; i<n; i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            
            total = total + gas[i] - cost[i];
            if(total < 0)
            {
                total = 0;
                index = i+1; 
            }
        }
        
        // Greddy Intutive without this line above logic is weird😁 
        if(totalGas < totalCost) 
        return -1;
        else 
        return index;
        
    }
};
```


This problem is based on the **Gas Station** problem, where we need to determine if there is a starting gas station from which we can complete a circular journey.

---

1. **Understanding the Requirement:**  
   - We have `n` gas stations.
   - At each station `i`, we get `gas[i]` amount of fuel.
   - To travel to the next station `(i+1)`, we need `cost[i]` amount of fuel.
   - We need to check if there exists a **starting station** from where we can **complete the full circle**.

2. **Observations:**  
   - If the **total gas available (`totalGas`)** is **less than the total cost (`totalCost`)**, completing the journey is impossible.  
     **(Greedy check: If totalGas < totalCost, return `-1` immediately)**
   - If **totalGas ≥ totalCost**, then there must be at least one valid starting point.

---

### **Greedy Approach:**
- We initialize `total = 0` to track the current gas balance.
- We traverse through each station:
  - Add the gas at the station.
  - Subtract the cost required to move to the next station.
  - If at any point `total` becomes **negative**, it means we **cannot start from any station before or at this index**.
  - Hence, we reset `total = 0` and assume the **next station (`i+1`) is a potential starting point**.

### **Why does this greedy approach work?**
- If a valid solution exists, then the journey must be possible from at least one station.
- If we fail at station `i`, it means no station before `i` could be the answer.
- Resetting `total = 0` and setting `index = i+1` ensures we only consider **a new potential start**.

---

### **Example Walkthrough**
**Example:**  
```cpp
gas  = [1, 2, 3, 4, 5]  
cost = [3, 4, 5, 1, 2]  
```

| Station | Gas | Cost | Total Gas-Cost | Cumulative Total | Start Index |
|---------|-----|------|---------------|-----------------|-------------|
| 0       | 1   | 3    | -2            | -2              | 1 (reset)   |
| 1       | 2   | 4    | -2            | -2              | 2 (reset)   |
| 2       | 3   | 5    | -2            | -2              | 3 (reset)   |
| 3       | 4   | 1    | +3            | 3               | 3           |
| 4       | 5   | 2    | +3            | 6               | 3           |

- We fail at stations `0`, `1`, and `2`, so we reset.
- We succeed from station `3`, completing the full circle.

**Output:** `3`

---

### **Time Complexity:**
- We traverse the list **only once** → **O(n)**
- Space Complexity: **O(1)** (no extra space used)

This is an **optimal greedy solution**. 