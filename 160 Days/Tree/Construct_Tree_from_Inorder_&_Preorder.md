Problem: Construct Tree from Inorder & Preorder


*Code*

```c++
class Solution {
  public:
  
    Node* solve(vector<int>&inorder, vector<int>&preorder,int in_start,
    int in_end,int pre_start,int pre_end, unordered_map<int,int>&mp){
        if(in_start>in_end || pre_start>pre_end) 
        return NULL;
        
        Node *root = new Node(preorder[pre_start]);    
        int pos = mp[root->data];
        int left = pos-in_start;
        
        root->left = solve(inorder,preorder,in_start,in_start+left-1,pre_start+1,pre_start+left,mp);
        root->right = solve(inorder,preorder,in_start+left+1,in_end,pre_start+left+1,pre_end,mp);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]]=i;
        }
        return solve(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1, mp);
    }
};
```
### **🔹 Logic to Construct a Binary Tree from Inorder and Preorder Traversal**

#### **🔸 Problem Statement**
Given two arrays:
- **`inorder`** traversal of a binary tree (Left, Root, Right)
- **`preorder`** traversal of the same tree (Root, Left, Right)

We need to reconstruct the original binary tree.

---

## **🔹 Key Observations**
1. **Preorder Traversal Rule**:  
   - The first element of `preorder` is always the **root** of the tree.
   
2. **Inorder Traversal Rule**:  
   - The elements to the **left** of the root (in `inorder`) form the **left subtree**.
   - The elements to the **right** of the root (in `inorder`) form the **right subtree**.

3. **Recursive Construction**:
   - Identify the root using `preorder`.
   - Locate the root index in `inorder` (to split left & right subtrees).
   - Recursively build left and right subtrees.

---

## **🔹 Step-by-Step Execution**

### **Example Input**
```cpp
inorder   = [9, 3, 15, 20, 7]
preorder  = [3, 9, 20, 15, 7]
```

### **Step 1: Find Root**
- `preorder[0] = 3` → Root of the tree  
- Find `3` in `inorder` at index **1**  
  - Elements **left** of `3` → Left Subtree (`[9]`)  
  - Elements **right** of `3` → Right Subtree (`[15, 20, 7]`)  

### **Step 2: Build Left Subtree**
- `preorder[1] = 9` → Root of Left Subtree  
- Find `9` in `inorder` at index **0**  
  - No left or right child (as it's a single element)  

### **Step 3: Build Right Subtree**
- `preorder[2] = 20` → Root of Right Subtree  
- Find `20` in `inorder` at index **3**  
  - Left subtree: `[15]`
  - Right subtree: `[7]`

### **Step 4: Recursive Construction**
- Left subtree of `20`: `15`
- Right subtree of `20`: `7`

### **Final Tree Structure**
```
        3
       / \
      9   20
         /  \
        15   7
```
---

## **🔹 Code Explanation**

### **Function: `buildTree()`**
```cpp
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    unordered_map<int,int> mp;
    for(int i=0; i<inorder.size(); i++) {
        mp[inorder[i]] = i; // Store index of each element in inorder
    }
    return solve(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1, mp);
}
```
- **Stores indices of inorder elements** in `mp` for O(1) lookup.
- Calls `solve()` to recursively construct the tree.

---

### **Function: `solve()`**
```cpp
Node* solve(vector<int>& inorder, vector<int>& preorder, 
            int in_start, int in_end, int pre_start, int pre_end, 
            unordered_map<int, int>& mp) {
    
    if (in_start > in_end || pre_start > pre_end) 
        return NULL; // Base case: If no elements left

    // Root is always first element of preorder
    Node *root = new Node(preorder[pre_start]);
    
    // Find root index in inorder
    int pos = mp[root->data];

    // Count nodes in left subtree
    int left = pos - in_start;

    // Recursive calls to construct left and right subtrees
    root->left = solve(inorder, preorder, in_start, pos - 1, 
                       pre_start + 1, pre_start + left, mp);
    
    root->right = solve(inorder, preorder, pos + 1, in_end, 
                        pre_start + left + 1, pre_end, mp);

    return root;
}
```
---

## **🔹 Time & Space Complexity**
- **Time Complexity: O(N)**  
  - `mp` lookup is O(1), and we visit each node once.

- **Space Complexity: O(N)**  
  - Recursion stack in worst case (skewed tree).

---

## **🔹 Summary**
✔ **Use preorder to find root**  
✔ **Use inorder to split left and right subtrees**  
✔ **Use recursion to construct tree**  
✔ **Use a hashmap for quick lookups**
