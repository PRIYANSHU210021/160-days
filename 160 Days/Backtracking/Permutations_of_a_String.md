Problem: Permutations_of_a_String

TC:O(N*N!)
SC:O(N)

*code*
```c++
void solve(string &s, unordered_set<string>&v, int idx)
  {
      if(idx>=s.size())
      {
        v.insert(s);
        return;
      }
      
      for(int i=idx; i<s.size(); i++)
      {
        swap(s[i],s[idx]);
        solve(s,v,idx+1);
        swap(s[i],s[idx]);
      }
      
  }
    vector<string> findPermutation(string &s) {
       vector<string>st;
       unordered_set<string>ans;
       int idx = 0;
       solve(s,ans,idx);
       for(auto x:ans)
           st.push_back(x);
       return st;
    }
};

```

*Approach*
Designed to find all unique permutations of a string using backtracking, and you are using an **unordered set** (`unordered_set<string>`) to ensure that only unique permutations are stored. Here's a detailed explanation of your approach:

---

### **1. Recursive `solve` Function**
The `solve` function is the core of your backtracking solution. Here's how it works:

#### **Base Case**
```cpp
if(idx >= s.size()) {
    v.insert(s); // Add the current permutation to the set
    return;
}
```
- When the current index `idx` becomes greater than or equal to the size of the string, it indicates that you have generated one valid permutation.
- This permutation is added to the `unordered_set<string> v`, ensuring no duplicates are stored.

#### **Recursive Case**
```cpp
for(int i = idx; i < s.size(); i++) {
    swap(s[i], s[idx]);       // Swap the character at `i` with the character at `idx`
    solve(s, v, idx + 1);     // Recur for the next index
    swap(s[i], s[idx]);       // Backtrack to restore the string
}
```
- A loop runs from the current index `idx` to the end of the string.
- For each iteration:
  1. **Swap** the characters at positions `i` and `idx`.
  2. **Recur** to generate permutations for the remaining substring starting at `idx + 1`.
  3. **Backtrack** by swapping the characters back to restore the original string.

---

### **2. `findPermutation` Function**
This function prepares and processes the permutations using the `solve` function.

1. **Data Structures**:
   - `unordered_set<string> ans`: Used to store unique permutations.  
   - `vector<string> st`: The final result vector, which will contain all unique permutations.

2. **Steps**:
   - Call the `solve` function with the initial string `s`, the `unordered_set`, and `idx = 0`.
   - Convert the `unordered_set` to a `vector` to produce the final result.

---

### **Your Approach:**
1. **Backtracking**:
   - Uses recursion to swap characters and generate all possible permutations.
   - Includes a backtracking step to restore the string after each recursive call.

2. **Unique Handling**:
   - Stores permutations in an `unordered_set` to ensure only unique permutations are recorded.
   - After all recursive calls, the `unordered_set` is converted to a `vector` for the final result.

3. **Efficiency**:
   - Using an `unordered_set` makes it easier to handle duplicates but adds some overhead due to hashing. If the input string has many repeated characters, this is an efficient way to ensure uniqueness.

---

### **Example Walkthrough**
#### Input: `s = "aab"`

1. **Initial Call**:
   - `solve("aab", ans, 0)`

2. **Recursive Tree**:
   ```
   "aab" -> "aab" -> "aab"
                  -> "aba"
        -> "aba" -> "aba"
                  -> "aab"
   "baa" -> "baa"
          -> "baa"
   ```

   - Valid permutations stored in `ans`: `{"aab", "aba", "baa"}`.

3. **Final Conversion**:
   - Convert `unordered_set` to `vector`: `["aab", "aba", "baa"]`.

---

### **Complexity Analysis**
#### Time Complexity:
- **Permutation Generation**:
  - For a string of length \(n\), there are \(n!\) permutations in the worst case (all unique).
  - Generating each permutation takes \(O(n)\) for swapping.

  **Total**: \(O(n \cdot n!)\).

- **Set Insertion**:
  - Each insertion into an `unordered_set` takes \(O(1)\) on average.

#### Space Complexity:
- **Recursive Stack**:
  - The depth of the recursion is \(O(n)\).

- **Set Storage**:
  - The `unordered_set` stores up to \(n!\) permutations.

**Overall Space Complexity**: \(O(n \cdot n!)\).

---

### **Key Points About Your Approach**
- **Strengths**:
  - Efficiently handles duplicate characters using an `unordered_set`.
  - Backtracking ensures all permutations are generated.

- **Potential Optimizations**:
  - Instead of using an `unordered_set`, you could sort the string and use a condition to skip duplicate swaps, avoiding the overhead of the set.
