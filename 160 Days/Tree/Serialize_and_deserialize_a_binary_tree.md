# Problem: Serialize and deserialize a binary tree #

## Code:

```c++
class Solution {
  public:
    vector<int> serialize(Node *root) {
       vector<int>v;
       queue<Node*>q;
       q.push(root);
       while(!q.empty()){
           Node* temp = q.front();
           q.pop();
           if(temp==NULL)
               v.push_back(-1);
           else{
               
            v.push_back(temp->data);
                q.push(temp->left);
                q.push(temp->right);
           }
       }
    //   for(auto x:v) cout<<x;
       return v;
    }

    Node *deSerialize(vector<int> &arr) {
        if(arr.size()==0) return NULL;
        int i=1;
        Node* root = new Node(arr[0]);
        queue<Node*>que;
        que.push(root);
        while(i<arr.size() && !que.empty()){
            Node* temp2 = que.front();
            que.pop();
            if(arr[i]!=-1)
            {
                temp2->left = new Node(arr[i]);
                que.push(temp2->left);
            }
            i++;
            if(i<arr.size() && arr[i]!=-1){
                temp2->right = new Node(arr[i]);
                que.push(temp2->right);
            }
            i++;
        }
        return root;
    }
};
```


1. **`serialize(Node* root)`** – Converts a binary tree into a list (vector) using level-order traversal.
2. **`deSerialize(vector<int> &arr)`** – Reconstructs the binary tree from the serialized list.

---

## **Serialization Logic (`serialize`)**
The goal of this function is to convert the binary tree into a list representation using **level-order traversal** (BFS). 

### **Steps:**
1. **Initialize a queue** (`q`) to store nodes for BFS.
2. **Push the root** node into the queue.
3. **Process nodes one by one**:
   - Remove (`pop`) the front node from the queue.
   - If the node is **not NULL**, push its data into the result vector `v` and **enqueue its left and right children**.
   - If the node is **NULL**, push `-1` into `v` to indicate a null child.
4. **Return the vector** containing the serialized tree.

### **Example:**
**Tree Structure:**
```
       1
      / \
     2   3
    / \   \
   4   5   6
```
**Serialized Output:**
```
[1, 2, 3, 4, 5, -1, 6, -1, -1, -1, -1, -1, -1]
```
- `-1` represents NULL nodes.
- It maintains the **level order sequence** (BFS).

---

## **Deserialization Logic (`deSerialize`)**
This function reconstructs the binary tree from the serialized vector.

### **Steps:**
1. **Handle the edge case**: If `arr` is empty, return `NULL`.
2. **Create the root node** from `arr[0]` and initialize a queue (`que`) to track parent nodes.
3. **Use BFS to reconstruct the tree**:
   - Extract the front node (`temp2`) from the queue.
   - Read the **next element** in `arr`:
     - If **not -1**, create a left child and enqueue it.
   - Read the **next element** in `arr`:
     - If **not -1**, create a right child and enqueue it.
   - Repeat this process until `arr` is fully processed.

### **Example:**
Serialized Input:
```
[1, 2, 3, 4, 5, -1, 6, -1, -1, -1, -1, -1, -1]
```
Reconstructed Tree:
```
       1
      / \
     2   3
    / \   \
   4   5   6
```
- `-1` values are ignored (indicating null children).

---

### **Complexity Analysis**
1. **Serialization**:
   - Uses **level-order traversal** (BFS), so the **time complexity** is **O(N)** (where `N` is the number of nodes).
   - The **space complexity** is also **O(N)** (to store the serialized list and queue).

2. **Deserialization**:
   - Also uses **level-order traversal**, so **O(N)** time complexity.
   - Space complexity is **O(N)** due to the queue.

---
