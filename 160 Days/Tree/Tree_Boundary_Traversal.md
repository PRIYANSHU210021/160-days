Problem: Tree Boundary Traversal


*CODE*

```C++
class Solution {
  public:
    
    void leftSolve(Node* root, vector<int>&ans)
    {
        if(root==NULL || (!root->left && !root->right)) return;
        ans.push_back(root->data);
        
        if(root->left)
        leftSolve(root->left,ans);
        else
        leftSolve(root->right,ans);
    }
    void leafSolve(Node* root, vector<int>&ans)
    {
        if(!root) return;
        if(!root->left && !root->right) 
        ans.push_back(root->data);
        
        leafSolve(root->left,ans);
        leafSolve(root->right,ans);
    }
    void rightSolve(Node* root, vector<int>&ans)
    {
        if(root==NULL || (!root->left && !root->right)) return;
        if(root->right)
        rightSolve(root->right,ans);
        else
        rightSolve(root->left,ans);
        ans.push_back(root->data);
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        
        ans.push_back(root->data);
        
        leftSolve(root->left,ans);
        if(root->left || root->right)
        leafSolve(root,ans);
        rightSolve(root->right,ans);
        
        return ans;
    }
```


This C++ code implements the **boundary traversal** of a binary tree. The goal is to traverse the boundary nodes in **anticlockwise** order, which includes:

1. **The root node**
2. **The left boundary** (excluding leaf nodes)
3. **All leaf nodes** (from left to right)
4. **The right boundary** (excluding leaf nodes, but added in reverse order)

### **Explanation of Functions**
---
#### **1. `leftSolve(Node* root, vector<int>& ans)`**
- This function **traverses the left boundary** of the tree.
- It ensures that **leaf nodes are excluded**.
- It **first adds the node** and then moves to its left child (if available); otherwise, it moves to the right child.

#### **2. `leafSolve(Node* root, vector<int>& ans)`**
- This function **collects all leaf nodes** (from left to right).
- If a node has **no left or right child**, it is a leaf node and is added to the result.
- The function **recursively calls itself** for the left and right subtrees.

#### **3. `rightSolve(Node* root, vector<int>& ans)`**
- This function **traverses the right boundary**.
- It avoids leaf nodes.
- Unlike `leftSolve()`, this function **first explores deeper nodes** (recursively) and then **adds them to the answer list (post-order fashion)**, ensuring they appear in **reverse order**.

---
### **Main Function: `boundaryTraversal(Node *root)`**
- This function orchestrates the boundary traversal:
  1. Adds the **root** node.
  2. Calls `leftSolve(root->left, ans)` to add the **left boundary**.
  3. Calls `leafSolve(root, ans)` to add all **leaf nodes**.
  4. Calls `rightSolve(root->right, ans)` to add the **right boundary**.

---
### **Time Complexity**
Each node is visited once, making the time complexity **O(N)**.

---
### **Example**
#### **Input Tree**
```
        1
       / \
      2   3
     / \   \
    4   5   6
       / \   \
      7   8   9
```
#### **Boundary Traversal Output**
```
[1, 2, 4, 7, 8, 9, 6, 3]
```

