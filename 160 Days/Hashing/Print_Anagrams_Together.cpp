Code: 


vector<vector<string>> anagrams(vector<string>& arr) {
        int n=arr.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0; i<n; i++)
        {
            string str = arr[i];
            sort(str.begin(),str.end());
            mp[str].push_back(arr[i]);
        }
        vector<vector<string>>v;
        for(auto x:mp)
            v.push_back(x.second);
        return v;
    }


    Intution (by chatgpt):

    ### Explanation of the Code:

This function groups words that are **anagrams** of each other. An anagram is a word formed by rearranging the letters of another word. For example, "listen" and "silent" are anagrams because they contain the same characters in a different order. Here's how the function works:

---

### **Function Overview**: 

#### **Input**:
- A vector of strings `arr` (e.g., `{"cat", "tac", "act", "dog", "god"}`).

#### **Output**:
- A vector of vectors of strings, where each inner vector contains all the anagrams grouped together.  
  For example:
  ```cpp
  Input: {"cat", "tac", "act", "dog", "god"}
  Output: {{"cat", "tac", "act"}, {"dog", "god"}}
  ```

---

### **Step-by-Step Explanation**:

#### 1. **Declare a Hash Map**:
```cpp
unordered_map<string,vector<string>>mp;
```
- The key of the map is a sorted version of the string. 
- The value is a vector of all strings that are anagrams of the key.

#### 2. **Iterate Through Each String**:
```cpp
for(int i=0; i<n; i++) {
    string str = arr[i];
    sort(str.begin(),str.end());
    mp[str].push_back(arr[i]);
}
```
- For each string in the input vector:
  - **Sort the string**: Rearrange its characters alphabetically (e.g., "cat" → "act").
  - Use the sorted string as a key in the hash map.
  - Push the original string into the corresponding value (a vector in the hash map).

#### Example:
- Input: `{"cat", "tac", "act", "dog", "god"}`
- After processing:
  ```cpp
  mp = {
      "act": {"cat", "tac", "act"},
      "dgo": {"dog", "god"}
  }
  ```

#### 3. **Extract Groups of Anagrams**:
```cpp
vector<vector<string>>v;
for(auto x: mp)
    v.push_back(x.second);
```
- Iterate through the hash map.
- Push each group (the `x.second` part of the map, which is a vector of strings) into the result vector `v`.

#### 4. **Return the Result**:
- Finally, return the vector of vectors containing the grouped anagrams.

---

### **How It Works**:
#### Example Input:
```cpp
arr = {"cat", "tac", "act", "dog", "god"}
```

#### Step-by-Step Execution:
1. Sort each string and add it to the hash map:
   - "cat" → "act": `mp["act"] = {"cat"}`
   - "tac" → "act": `mp["act"] = {"cat", "tac"}`
   - "act" → "act": `mp["act"] = {"cat", "tac", "act"}`
   - "dog" → "dgo": `mp["dgo"] = {"dog"}`
   - "god" → "dgo": `mp["dgo"] = {"dog", "god"}`

2. Hash map after processing:
   ```cpp
   mp = {
       "act": {"cat", "tac", "act"},
       "dgo": {"dog", "god"}
   }
   ```

3. Extract values from the map:
   ```cpp
   v = {{"cat", "tac", "act"}, {"dog", "god"}};
   ```

4. Return the result:
   ```cpp
   return v;
   ```

---

### **Time Complexity**:
1. **Sorting Each String**: \(O(N \cdot K \log K)\), where \(N\) is the number of strings and \(K\) is the average length of a string.
2. **Inserting into Hash Map**: \(O(N \cdot K)\).
3. **Extracting Results**: \(O(N)\).

**Overall**: \(O(N \cdot K \log K)\).

---

### **Space Complexity**:
- **Hash Map Storage**: \(O(N \cdot K)\), for storing all strings and their sorted keys.
- **Result Vector**: \(O(N \cdot K)\).

---

This is an efficient solution to group anagrams using hashing and sorting!

