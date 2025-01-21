Problem: Linked_List_Group_Reverse

TC: O(N)
SC: O(1)

*CODE*


```c++
Node *reverseKGroup(Node *head, int k) {
        if(head==NULL) return NULL;
        Node *prev=NULL , *curr = head, *fut=NULL;
        int cnt=0;
        while(curr && cnt<k)
        {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
            cnt++;
        }
        if(fut) // still future node exist after k move
        {
            head->next = reverseKGroup(fut,k);
        }
        return prev;
    }
```


Here, we should know how reverese linked lists so,

KEY IDEA:
The function works recursively:
    It reverses the first k nodes of the linked list.
    It calls itself for the rest of the list (the part after the first k nodes) and reverses the next group of k nodes.
    Finally, it connects the reversed first k nodes to the reversed result of the rest of the list
