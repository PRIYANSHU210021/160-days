# Problem : Alien Dictionary
# Code:
```c++
class Solution {
  public:
    string findOrder(vector<string> &words) {
       vector<int> adj[26];
       vector<int> inDeg(26, 0);
       vector<int> isPresent(26, 0);
       int n = words.size();
       for(int i = 0; i < n; i++) {
           for(char c : words[i]) {
               isPresent[c-'a'] = 1;
           }
       }
       for(int i = 0; i < n - 1; i++) {
           string str1 = words[i], str2 = words[i + 1];
           int j = 0, k = 0;
           while(j<str1.size() && k < str2.size() && str1[j] == str2[k]) {
               j++; k++;
           }
           if(k == str2.size() && j < str1.size()) return "";
           if(j < str1.size() && k < str2.size()) {
               adj[str1[j] - 'a'].push_back(str2[k] - 'a');
               inDeg[str2[k] - 'a']++;
           }
       }
       queue<int> q;
       for(int i = 0; i < 26; i++) {
           if(isPresent[i] == 1 && inDeg[i] == 0) {
               q.push(i);
           }
       }
       string ans = "";
       while(!q.empty()) {
           int node = q.front();
           q.pop();
           ans += (char)(node + 'a');

           for(auto x : adj[node]) {
               inDeg[x]--;
               if(inDeg[x] == 0) q.push(x);
           }
       }
       int cnt = 0;
       for(int i = 0; i < 26; i++) {
           if(isPresent[i]) cnt++;
       }
       if(ans.size() != cnt) return "";
       return ans;
    }
};
```

***The problem is to determine the correct order of characters in an alien language, given a sorted dictionary of words from that language. Since the words are sorted, we can infer character precedence by comparing adjacent words. The code constructs a directed graph where each node is a character, and an edge from a → b means character a comes before b. Then, it performs a topological sort (using BFS) to find a valid linear ordering of characters. If a cycle is detected or the input is invalid (e.g., a prefix issue), it returns an empty string.***
---

###  **Intuition**

---

####  1. **Track Present Characters**
```cpp
for(char c : words[i]) {
    isPresent[c - 'a'] = 1;
}
```
- Mark all characters that appear in any word.

---

####  2. **Build Adjacency List (Graph)**
```cpp
adj[str1[j] - 'a'].push_back(str2[k] - 'a');
inDeg[str2[k] - 'a']++;
```
- For every pair of adjacent words, compare characters.
- First non-matching character defines order:  
  e.g., if `c1 != c2`, then `c1 → c2`.

---

####  3. **Invalid Prefix Case**
```cpp
if(k == str2.size() && j < str1.size()) return "";
```
- If word2 is a prefix of word1 and comes after it, it's invalid → return `""`.

---

####  4. **Topological Sort using BFS**
```cpp
if(inDeg[i] == 0) q.push(i);
```
- Start with characters having **in-degree 0** (no dependencies).

---

####  5. **Build Result String**
```cpp
ans += (char)(node + 'a');
```
- Add characters to result as they get resolved (in-degree becomes 0).

---

####  6. **Cycle Detection**
```cpp
if(ans.size() != cnt) return "";
```
- If not all present characters are in the result → **cycle exists** → return `""`.

---

###  Summary:
- **Graph + Topological Sort**.
- Detects invalid input and cycles.
- Efficiently handles multiple characters and alien dictionary order.

---
