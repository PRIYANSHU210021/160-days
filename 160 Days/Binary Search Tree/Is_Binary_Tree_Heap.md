# Problem: Is Binary Tree Heap
# Code: 

```c++
class Solution {
  public:
    int size(Node*root)
    {
        if(root==NULL) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    
    bool compare(Node *root)
    {
        if(root== NULL) return true;
        if(root->left && root->left->data > root->data) return false;
        if(root->right && root->right->data > root->data) return false;
        return compare(root->left) && compare(root->right);
    }
    bool isCBT(Node *root)
    {
        int s = size(root);
        queue<Node*>q;
        q.push(root);
        int cnt = 0;
        while(cnt!=s)
        {
            Node*temp = q.front();
            q.pop();
            cnt++;
            if(temp!=NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        while(!q.empty())
        {
            if(q.front()!=NULL) return false;
            q.pop();
        }
            return true;
    }
    bool isHeap(Node* tree) {
        return compare(tree) && isCBT(tree);
    }
};
```

# Explanation of the Code:

## Problem:
The goal is to check whether a given binary tree is a **Max Heap**.  
A binary tree is a Max Heap if:
1. It is a **Complete Binary Tree (CBT)**.
2. Every node's value is **greater than or equal to** the values of its children.


## 1. `int size(Node* root)`

- **Purpose:**  
  Calculates the total number of nodes in the binary tree.

- **Logic:**  
  - If the node is `NULL`, return 0.
  - Otherwise, recursively add:
    - 1 (for the current node) +
    - size of the left subtree +
    - size of the right subtree.

- **Why:**  
  The size is needed later to help verify if the tree is a Complete Binary Tree.

---

## 2. `bool compare(Node* root)`

- **Purpose:**  
  Checks whether the tree follows the **Max Heap property**.

- **Logic:**  
  - If the node is `NULL`, return `true`.
  - If the left child exists and its value is greater than the current node's value, return `false`.
  - If the right child exists and its value is greater than the current node's value, return `false`.
  - Recursively check the left and right subtrees.

- **Why:**  
  Ensures that every parent node is greater than its children — the key property of a Max Heap.

---

## 3. `bool isCBT(Node* root)`

- **Purpose:**  
  Checks whether the tree is a **Complete Binary Tree**.

- **Logic:**  
  - First, find the total number of nodes (`size(root)`).
  - Perform a **level order traversal** (BFS) using a queue:
    - Push the root node into the queue.
    - Keep popping nodes one by one and counting them.
    - For each non-NULL node, push its left and right children (even if they are NULL) into the queue.
    - Stop the first loop once all expected nodes are counted.
  - After the expected number of nodes are popped:
    - If any **non-NULL** node is still present in the queue, it means the tree is **not complete** → return `false`.
    - Otherwise, return `true`.

- **Important Idea:**  
  - In a Complete Binary Tree, once a `NULL` is encountered during level-order traversal, there should be no further non-NULL nodes.
  - If any non-NULL node appears after a NULL, the tree is not complete.

---

## 4. `bool isHeap(Node* tree)`

- **Purpose:**  
  Final method to check if the tree is a **Max Heap**.

- **Logic:**  
  - Calls `compare(tree)` to ensure the Max Heap property is satisfied.
  - Calls `isCBT(tree)` to ensure the tree structure is complete.
  - Returns `true` only if **both** checks pass.

---
