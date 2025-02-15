This function finds the **Lowest Common Ancestor (LCA)** of two given nodes (**n1** and **n2**) in a **Binary Tree**. Let's break it down step by step:

---

### **Code Explanation**
```cpp
class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(root==NULL || root==n1 || root == n2)
            return root;
        
        Node* left = LCA(root->left, n1, n2);
        Node* right = LCA(root->right, n1, n2);
        
        if(left == NULL) 
            return right;
        else if(right == NULL)
            return left;
        else 
            return root;
    }
};
```

---

### **Step-by-Step Explanation**
1. **Base Case:**  
   - If `root == NULL`, return `NULL` (tree doesn't exist).
   - If `root == n1` or `root == n2`, return `root` (because if a node itself is one of the required nodes, then it must be the LCA).

2. **Recursive Calls (Divide and Conquer Approach)**  
   - Call `LCA(root->left, n1, n2)` to search for LCA in the left subtree.
   - Call `LCA(root->right, n1, n2)` to search for LCA in the right subtree.

3. **Decision Making:**  
   - **Case 1:** If the left subtree returns `NULL`, it means both nodes are in the right subtree, so return `right`.
   - **Case 2:** If the right subtree returns `NULL`, it means both nodes are in the left subtree, so return `left`.
   - **Case 3:** If both left and right return non-NULL values, it means one node is in the left subtree and the other is in the right subtree. In this case, the **current root is the LCA**.

---

### **Dry Run Example**
#### **Given Binary Tree:**
```
        3
       / \
      5   1
     / \  / \
    6  2 0  8
      / \
     7   4
```
#### **Finding LCA of (5,1)**
1. `n1 = 5`, `n2 = 1`
2. LCA(5,1) is **3** (because node 5 is in the left subtree and node 1 is in the right subtree).

---

### **Time Complexity**
- **O(N)** in the worst case (since we traverse the entire tree).

### **Credit** (I hope you guys you are exteeeeeeeeemly well)
This explanation is based on **Striver's** approach, which helped in understanding the concept well. 