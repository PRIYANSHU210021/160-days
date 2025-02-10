Problem: K Sum Paths

*code*

```c++
class Solution {
  public:
  void solve(unordered_map<int,int>&mp,Node*node,int &cnt, int k,int sum)
  {
      if(node==NULL) 
      return;
      sum += node->data;
      if(sum == k)
      cnt++;
      if(mp.find(sum-k)!=mp.end())
      cnt += mp[sum-k];
      mp[sum]++;
      solve(mp,node->left,cnt,k,sum);
      solve(mp,node->right,cnt,k,sum);
      mp[sum]--;
  }
    int sumK(Node *root, int k) {
        int cnt=0,sum=0;
        unordered_map<int,int>mp;
        solve(mp,root,cnt,k,sum);
        return cnt;
    }
};
```


*Approch*

## **Understanding the Problem Statement**
You have a **binary tree**, and you need to find **the number of paths** where the **sum of node values along the path equals `k`**.  
- The **path can start from any node** and must **go downward** (i.e., from parent to child).
- The **path does not need to end at a leaf**.
- **A node can only be used once per path**.

---

## **Code Explanation**

### **🔹 `sumK(Node *root, int k)` (Main Function)**
- This function initializes:
  - `cnt = 0` → **Counts the valid paths**.
  - `sum = 0` → **Tracks the current path sum**.
  - `unordered_map<int,int> mp` → **Stores prefix sums**.
- It calls `solve(mp, root, cnt, k, sum)` to perform a **DFS traversal** and find valid paths.

---

### **🔹 `solve(mp, node, cnt, k, sum)` (Recursive DFS Traversal)**
This function **traverses the tree** and checks for paths that sum to `k`.

#### **📌 Steps Inside `solve()`**
1️⃣ **Base Case: If the node is `NULL`, return.**  
   ```cpp
   if(node == NULL) return;
   ```
   - This stops recursion when reaching a leaf node.

2️⃣ **Add `node->data` to the sum (Path Sum Calculation).**
   ```cpp
   sum += node->data;
   ```
   - This keeps track of the **current sum from the root to this node**.

3️⃣ **Check if `sum == k`** → Direct match found.  
   ```cpp
   if(sum == k) cnt++;
   ```
   - If the sum from the **root to the current node** is `k`, we found a valid path.

4️⃣ **Check for previous prefix sum (`sum - k`).**
   ```cpp
   if(mp.find(sum - k) != mp.end())
      cnt += mp[sum - k];
   ```
   - This checks **if there exists a subarray (path segment) whose sum is `k`**.
   - **Logic:**  
     - If `sum - k` exists in the map, it means **removing this sum from the current sum gives `k`**.
     - **All occurrences of `sum - k` in `mp` represent valid paths ending at `node`**.

5️⃣ **Store the current prefix sum in `mp`.**
   ```cpp
   mp[sum]++;
   ```
   - This keeps track of how many times `sum` has been seen.

6️⃣ **Recursive Calls (DFS Traversal).**
   ```cpp
   solve(mp, node->left, cnt, k, sum);
   solve(mp, node->right, cnt, k, sum);
   ```
   - **Traverse left and right subtrees** to check for valid paths.

7️⃣ **Backtrack: Remove the current sum from `mp`.**
   ```cpp
   mp[sum]--;
   ```
   - **After processing a node, we backtrack and remove its sum from the map**.
   - This ensures that the **prefix sum only belongs to the current path**.

---

## **📌 Example Walkthrough**
Consider the **Binary Tree**:

```
        1
       / \
      2   3
     /   / \
    1   -1  2
```

**Target Sum `k = 3`**  
We need to count paths where the sum equals `3`.

### **DFS Traversal & Prefix Sum Logic**
#### ✅ **From root (1)**
- `sum = 1`
- Go left (`2`): `sum = 1 + 2 = 3` **✅ Path Found**
- Go left (`1`): `sum = 3 + 1 = 4`
- Backtrack

#### ✅ **From root (1), go right (`3`)**
- `sum = 1 + 3 = 4`
- Go left (`-1`): `sum = 4 + (-1) = 3` **✅ Path Found**
- Go right (`2`): `sum = 4 + 2 = 6`
- Backtrack

### **Total Paths Found = 3** 🎯

---

## **🔹 Complexity Analysis**
- **Each node is visited once** → `O(N)`, where `N` is the number of nodes.
- **Unordered map operations (insert/find) are `O(1)` average-case**.
- **Total complexity: `O(N)`** (Efficient!)

---

## **🔹 Key Point**
✅ Uses **DFS + Prefix Sum Technique**  
✅ **Efficient `O(N)` solution using `unordered_map`**  
✅ Works for **any path** (not just root-to-leaf)  
✅ Uses **backtracking to remove extra sums**  

---
