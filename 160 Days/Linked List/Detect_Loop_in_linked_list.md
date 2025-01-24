Problem: Detect Loop in linked list


**Today's POTD (Problem of the Day) was initially solved by me using a brute-force approach with extra space. Later, I explored the concept of slow and fast pointers and used that understanding to solve the question efficiently.**

Using space

```c++

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
      set<Node*>mp;
      Node* temp = head;
      while(temp)
      {
          if(mp.find(temp->next)!=mp.end())
          return true;
          mp.insert(temp);
          temp=temp->next;
      }
      return false;
    }    
};

```

Using slow and fast pointer concept

```c++

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
      Node* slow = head,*fast=head;
      while(fast!=NULL && fast->next != NULL)
      {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        return true;
      }
      return false;
    }   

```

*Approach*

Initially, I solved today’s POTD (Problem of the Day) using a brute-force approach, where I utilized additional space to keep track of the elements. By storing the elements in a data structure like a set or an array, I was able to identify patterns or conditions required to solve the problem. Although this approach was straightforward and easy to implement, it wasn’t optimal in terms of space complexity.

Later, I revisited the problem and explored the concept of slow and fast pointers to solve it efficiently without using extra space. By employing this technique, I was able to detect patterns or loops within the problem by iterating through the data with two pointers moving at different speeds. This approach not only improved the space complexity but also enhanced my understanding of the two-pointer method, making the solution more elegant and efficient.