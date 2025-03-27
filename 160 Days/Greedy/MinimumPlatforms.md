# Problem: Minimum Platforms
# Link : https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

**Think of a situation where:One train arrives, and another hasn’t departed yet ...**

# Code:
```c++
class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
      int a = arr.size();
      int d = dep.size();
      sort(arr.begin(), arr.end());
      sort(dep.begin(), dep.end());
      
    int maxx = 0;
    int cnt=0;
    int i=0,j=0;
    while(i<a)
    {
        if(arr[i]<=dep[j])
        {
            cnt++;
            i++;
        }
        else if(arr[i]>dep[j])
        {
            cnt--;
            j++;
        }
        maxx = max(maxx, cnt);
    }
        return maxx;
    }
};
```


### 🪜 **Step-by-Step Logic**:

1. **Sort** the arrival and departure arrays.
   - So we can process the trains in time order.

2. Use **two pointers**:
   - `i` for the next **arrival**
   - `j` for the next **departure**

3. Use a counter `cnt`:
   - It keeps track of **how many platforms are currently needed**.
   - If a train **arrives** before the previous one **departs**, `cnt++` (you need one more platform).
   - If a train **departs** before the next one **arrives**, `cnt--` (a platform gets free).

4. Keep updating a variable `maxx`:
   - This stores the **maximum platforms** needed at any moment — which is your final answer.

---




