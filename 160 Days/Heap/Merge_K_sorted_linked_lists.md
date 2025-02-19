# Problem: Merge K sorted linked lists

```c++
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
       priority_queue<pair<int,Node*>,vector<pair<int,Node*>>, greater<pair<int,Node*>>>pq;
       Node* ans = new Node(0);
       Node* temp = ans;
       
        for(auto x:arr)
            pq.push({x->data,x});
        
        while(!pq.empty())
        {
            auto curr = pq.top().second;
            pq.pop();
            temp -> next = curr;
            temp = temp->next;
            if(curr->next)
            {
                curr = curr->next;
                pq.push({curr->data,curr});
            }
            
        }
        return ans->next;
    }
};
```

### Explanation of the Code:
The given C++ function `mergeKLists` is designed to merge **K sorted linked lists** into a single sorted linked list. It uses a **min-heap (priority queue)** to efficiently extract the smallest node among the heads of all the lists.

---

### **Understanding the Approach**
- A **priority queue (min-heap)** is used to always extract the smallest available node.
- A dummy node (`ans`) is used to simplify list construction.
- We iterate over the lists and push their heads into the min-heap.
- We then repeatedly extract the smallest element from the heap and link it to our result list.
- If the extracted node has a next node, we push that into the heap.
- Finally, the merged list is returned.

---

### **Code Breakdown**
```cpp
class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
       priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
       Node* ans = new Node(0); // Dummy node
       Node* temp = ans; // Pointer to construct result list
```
- We define a **min-heap (`pq`)** that stores pairs `(node->data, node*)`. The **smallest element** will always be on top.
- We create a **dummy node (`ans`)** to make it easier to build the merged list.

---

```cpp
       for(auto x : arr)
            pq.push({x->data, x});
```
- We insert the **head nodes** of all `K` lists into the min-heap.

---

```cpp
        while(!pq.empty()) {
            auto curr = pq.top().second; // Get the smallest node
            pq.pop(); // Remove it from the heap
            temp->next = curr; // Link to result list
            temp = temp->next; // Move temp pointer forward
            
            if(curr->next) { 
                curr = curr->next; 
                pq.push({curr->data, curr}); // Push next node of the current list
            }
        }
```
- We extract the **smallest node** from the heap.
- We attach it to our result list.
- If this node has a next node, we **push it back** into the heap to maintain the sorted order.

---

```cpp
        return ans->next; // Return the merged list (skip dummy node)
    }
};
```
- We **return `ans->next`** because `ans` is just a dummy node.

---

### **Time Complexity Analysis**
- **Pushing `K` nodes initially:** \( O(K \log K) \)
- **Extracting & Inserting each node (N nodes in total):** \( O(N \log K) \)
- **Total Complexity:** \( O(N \log K) \), where \( N \) is the total number of nodes across all lists.

