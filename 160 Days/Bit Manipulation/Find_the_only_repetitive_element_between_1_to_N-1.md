# Problem:  Findthe only repetitive element between 1 to N-1

# Approch 1: Maths Concept
```c++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        long long sum = 0, n=arr.size();
        for(auto x:arr)
        sum += x;
        return sum-(n-1)*(n)/2;
    }
};
```
### Intution:

- The array has numbers from `1 to n-1`, but one number is repeated.
- **Expected sum** of `1 to n-1` is:  
  \[
  \frac{(n - 1) \times n}{2}
  \]
- **Actual sum** will be more because of the duplicate.
- Subtract to get the duplicate:  
  \[
  \text{Duplicate} = \text{Actual Sum} - \text{Expected Sum}
  \]

---

###  Example:
`arr = [1, 3, 4, 2, 2]`  
Actual sum = 12, Expected = 10  
Answer = `12 - 10 = 2` ✅

# Approch 2: Bit Manipulation Concept
```c++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int n=arr.size(),xor1=0;
        for(int i=0; i<n; i++)
        xor1 = xor1^arr[i];
               
        if((n-1)%4 == 0)
            return xor1^(n-1);
        else if((n-1)%4 == 1)
            return xor1^1;
        else if((n-1)%4 == 2)
            return xor1^n;
        else
            return xor1^0; 
    }
};
```

Perfect! Let's go with just explanation first, then we’ll do one example at the end.

---

###  Intution:

1. **we start with XORing all the elements in the array.**  
   - This includes every number from 1 to N−1 **once**, and one of them **twice** (since it's duplicated).
   - XOR naturally cancels out duplicates (`a ^ a = 0`), so if all numbers occurred once, they'd cancel out completely.
   - But because one number appears twice, it won't fully cancel and will be left behind.

2. **Next, we XOR with all the numbers from 1 to N−1.**  
   - This gives we a clean way to cancel out the correct original numbers, leaving behind just the duplicated one.
   - Instead of using a loop to XOR from 1 to N−1, we use a **smart math trick** that finds XOR of a range using `(n-1) % 4`.
   - This shortcut is based on the known XOR pattern of numbers from 1 to K.

3. **Final XOR operation:**  
   - we XOR the result of step 1 with the result of step 2.
   - All numbers cancel out, and **only the duplicate remains**.

---

###  Final Result:
The number that appears **twice** in the array.

---

###  Example

Let's take:
```
arr = [1, 3, 4, 2, 2]
```

- Length of array = 5 → numbers should be from `1 to 4`
- One number (`2`) is repeated

wer logic:
- Step 1: XOR all array elements → ends up being 6
- Step 2: XOR of numbers from 1 to 4 (using the shortcut) → 4
- Final XOR → `6 ^ 4 = 2`

**Answer: 2 **
