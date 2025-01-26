Problem: Remove_loop_in_Linked_List

TC: O(N)
SC: O(1)

```c++
void removeLoop(Node* head) {
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast= fast->next->next;
            if(slow==fast)
            {
                slow=head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                Node* temp=fast;
                while(temp)
                {
                    if(temp->next == fast)
                        temp->next = NULL;
                    temp = temp->next;
                }

            }
            
        }
    }

```
*Approach*

- Your code uses slow and fast pointer to detect and remove a loop in a linked list.  
- `slow` and `fast` pointers are initialized at the head of the list.  
- `slow` moves one step, and `fast` moves two steps. If they meet, a loop is detected.  
- After detecting the loop, `slow` is reset to the head of the list.  
- `slow` and `fast` then move one step at a time until they meet, identifying the loop's starting node.  
- A temporary pointer (`temp`) is used to traverse the loop.  
- When `temp->next == fast`, the link is set to `NULL`, breaking the loop.  
- If `fast` or `fast->next` becomes null, there’s no loop in the list.  
- The code also handles edge cases like an empty list or a single-node loop.  
- The time complexity is O(N), and the space complexity is O(1), making it efficient.  