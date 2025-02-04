Problem: Diameter of a Binary Tree

*Code*
```c++
class Solution {
  public:
    int solve(Node* root,int &d)
    {
        if(root==NULL) 
        return 0;
        
        int left = solve(root->left,d);
        int right = solve(root->right,d);
        d = max(d, left+right);
        return 1+max(left,right);
    }
    int diameter(Node* root) {
       int d = 0;
       solve(root,d);
       return d;
    }
};
```

---

## **Understanding the Diameter of a Binary Tree**
- The **diameter** of a binary tree is the **longest path between any two nodes** in the tree.
- The path may or may not **pass through the root**.
- It is measured in **number of edges**, so we need to count the edges between nodes.

---

## **Code Breakdown**
### **Function: `solve(Node* root, int &d)`**
This function is a **helper function** that:
1. **Recursively computes** the height of the left and right subtrees.
2. **Updates the diameter `d`** whenever the sum of left and right subtree heights (`left + right`) is larger than the current `d`.
3. Returns the height of the current subtree.

### **Function: `diameter(Node* root)`**
- Initializes `d = 0` to store the maximum diameter.
- Calls `solve(root, d)`, which updates `d` with the maximum diameter.
- Returns the final diameter value.

---

## **Step-by-Step Execution**
### **1. Base Case (`if (root == NULL) return 0;`)**
- If the node is `NULL`, return `0` (height of an empty subtree is `0`).

### **2. Recursive Calls (`left = solve(root->left, d);` & `right = solve(root->right, d);`)**
- Recursively **compute heights** of left and right subtrees.

### **3. Update Diameter (`d = max(d, left + right);`)**
- The diameter for any node is `left height + right height`.
- If this is greater than the current `d`, update `d`.

### **4. Return Height (`return 1 + max(left, right);`)**
- The height of the current node is `1 + max(left, right)`, because:
  - `1` represents the current node.
  - `max(left, right)` takes the larger height of the left or right subtree.

---

## **Example Execution**
### **Tree:**
```
        1
       / \
      2   3
     / \  
    4   5
```
### **Recursive Calls**
| Node | Left Height | Right Height | Diameter `d` |
|------|------------|-------------|--------------|
| 4    | 0          | 0           | 0            |
| 5    | 0          | 0           | 0            |
| 2    | 1          | 1           | 2 (1+1)      |
| 3    | 0          | 0           | 2            |
| 1    | 2          | 1           | 3 (2+1)      |

### **Final Output**
`diameter(root) → 3`

---

## **Time Complexity**
- Each node is **visited once**, and at each node, we perform **O(1) operations**.
- **Time Complexity: O(N)** (where N = number of nodes).
- **Space Complexity: O(H)** (due to recursion stack, where H = height of tree).

---

## **Key Takeaways**
1. The function **calculates height** but also **updates the diameter simultaneously**.
2. The **diameter is the longest path (edges) between any two nodes**.
3. **Efficient O(N) approach** using postorder traversal.

Let me know if you have any doubts! 🚀