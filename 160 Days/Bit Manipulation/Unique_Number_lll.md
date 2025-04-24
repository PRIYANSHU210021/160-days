# Problem: Unique Number lll
# Code:
```c++
class Solution {
  public:
    int getSingle(vector<int> &arr) {
      int ans = 0;
      
      for(int i=0; i<32; i++){
      int cnt =0; 
          for(auto x:arr)
              if (x & (1 << i)) cnt++;
              
          if(cnt%3 != 0)
          ans =ans | (1<<i);
      }
      return ans;
    }
};

```

1. **Loop through 32 bits** (since integers are 32-bit).
2. For each bit position `i`, **count how many numbers** in the array have the `i-th` bit set.
3. If the count of set bits at position `i` is **not divisible by 3**, it means the unique number has that bit set.
4. Use `ans |= (1 << i)` to **set that bit** in the answer.
5. Return the final answer — it's the number that appears only once.