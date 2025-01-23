
Problem: Clone_List_with_Next_and_Random

Time Complexity: O(n)
Space: O(1)

```c++
 Node *cloneLinkedList(Node *head) {
        map<Node*,Node*>mp;
        Node* temp = head;
        while(temp)
        {
            mp[temp] = new Node(temp->data);
            temp=temp->next;
        }
        temp = head;
        Node* main = new Node(-1);
        Node* ptr = main;
        while(temp)
        {
            mp[temp] -> next = temp->next;
            mp[temp]->random = mp[temp->random];
            ptr->next = mp[temp];
            ptr = ptr->next;
            temp = temp->next;
        }
        return main->next;
        
    }
```



*Intution*
### **7-Line Explanation**
1. **Map Creation:** Ek map banate hain jo original list ke har node ko uske cloned node se map karta hai.  
   ```cpp
   mp[temp] = new Node(temp->data);
   ```

2. **Clone Nodes:** Map ke through original list ke har node ka ek naya clone create karte hain.

3. **Set Next Pointer:** Har cloned node ka `next` pointer, original node ke `next` node ke clone par point karega.  
   ```cpp
   mp[temp]->next = mp[temp->next];
   ```

4. **Set Random Pointer:** Har cloned node ka `random` pointer, original node ke `random` node ke clone par point karega.  
   ```cpp
   mp[temp]->random = mp[temp->random];
   ```

5. **Build Cloned List:** Dummy node (`main`) ka use karte hue naye cloned list ko build karte hain.

6. **Preserve Original List:** Har pointer cloned nodes par set hota hai, isliye original list unchanged rehti hai.

7. **Return Cloned Head:** Dummy node ke `next` ko return karte hain, jo cloned list ka head hota hai.  
   ```cpp
   return main->next;
   ```