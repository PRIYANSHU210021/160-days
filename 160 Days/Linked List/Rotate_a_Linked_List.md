Program: "Rotate_a_Linked_List"

*code*

TC: O(N)
Sc: O(1)

```c++
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        Node* temp=head, *curr=NULL;
        int n = 1;
        while(temp->next)
        {
        temp= temp->next;
            n++;
        }
        k = k%n;
        while(k)
        {
            temp->next = head;
            head = head->next;
            temp = temp->next;
            k--;
        }
        temp->next = NULL;
        return head;
        
    }
};
```

*Approach*

1.  Calculate length: You use a pointer (temp) to traverse the linked list and calculate its length (n).
2. Normalize rotations: You reduce k by taking k % n to handle cases where k is greater than the length of the list.
    
3.  Perform rotations:
    • You connect temp->next to head to create a circular linked list.
    • Move the head pointer forward and update temp for k steps to perform the rotation.

4. Break the circular link: Finally, set temp->next = NULL to break the circular link and return the updated head.