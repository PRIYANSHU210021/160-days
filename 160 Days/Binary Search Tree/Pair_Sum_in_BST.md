# CODE #

```c++
class Solution {
  public:
  
  int  solve(Node* node, int t, unordered_map<int,int>&mp,bool &flag)
  {
        if(node==NULL)
            return 0;
        
      if ( solve(node->left,t,mp,flag)==1)return 1;
        if(mp.find(t-node->data)!=mp.end())
        {flag=1;return 1;}
        mp[node->data]++;
       return solve(node->right,t,mp,flag);
            
  }
  
    bool findTarget(Node *root, int target) {
        bool flag = 0;
        unordered_map<int,int>mp;
        int y=solve(root,target,mp,flag);
        return flag;
    }
};
```

## **🔍Logic**
1. **Recursive Function `solve()`**  
   - The function traverses the BST **in-order (left → node → right)** and stores values in an **unordered_map (`mp`)**.
   - For each node, it checks if **(target - current node’s value) is already in the map**.
   - If found, that means we have a pair that sums up to `target`, so `flag` is set to `1` and returns immediately.

2. **Checking the Condition (`mp.find(t - node->data) != mp.end()`)**  
   - If `t - node->data` exists in the map, it means we have already seen a node whose value, when added to the current node, gives `target`.
   - In this case, we set `flag = 1` and return `1`.

3. **Updating the Map (`mp[node->data]++`)**  
   - If no pair is found yet, **store the current node’s value in the map** and move to the right subtree.

4. **Main Function `findTarget()`**
   - Calls `solve(root, target, mp, flag)`.
   - If `flag == 1`, it means a valid pair exists in the tree, so return `true`.
   - Otherwise, return `false`.

---

## **💡 Example Walkthrough**
### **Input BST:**
```
      5
     / \
    3   7
   / \   \
  2   4   8
```
### **Target: `9`**
### **Step-by-step Execution**
| Node Processed | Check `target - node->data` in `mp` | Store `node->data` in `mp` | Found Pair? |
|---------------|--------------------------------|------------------------|------------|
| 2             | `9 - 2 = 7` (Not found)       | `{2}`                  | ❌ No      |
| 3             | `9 - 3 = 6` (Not found)       | `{2, 3}`               | ❌ No      |
| 4             | `9 - 4 = 5` (Not found)       | `{2, 3, 4}`            | ❌ No      |
| 5             | `9 - 5 = 4` ✅ Found!        | `{2, 3, 4, 5}`         | ✅ Yes    |

Since we found `4` in the map when processing `5`, we return `true`.

---

## **⏳ Time Complexity Analysis**
- Since we are doing an **in-order traversal** of the BST, it takes **O(N)** time.
- Searching in an **unordered_map** takes **O(1)** on average, so overall time complexity is **O(N)**.

---

