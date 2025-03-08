# Problem: Longest Palindrome in a String

# Code: 
```c++
class Solution {
  public:
    int solve_len(int l,int r, string s)
    {
        int len = 0;
        while(l>=0 && r<=s.size()){
            if(s[l--]==s[r++])
                len = len+2;
            else
            break;
        }
        return len;
    }
    string longestPalindrome(string &s) {
        int n = s.size();
        int mxlen =1;
        int start  = 0;
        
        for(int i=0;i<n; i++)
        {
            int len = 1+solve_len(i-1,i+1,s);
            if(len>mxlen)
            {
                mxlen = len;
                start = i-mxlen/2;
            }
            
        }
        for(int i=1; i<n; i++)
        {
            int len = solve_len(i-1,i,s);
            if(len>mxlen)
            {
                mxlen = len;
                start = i-mxlen/2;
            }
        }
        
        return s.substr(start,mxlen);
    }
};
```


### **1. Understanding the Nature of a Palindrome**
- A palindrome is a sequence that reads the same forward and backward.
- It can have either **odd length** (e.g., "racecar") or **even length** (e.g., "adda").
- Every palindrome has a **center**, and expanding outward from that center can help find the longest possible palindrome.

---

### **2. Expanding Around the Center**
- You observed that every character (or a pair of adjacent characters) can be a potential center of a palindrome.
- Instead of checking all substrings (which would be inefficient), you decided to **expand outward** from each center.

#### **`solve_len` Function**
- This function expands **from a given center** (left `l` and right `r`) and **counts how far it can go** while maintaining the palindrome condition.
- It increases the palindrome length as long as `s[l] == s[r]` and moves outward (`l--` and `r++`).

---

### **3. Finding the Longest Palindrome**
- You iterate over the string, treating each character as a potential **center** for an odd-length palindrome.
  ```cpp
  for(int i=0; i<n; i++)
  {
      int len = 1+solve_len(i-1,i+1,s);
      if(len>mxlen)
      {
          mxlen = len;
          start = i-mxlen/2;
      }
  }
  ```
  - Here, `solve_len(i-1, i+1, s)` expands around `i` to check for an **odd-length palindrome**.
  - If the palindrome is longer than the current `mxlen`, update the `start` index.

- Then, you iterate again, treating **adjacent pairs** as the center for even-length palindromes.
  ```cpp
  for(int i=1; i<n; i++)
  {
      int len = solve_len(i-1,i,s);
      if(len>mxlen)
      {
          mxlen = len;
          start = i-mxlen/2;
      }
  }
  ```
  - This checks for **even-length palindromes** using `solve_len(i-1, i, s)`, where `i-1` and `i` are the two middle characters.

---

### **4. Extracting the Longest Palindromic Substring**
- Once the longest palindrome is found, you extract it using:
  ```cpp
  return s.substr(start,mxlen);
  ```
  - `start` holds the beginning index of the palindrome.
  - `mxlen` stores its length.

---

- **Time Complexity:** **O(n²)**  
  - For each character, the `solve_len` function expands outward, which in the worst case takes **O(n)** time.  
  - Since this is done for each of the **n** characters, the total time complexity is **O(n²)**.  

- **Space Complexity:** **O(1)**  
