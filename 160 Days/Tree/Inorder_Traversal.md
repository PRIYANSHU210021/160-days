Program: Inorder Traversal

*Code*

```c++
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void solve(Node*root , vector<int>&v)
    {
        if(root==NULL) return;
        solve(root->left,v);
        v.push_back(root->data);
        
        solve(root->right,v);
    }
    vector<int> inOrder(Node* root) {
        vector<int>v;
        solve(root,v);
        return v;
    }
};
```

---

## **Understanding Inorder Traversal**
### **Definition:**
**Inorder Traversal (Left → Root → Right)**  
- First, visit the **left subtree**  
- Then, visit the **root node**  
- Finally, visit the **right subtree**  

---

## **Code Explanation**
### **1. Function: `solve(Node* root, vector<int>& v)`**
- This is a **recursive helper function** that performs the inorder traversal and stores the values in the vector `v`.
- **Base case:** If the node is `NULL`, return immediately.
- **Recursive calls:**  
  - **First**, call `solve()` on the left child (visit left subtree).
  - **Then**, push the current node’s value into the vector `v` (process root).
  - **Finally**, call `solve()` on the right child (visit right subtree).  

### **2. Function: `inOrder(Node* root)`**
- This is the main function that initializes an empty vector `v` and calls `solve(root, v)`.
- Once `solve()` fills the vector `v`, it **returns** the vector containing the inorder traversal.

---

## **Step-by-Step Dry Run**
### **Example Tree**
```
        1
       / \
      2   3
     / \
    4   5
```

### **Step 1: Function Call**
```cpp
inOrder(root) → solve(root, v)
```

### **Step 2: Recursive Execution**
| Call Stack | Action |
|------------|--------|
| `solve(1, v)` | Move left → `solve(2, v)` |
| `solve(2, v)` | Move left → `solve(4, v)` |
| `solve(4, v)` | Left NULL → Push `4` → Right NULL |
| Back to `solve(2, v)` | Push `2` → Move right → `solve(5, v)` |
| `solve(5, v)` | Left NULL → Push `5` → Right NULL |
| Back to `solve(1, v)` | Push `1` → Move right → `solve(3, v)` |
| `solve(3, v)` | Left NULL → Push `3` → Right NULL |

### **Step 3: Final Vector**
```
v = [4, 2, 5, 1, 3]
```
This is the **inorder traversal** of the tree.

---

## **Final Output**
```cpp
vector<int> result = inOrder(root); 
// result = [4, 2, 5, 1, 3]
```

---

## **Complexity Analysis**
- **Time Complexity:** **O(N)** → Every node is visited **once**.
- **Space Complexity:** **O(N)** (for the result vector + recursion stack in the worst case of a skewed tree).

---

## **Summary**
✔ **Recursive function `solve()`** ensures **left → root → right** traversal.  
✔ **Base case (`if(root == NULL) return;`)** prevents errors.  
✔ **Vector `v` stores the final inorder traversal result.**  
✔ **Time complexity is O(N).**  
