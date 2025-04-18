# Problem: Implement Trie
# Code: 

```c++
class Trie {
  public:
  
  struct trieNode {
      bool isLastChar;
      trieNode* childs[26];
  };
  
  trieNode* getNode(){
      trieNode* Node = new trieNode();
      Node->isLastChar= false;
      
      for(int i=0; i<26; i++)
      {
          Node->childs[i] = NULL;
      }
      return Node;
  }

     trieNode* root;
    Trie() {
        root = getNode();        
    }

    void insert(string &word) {
        trieNode* node = root;
        for(auto ch: word)
        {
            if(node->childs[ch-'a']==NULL)
            {
                node->childs[ch-'a'] = getNode();
            }
                node = node->childs[ch-'a'];
        }
        node->isLastChar = true;
    }

    bool search(string &word) {
         trieNode* node = root;
        for(auto ch: word)
        {
            if(node->childs[ch-'a']==NULL)
               return false;
            
            node = node->childs[ch-'a'];
        }
       if(node->isLastChar && node!=NULL) return true;
       return false;
       
    }

    bool isPrefix(string &word) {
        trieNode* node = root;
        int i;
        for(i =0 ;i<word.size(); i++)
        {
            int idx = word[i]-'a';
            if(node->childs[idx]==NULL)
               return false;
            node = node->childs[idx];
            
        }
       if(i == word.size()) return true;
    }
};
```

###  Intuition:

---

###  Structure of Trie Node:
Each node in the Trie represents a single character and stores:
- A flag `isLastChar` — tells us if this is the **end of a complete word**.
- An array of 26 pointers — each pointing to the next character (a–z). If a pointer is `NULL`, that character doesn't exist from this node.

---

###  `insert` function:
This function adds a word to the Trie.

Think of it like walking down a path:
- For each character, we check if that path (child node) exists.
- If not, we **create a new node**.
- Then we move forward (step into the next character).
- At the end of the word, we mark `isLastChar = true` to say: “Hey, this is a valid word endpoint.”

---

###  `search` function:
Here, we just try to walk through the Trie using each character of the word.
- If at any point the character path doesn’t exist → the word isn’t present.
- If we reach the end, and the node’s `isLastChar` is true → the word exists in the Trie.

Basically, we’re confirming both:
1. The **path exists**, and
2. It’s marked as the **end of a complete word**.

---

###  `isPrefix` function:
This is for checking **prefix existence**.
- We walk the path using each character like in `search`, but we **don’t care** if it’s a full word.
- As long as we can follow the characters to the end of the prefix → it exists.

So, even if `app` isn’t marked as a word, but `apple` exists, `isPrefix("app")` returns true.

---