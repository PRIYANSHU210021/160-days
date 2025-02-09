Problem: Maximum path sum from any node

*code*

```c++
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int solve(Node* node, int &ans)
    {
        if(node==NULL) return 0;
        int leftSum = max(0,solve(node->left,ans));
        int rightSum = max(0,solve(node->right,ans));
        ans = max(ans,(leftSum+rightSum+node->data));
        return max(leftSum,rightSum)+node->data;
    }
    int findMaxSum(Node *root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
```

*approach*

1. **Recursive function `solve(Node* node, int &ans)`**:
   - This function works recursively to calculate the maximum path sum starting from each node.
   - It also updates the global variable `ans` to keep track of the highest path sum found so far.

#### Let's look at the steps inside `solve`:

- **Base Case (Empty Node):**
  ```cpp
  if (node == NULL) return 0;
  ```
  If the current node is `NULL` (i.e., the end of a branch is reached), the function returns `0` because an empty subtree contributes nothing to the path sum.

- **Recursive Calculation (Left and Right Subtree):**
  ```cpp
  int leftSum = max(0, solve(node->left, ans));
  int rightSum = max(0, solve(node->right, ans));
  ```
  Here, you're calculating the maximum path sum for the **left** and **right** subtrees recursively.
  - The `max(0, solve(...))` part ensures that if the path sum for the left or right subtree is negative, it is ignored (since negative path sums would reduce the overall path sum). You only want to consider positive contributions to the sum.
  
- **Update the Global Maximum Path Sum (`ans`):**
  ```cpp
  ans = max(ans, leftSum + rightSum + node->data);
  ```
  Now, the key part: You're considering the **path sum that passes through the current node**. This path includes:
  - The maximum path sum from the **left subtree** (`leftSum`).
  - The maximum path sum from the **right subtree** (`rightSum`).
  - The **current node's value** (`node->data`).
  
  So, `leftSum + rightSum + node->data` gives you the path sum that goes through the current node and includes both left and right children. You then update the global variable `ans` to track the maximum sum found.

- **Return the Maximum Path Sum from the Current Node:**
  ```cpp
  return max(leftSum, rightSum) + node->data;
  ```
  This line returns the maximum path sum that can **extend upwards** (to the parent node). 
  - You can extend the path either to the left or right subtree, so you take the maximum of the two (`leftSum` or `rightSum`) and add the current node's value (`node->data`).
  
  This ensures that the parent node can use this returned value to calculate the path sum for its own subtrees.

2. **Main Function `findMaxSum(Node *root)`**:
   - This is the main function that initializes the result and starts the recursive computation.
   
   ```cpp
   int ans = INT_MIN;
   solve(root, ans);
   return ans;
   ```
   - It initializes the `ans` variable to `INT_MIN` (a very small value to ensure the first valid path sum will override it).
   - It calls the `solve` function starting from the root of the tree.
   - After the recursive traversal, `ans` holds the maximum path sum, which is then returned.

### How It Works:
- **`solve`** computes the maximum path sum for each node, considering both downward paths and paths that go through the node (including both left and right children).
- The result is accumulated in the `ans` variable, which keeps track of the highest path sum seen at any point in the tree.
- The recursion allows you to explore every node in the tree while updating the global `ans` with the best possible path sum.

### Example Walkthrough:

Let's use a small tree to demonstrate:

```
        1
       / \
      2   3
     / \
    4   5
```

- **For node 4**: No children, so `leftSum = 0`, `rightSum = 0`. The max sum from node 4 is `0 + 0 + 4 = 4`. Return `max(0, 0) + 4 = 4`.
- **For node 5**: Similarly, `leftSum = 0`, `rightSum = 0`. The max sum from node 5 is `0 + 0 + 5 = 5`. Return `max(0, 0) + 5 = 5`.
- **For node 2**: Left sum = 4 (from node 4), right sum = 5 (from node 5). The max sum from node 2 is `4 + 5 + 2 = 11`. Return `max(4, 5) + 2 = 7`.
- **For node 3**: No children, so the max sum from node 3 is `3`. Return `max(0, 0) + 3 = 3`.
- **For node 1 (root)**: Left sum = 7 (from node 2), right sum = 3 (from node 3). The max sum from node 1 is `7 + 3 + 1 = 11`. Return `max(7, 3) + 1 = 8`.

Finally, the `ans` will hold the value `11`, which is the maximum path sum in the tree.
