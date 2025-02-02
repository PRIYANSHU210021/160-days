Problem: Level_Order_Traversal

*code**
```c++
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        queue<Node*>q;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp2;
            for(int i=0;i<n;i++)
            {
                 Node*temp = q.front();
            q.pop();
            temp2.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            }
           ans.push_back(temp2);
        }
        return ans;
    }
};

```
This C++ code performs a **level order traversal** of a **binary tree** using the **Breadth-First Search (BFS)** approach. In simple terms, it visits the tree **level by level**, starting from the **root**, then its **children**, then their **children**, and so on.  

---

### **Step-by-Step Explanation**
1. **Using a Queue for BFS Traversal**  
   - A queue (`q`) is used to store nodes level by level.  
   - A **2D vector (`ans`)** stores the final result, where each inner vector represents nodes of one level.  

2. **Starting with the Root Node**  
   - The root node is pushed into the queue.  
   - While the queue is **not empty**, we process all nodes of the current level.  

3. **Processing Each Level**  
   - `n = q.size()` stores the number of nodes at the current level.  
   - A temporary vector (`temp2`) stores values of nodes at this level.  
   - A **for loop** runs `n` times to process all nodes at the current level:  
     - The front node is **removed (popped)** from the queue.  
     - Its **value is stored** in `temp2`.  
     - If the node has a **left child**, push it into the queue.  
     - If the node has a **right child**, push it into the queue.  
   - After processing all nodes of a level, push `temp2` into `ans`.  

4. **Returning the Final Result**  
   - After all levels are processed, return `ans`, which contains the level order traversal of the tree.  

---

### **Example Walkthrough**
#### **Given Tree**
```
        1
       / \
      2   3
     / \   \
    4   5   6
```
#### **Step-by-step Traversal**
1. Start with the root (`1`) → Push into queue → `q = [1]`
2. Process level 1 → `temp2 = [1]`, add children (`2, 3`) → `q = [2, 3]`
3. Process level 2 → `temp2 = [2, 3]`, add children (`4, 5, 6`) → `q = [4, 5, 6]`
4. Process level 3 → `temp2 = [4, 5, 6]`, no more children → `q = []`
5. Queue is empty → Return `[[1], [2, 3], [4, 5, 6]]`

---

### **Final Output**
```cpp
[[1], [2, 3], [4, 5, 6]]
```
This represents the **level order traversal** of the binary tree. 🚀
