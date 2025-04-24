# Problem: Unique Number II
# Code:

```c++
    class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
       int xor_all = 0;
       for(auto x:arr)
       {
           xor_all ^= x;
       }
       int cnt = xor_all & -xor_all;
        int p = 0, q=0;
       for(auto x: arr)
       {
           if(x & cnt)
           p = p^x;
           else
           q = q^x;
       }
       if(p<q)
       return {p,q};
       else
       return {q,p};
    }
};
```


###  Steps:

1. **XOR all elements** →  
   This cancels out all duplicate elements (since `a ^ a = 0`), and you're left with `xor_all = num1 ^ num2`.

2. **Find the rightmost set bit** →  
   `cnt = xor_all & -xor_all` gives you the lowest bit where `num1` and `num2` differ.

3. **Split the array into two groups**:
   - One group has the set bit at `cnt`.
   - One group doesn't.
   - These two groups **each contain one unique number**, rest are duplicates and cancel out.

4. **XOR within each group** →  
   This cancels out the duplicates and gives you the two unique numbers `p` and `q`.

5. **Return them in sorted order**.

---

###  Example:
Input: `[1, 2, 1, 3, 2, 5]`  
→ Output: `[3, 5]` (sorted)

---
