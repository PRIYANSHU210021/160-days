# Problem: Maximum_XOR_of_two_numbers_in_an_array

# Code: 
```c++
class Solution {
  public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    int maxXor(vector<int> &arr) {
        trieNode* root = new trieNode();
        int finalmaXor = 0;
        for(int i=0; i<arr.size(); i++)
        {
            trieNode* temp = root;
            for(int j=31; j>=0; j--){
                int ith_bit = (arr[i]>>j)&1;
                if(ith_bit)
                {
                    if(temp->right==NULL)
                        temp->right = new trieNode();
                    temp = temp->right;
                }
                else
                {
                    if(temp->left==NULL)
                        temp->left = new trieNode();
                    temp = temp->left;
                }
            }
        }
        for(int i=0; i<arr.size(); i++)
        {
            int maXor = 0;
            trieNode* temp = root;
            for(int j=31; j>=0; j--){
                int ith_bit = (arr[i]>>j)&1;
                
                if(ith_bit==1)
                {
                    if(temp->left!=NULL)
                    {
                        maXor+= (1<<j);
                        temp = temp->left;
                    }
                    else
                        temp = temp->right;
                }
                else
                {
                    if(temp->right!=NULL)
                    {
                        maXor += (1<<j);
                        temp = temp->right;
                    }                    
                    else
                        temp = temp->left;
                }
            }
            finalmaXor = max(finalmaXor, maXor);
        }
        return finalmaXor;
    }
};
```

---

###  Problem:  
Given an array of integers, you have to **find the maximum XOR of any two numbers** in the array.

---

### Intuition Behind XOR:
1. **XOR** of two bits is `1` if they are different.
   - `0 ^ 1 = 1`, `1 ^ 0 = 1`
   - `0 ^ 0 = 0`, `1 ^ 1 = 0`

2. To **maximize XOR**, we want each bit to be as different as possible.
   - So, if we have `0`, we want to pair it with `1`.
   - If we have `1`, we want to pair it with `0`.

---

### Why Use Trie?
- A binary trie stores numbers bit by bit.
- It helps you quickly **find the best possible number** that gives max XOR with current number.

---

###  Step-by-Step Intuition:
1. **Build a Trie** from all numbers in the array.
   - Each number is inserted **bit by bit from 31st to 0th bit** (assuming 32-bit integers).
   - `left` child means bit `0`, `right` child means bit `1`.

2. **Search for best pair for each number**:
   - For every number, try to move opposite in the trie to get maximum XOR.
     - If current bit is `1`, try to move to `left` (bit `0`).
     - If current bit is `0`, try to move to `right` (bit `1`).
   - Accumulate the XOR value.

3. Keep track of the maximum XOR obtained during the process.

---

###  Dry Run Example:
Let's say the array is: `[3, 10, 5, 25, 2, 8]`

- Build trie of all numbers.
- For each number (say `10`), traverse trie to find the number that gives the highest XOR with `10`.

---

### Code Summary (Line-by-Line):
1. `struct trieNode { ... }`: Custom binary trie node.
2. First `for` loop:
   - Insert all numbers bit by bit into trie.
3. Second `for` loop:
   - For each number, try to go opposite bit path in trie for max XOR.
   - Use `1<<j` to add that bit's value to current XOR.
   - Update `finalmaXor` with max value.

---

###  Time Complexity:
- Inserting & checking each number takes **O(32)** (for 32 bits).
- So overall: **O(n × 32)** = **O(n)** in practice.

---
