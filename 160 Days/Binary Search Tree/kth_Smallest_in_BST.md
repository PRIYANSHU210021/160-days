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