Problem: Reverese Linked List

*Code*

TC: O(N)
SC: O(1)

```c++
Node* reverseList(struct Node* head) {
        Node* curr=head, *prev = NULL, *fut=NULL;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        head = prev;
        return head;
    }
```

Simple Approach (Iterative)

1. First we hold curr next in fut for further use
2. current next point to previous one by curr->next = prev
3. prev help to store previous one using prev = curr.
4. now curr update to fut, means curr move further till curr exist
5. After ending of while loop head become prev because at that time prev at last node(for better understanding dry this code), and last return head.