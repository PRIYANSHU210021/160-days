Problem: Mirror Tree

*Code*

```c++
class Solution {
  public:
    void mirror(Node* node) {
        if(node==NULL)
        return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};
```


*Approach*

### **Mirror a Binary Tree – Step-by-Step Explanation**  

The function `mirror(Node* node)` converts a given binary tree into its **mirror image** by swapping the left and right child nodes at each level.

---

## **🔹 How Does It Work?**
The function follows **recursion**, meaning it breaks down the problem into smaller subproblems until it reaches a stopping condition.

### **1️⃣ Base Case**
- If the current node (`node`) is `NULL`, that means we have reached a leaf node’s child (empty), so we simply return.
- This ensures that we don’t access invalid memory.

```cpp
if(node == NULL) 
    return;
```

### **2️⃣ Swap Left and Right Subtrees**
- We **swap** the left and right child of the current node.

```cpp
swap(node->left, node->right);
```

### **3️⃣ Recursively Process Left and Right Subtrees**
- Now, we move to the **left** and **right** children and apply the same process.

```cpp
mirror(node->left);
mirror(node->right);
```

---

## **🔹 Example**
Let's understand with a binary tree.

### **🔸 Original Tree**
```
        1
       /  \
      2    3
     / \  / \
    4   5 6  7
```

### **🔸 Step-by-Step Execution**
#### **Step 1: Start from Root (Node 1)**
- Swap left (`2`) and right (`3`).

```
        1
       /  \
      3    2
     / \  / \
    6   7 4  5
```

#### **Step 2: Move to Left Subtree (Node 3)**
- Swap left (`6`) and right (`7`).

```
        1
       /  \
      3    2
     / \  / \
    7   6 4  5
```

#### **Step 3: Move to Right Subtree (Node 2)**
- Swap left (`4`) and right (`5`).

```
        1
       /  \
      3    2
     / \  / \
    7   6 5  4
```

---

## **🔹 Final Mirrored Tree**
```
        1
       /  \
      3    2
     / \  / \
    7   6 5  4
```

---

## **🔹 Time Complexity**
The function visits every node **exactly once**, so the time complexity is:
\[
O(N)
\]
where `N` is the number of nodes in the tree.

---
