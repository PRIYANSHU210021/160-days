Problem : Fixing Two nodes of a BST

# CODE #

```c++
class Solution {
public:
    void solve(Node* root, Node*& first, Node*& second, Node*& prev, Node*& temp) {
        if (!root) return;

        solve(root->left, first, second, prev, temp);
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                temp = root;
            } else {
                second = root;
            }
        }

        prev = root; 
        solve(root->right, first, second, prev, temp);
    }

    void correctBST(Node* root) {
        Node* first = NULL, *second=NULL, *prev=NULL, *temp =NULL;
        
        solve(root, first, second, prev, temp);
        if (first && second) {
            swap(first->data, second->data);
        } else if (first && temp) { 
            swap(first->data, temp->data);
        }
    }
};
```


This code is solving the problem of **correcting a BST (Binary Search Tree)** where **two nodes have been swapped** by mistake. The goal is to find and swap them back to restore the BST.

---

### **Understanding the Problem**
A BST follows these rules:
1. The left subtree contains smaller values than the root.
2. The right subtree contains larger values than the root.

If two nodes are swapped **by mistake**, the BST property is violated. This code finds the swapped nodes and swaps them back.

---

### ** How This Code Works**
The `correctBST` function:
1. Calls the **recursive function** `solve()` to **find the two misplaced nodes**.
2. Once found, it **swaps their values** to fix the BST.

---

### ** Step-by-Step Breakdown**
#### **1️ Recursive Function (`solve`)**
- It does an **in-order traversal** (left → root → right), which should give a **sorted sequence** in a correct BST.
- During traversal, it **compares the current node (`root`) with the previous node (`prev`)**.
- If the order is incorrect (`root->data < prev->data`), we **identify the misplaced nodes**:
  - **First misplaced node (`first`)**: Set when we find the **first disorder**.
  - **Second misplaced node (`second`)**: Set when we find the **second disorder** (if it exists).
  - **Temporary node (`temp`)**: Holds the second misplaced node in case only one swap is found.

#### **2️ Fixing the Swapped Nodes (`correctBST`)**
- After identifying `first` and `second`, we swap their values to fix the BST.
- If `second` was not found, we swap `first` with `temp`.

---

### **Example**
#### ** Input (Swapped BST)**
```
        10
       /  \
      5    8  <- (8 and 20 are swapped)
     / \    \
    2   20   15
```
Here, **20 and 8 are swapped**.

#### ** In-order Traversal (Expected vs. Actual)**
- Expected: **[2, 5, 8, 10, 15, 20]**
- Actual: **[2, 5, 20, 10, 15, 8]**   (wrong order)

#### ** Fixing Process**
1. Detect swapped nodes: **(20 and 8)**
2. Swap them back to **restore BST**.

#### ** Corrected BST**
```
        10
       /  \
      5    20
     / \    \
    2   8   15
```

---

### Summary 
1. The function **traverses the BST in-order**.
2. It finds the **two misplaced nodes**.
3. It **swaps their values** to restore the correct BST.

This method runs in **O(N) time** and uses **O(H) space** (for recursion stack, where H = tree height). 