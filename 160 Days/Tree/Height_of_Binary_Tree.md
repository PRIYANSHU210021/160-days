Problem: Height of Binary Tree

*code*

```c++
class Solution {
  public:
    int solve(Node* root)
    {
        if(root==NULL)     
        {
            return 0;
        }
        
        return(1+max(solve(root->left),solve(root->right)));
    }
    
    int height(Node* node) {
       return solve(node)-1;
    }
};
```
*Approach*
This C++ code is used to find the **height** of a binary tree. Let's break it down step by step in simple words:

### **Understanding the Code**
1. **Class Definition:**  
   The class `Solution` contains two functions:  
   - `solve(Node* root)`: A helper function that calculates the depth of the tree.
   - `height(Node* node)`: A function that returns the height of the tree.

2. **Function `solve(Node* root)` (Recursive function to calculate depth)**
   - If the given `root` is `NULL` (meaning no node exists), return `0`.
   - Otherwise, recursively find the maximum depth of the **left** and **right** subtrees.
   - Add `1` (for the current node) and return the maximum depth.

3. **Function `height(Node* node)`**
   - Calls the `solve(node)` function, which returns the depth.
   - Subtracts `1` because height is counted as the number of edges, while depth includes the root node.

### **Example Walkthrough**
Consider this binary tree:
```
        1
       / \
      2   3
     /
    4
```
- The height of the tree is **2** (edges from root `1` to deepest leaf `4`).
- `solve(root)` will return `3` (because it counts nodes: `1 -> 2 -> 4`).
- `height(root)` will return `3 - 1 = 2`, which is the correct height.

### **Final Summary**
- `solve()` counts the total depth (number of nodes).
- `height()` adjusts it by subtracting `1` to get the correct number of edges.  
- The height of a tree is the longest path from the root to a leaf node, measured in edges.