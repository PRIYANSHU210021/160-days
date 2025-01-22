Problem: Add Number Linked Lists

*Code*
Time Complexity: O(n + m)
Space: O(max(n, m))


![alt text](image.png)

``` 
class Solution {
  public:
  Node *reversell(Node* head)
  {
      Node* prev= NULL, *curr= head, *fut=NULL;
      while(curr)
      {
      fut = curr->next;
      curr->next = prev;
      prev = curr;
      curr = fut;
      }
      return prev;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* head1 = reversell(num1);
        Node* head2 = reversell(num2);
        Node *temp = new Node(-1);
        Node* ptr = temp;
        int carry=0;
        while(head1 && head2)
        {
            int sum = head1->data + head2->data+ carry;
            ptr->next = new Node(sum%10);
            carry = sum / 10;
            ptr = ptr->next;
            head1= head1->next;
            head2= head2->next;
        }
        while(head1)
        {
            int sum = head1->data+carry;
            ptr->next = new Node(sum%10);
            carry = sum / 10;
            ptr = ptr->next;
            head1= head1->next;
        }
        while(head2)
        {
            int sum = head2->data+carry;
            ptr->next = new Node(sum%10);
            carry = sum / 10;
            ptr = ptr->next;
            head2= head2->next;
        }
        while(carry)
        {
            ptr->next= new Node(carry%10);
            carry /=10;
        }
       
       Node* fans = reversell(temp->next);
       while(fans->data==0)
       {
           fans = fans->next;
       }
       return fans;
       
    }
};
```

