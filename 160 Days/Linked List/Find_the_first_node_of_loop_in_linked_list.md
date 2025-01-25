Problem: **Find the first node of loop in linked list
**

Iam Solve With Both Approaches Brute and optimize

```c++
 Brute:
 TC: O(N)
 SC: O(N)

 class Solution {
  public:
    Node* findFirstNode(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp = head;
        while(temp)
        {
            if(mp.find(temp)!=mp.end())
            {
                temp->next = NULL;
                return temp;
            }
            mp[temp]++;
            temp=temp->next;
        }
        return new Node(-1);
        
    }
};


Optimize:
TC: O(N)
SC: O(1)

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                slow = head;
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return new Node(-1);
    }
};
```


*Explaination*
### **Brute Force Approach **  
1. Use a hash map to store visited nodes while traversing the linked list.  
2. For each node, check if it already exists in the map.  
3. If it exists, it means a cycle is detected, and the current node is the starting point of the cycle.  
4. If no cycle is detected, return a new node with value `-1`.  
5. This approach has **O(N)** time complexity but requires **O(N)** additional space for the map.  

---

### **Optimized Approach **  
1. Use two pointers (`slow` and `fast`), where `slow` moves one step and `fast` moves two steps.  
2. If the pointers meet, reset `slow` to the head and keep `fast` at the meeting point.  
3. Move both pointers one step at a time until they meet again, which will be the start of the cycle.  
4. If no cycle exists, `fast` will reach `NULL`, and return a new node with value `-1`.  
5. This approach has **O(N)** time complexity and **O(1)** space complexity.  

--------------------------------------
If you want to understand how the fast and slow pointers work in this question, check out this link: https://www.youtube.com/watch?v=2Kd0KKmmHFc



