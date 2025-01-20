Problem: Merge _two_sorted_linked_lists

TC: O(n+m)
SC: O(1)

```c++
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Node* head;
        Node* head = new Node(-1);
        Node* temp = head;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->data < head2->data)
            {
                head->next = head1;
                head1 =  head1->next;
                head = head->next;
            }
            else
            {
                head->next = head2;
                head2 =  head2->next;
                head = head->next;
            }
        }
        if(head1!=NULL)
            head->next = head1;

        if(head2!=NULL)
            head->next = head2;
        
        return temp->next;
    
    }
};
```


*Approach*

1. Initial Setup
    You create a dummy node head with a value of -1 (this value is arbitrary and acts as a placeholder).
    You also initialize a pointer temp that points to the dummy node head. This pointer helps in returning the merged 
    list's head at the end, as head will be shifted forward during the merging process.


2. Traverse Both Lists
    • You iterate through both linked lists (head1 and head2) simultaneously using a while loop, which runs until one of 
        the lists becomes NULL.
    
    • Inside the loop:
        Compare the data values of the current nodes of head1 and head2.
    • If head1->data is smaller, set head->next to point to head1, move head1 to its next node, and advance head to its 
    next node as well.
    • If head2->data is smaller or equal, set head->next to point to head2, move head2 to its next node, and advance head 
    to  its next node as well.

3.  Handle Remaining Nodes
    • After the loop, one of the lists (head1 or head2) may still have remaining nodes.
    • If head1 is not NULL, set head->next to the remaining part of head1.
    • If head2 is not NULL, set head->next to the remaining part of head2.

4. Return the Result
    • Since temp initially pointed to the dummy node head, and the actual merged list starts from the next node of head, 
        you return temp->next.
