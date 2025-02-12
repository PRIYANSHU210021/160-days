```c++
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void solve(Node* node, vector<int>&ans)
    {
        if(!node)
        return;
        
        solve(node->left,ans);
        ans.push_back(node->data);
        solve(node->right,ans);
        
    }
    int kthSmallest(Node *root, int k) {
       vector<int>ans;
        solve(root,ans);
        if(ans.size()<k)
        return -1;
        return ans[k-1];
    }
};

```
### **1. `solve(Node* node, vector<int>& ans)`**
- Ye function **recursive inorder traversal** karta hai (Left → Root → Right).
- Sabse pehle **left subtree** traverse hota hai.
- Phir **current node** ka data vector `ans` me store hota hai.
- Finally, **right subtree** traverse hota hai.
- Is traversal se **sorted order** me values milti hain (BST property ke wajah se).

---

### **2. `kthSmallest(Node *root, int k)`**
- Ek `vector<int> ans` banaya gaya hai jo BST ke elements ko **sorted order me store karega**.
- `solve(root, ans);` call karke BST ke **sorted elements vector me store** ho jayenge.
- Ab agar `ans.size() < k`, to iska matlab BST me k elements hi nahi hain, **to -1 return kar diya**.
- **Nahi to** `ans[k-1]` return kar diya, jo **k-th smallest element** hai.

---

### **Example**
#### **Input**
BST:
```
        5
       / \
      3   8
     / \   \
    2   4   10
```
Agar `k = 3` diya ho, to inorder traversal (`solve`) karega:
```
[2, 3, 4, 5, 8, 10]  // Sorted order
```
- `3rd` smallest element `4` hoga.
- Code `return ans[3-1] = ans[2] = 4;` karega.

---

### **Time Complexity**
- **Inorder traversal** ka time complexity **O(N)** hota hai.
- Element access `O(1)` me hota hai.
- **Overall complexity:** `O(N)`

---
# *Better* #


```c++
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int solve(Node* node, int k, int &cnt)
    {
        if(!node)
        return -1;
        
        int left = solve(node->left,k,cnt);
        if(left != -1)
        return left;
        cnt++;
        if(cnt==k)
        return node->data;
        
        return solve(node->right,k,cnt);
                
    }
    int kthSmallest(Node *root, int k) {
        int cnt = 0;
        return solve(root,k,cnt);
    }
};
```

#### **1. `solve(Node* node, int k, int &cnt)` (Recursive Function)**
This function performs **inorder traversal** (Left → Root → Right) and maintains a **counter (`cnt`)** to track the number of nodes visited.

#### **2. Base Condition**
```cpp
if (!node)
    return -1;
```
- If the node is `NULL`, return `-1`, meaning the element was not found.

#### **3. Left Subtree Traversal**
```cpp
int left = solve(node->left, k, cnt);
if (left != -1)
    return left;
```
- First, we recursively traverse the **left subtree**.
- If the `left` subtree finds the `k-th` element (`left != -1`), return it immediately.

#### **4. Process the Current Node**
```cpp
cnt++;
if (cnt == k)
    return node->data;
```
- Increase the **counter `cnt`** because we have visited one more node.
- If **`cnt == k`**, return the current node's value as the `k-th` smallest element.

#### **5. Right Subtree Traversal**
```cpp
return solve(node->right, k, cnt);
```
- If the current node is **not** the `k-th` smallest, continue to the **right subtree**.

---

### **`kthSmallest(Node *root, int k)`**
```cpp
int cnt = 0;
return solve(root, k, cnt);
```
- Initializes `cnt = 0` to keep track of the count.
- Calls `solve(root, k, cnt)` to find the `k-th` smallest element.

---

### **Example Walkthrough**
#### **BST Structure**
```
        5
       / \
      3   8
     / \   \
    2   4   10
```
**Find `k = 3` (3rd smallest element)**  
- **Inorder traversal:** `[2, 3, 4, 5, 8, 10]`
- `cnt` increases at:  
  - `2` (`cnt = 1`)
  - `3` (`cnt = 2`)
  - `4` (`cnt = 3`) → **Return `4`**

---

### **Time & Space Complexity**
- **Time Complexity:** `O(H + K)`, where `H` is the height of the BST.
- **Space Complexity:** `O(H)`, due to recursion stack (better than `O(N)` array storage).

---

### **Why is this better than storing in a vector?**
- It **doesn't store all elements**, just tracks `cnt`.
- Saves **extra O(N) space**, making it more memory-efficient.
