# Problem: Missing in Array
# Code: 
```c++
class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xor1=0, xor2=0;
        for(int i=0; i<n; i++)
        xor1 = xor1^arr[i];
        
        n = n+1;
        if(n%4==0)
         return xor1^n;
        else if(n%4==1)
         return xor1^1;
        else if(n%4==2)
         return xor1^(n+1);
        else
            return  
            xor1;
    }
};
```

---

###  Idea of XOR Trick

XOR has useful properties:
- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is **commutative and associative**

So, if you XOR all numbers from `1` to `n`, and then XOR all elements in the array, the missing number will be left after cancellation.

---

### Logic Breakdown:

1. `xor1` = XOR of all elements in the array  
2. `xor2` = XOR of all numbers from `1` to `n`

But instead of looping for `1 to n`, the code uses a shortcut:
```cpp
if(n % 4 == 0) xor2 = n
if(n % 4 == 1) xor2 = 1
if(n % 4 == 2) xor2 = n + 1
if(n % 4 == 3) xor2 = 0
```
This is based on the pattern of XOR from `1` to `n`.

---

###  Final Step:
Return `xor1 ^ xor2` → gives the missing number.

---
