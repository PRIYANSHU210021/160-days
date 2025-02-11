# Checking if a Binary Tree is a BST

## Approach:
To determine whether a given binary tree is a Binary Search Tree (BST), we use **inorder traversal**. In a BST, an inorder traversal should always produce a sorted sequence in **ascending order**.

## Steps:
1. Perform an **inorder traversal** (Left → Root → Right) of the binary tree and store the elements in a list.
2. Check if the stored list is sorted in ascending order.
   - If it is sorted, then the given binary tree is a BST.
   - Otherwise, it is not a BST.

## Code Implementation:
```cpp
class Solution {
  public:
    // Helper function to perform inorder traversal
    void solve(Node* root, vector<int>& ans) {
        if (root == NULL)
            return;
        
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }

    // Function to check whether a Binary Tree is BST or not
    bool isBST(Node* root) {
        vector<int> ans;
        solve(root, ans);
        
        // Check if inorder traversal is sorted
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i - 1] > ans[i])
                return false;
        }
        return true;
    }
};

```

## Complexity Analysis:
- **Inorder Traversal** takes **O(N)** time, where `N` is the number of nodes in the tree.
- Checking if the list is sorted takes **O(N)** time.
- Thus, the overall **time complexity is O(N)**.

## Alternative Approach (Without Extra Space):
Instead of storing elements in a list, we can check directly during traversal using a pointer/reference to the previous node. This reduces **space complexity to O(1)** instead of **O(N)**.

```c++
class Solution {
  private:
    Node* prev = NULL;
    
  public:
    bool isBST(Node* root) {
        if (root == NULL) return true;

        // Check left subtree
        if (!isBST(root->left)) return false;

        // Validate current node
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        // Check right subtree
        return isBST(root->right);
    }
};
```

## Conclusion:
- **Method 1 (Using extra space - vector)**: **O(N) time, O(N) space**
- **Method 2 (Optimized - Without extra space)**: **O(N) time, O(1) space**
