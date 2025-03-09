# Problem: Palindrome SubStrings

# Code: 

```c++
class Solution {
  public:
  void solve(int left,int right, string s,int &cnt)
  {
      int len = 0;
      while(left>=0 && right>=0)
      {
          if(s[left]==s[right])
          {
              left--;
              right++;
              len +=2;
              if(len>1)
              cnt++;
          }
          else
          break;
      }
  }
    int countPS(string &s) {
        int n = s.size();
        int mxlen = 1;
        int start= 0;
        int cnt= 0;
        for(int i=0; i<n; i++)
            solve(i-1,i+1,s,cnt);
        for(int i=1; i<n; i++)
           solve(i-1,i,s,cnt);
        return cnt;
    }
};
```


### **Thought Process (Intuition)**  

1️⃣ **Expand Around Center Approach:**  
   - You are considering **each character as a center** and expanding **left and right** to check if it forms a palindrome.  
   - **For odd-length palindromes:** `solve(i-1, i+1, s, cnt)`  
   - **For even-length palindromes:** `solve(i-1, i, s, cnt)`  

   🔹 **Example: Given string `"adda"`**  
   - `solve(1,2,"adda",cnt)` expands `"bb"`  
   - `solve(0,3,"adda",cnt)` expands `"adda"`  
   - This way, you are detecting palindromic substrings by expanding from the center.

2️⃣ **Tracking Palindromic Length:**  
   - You maintain a `len` variable to keep track of palindrome length.  
   - When `len > 1`, you **increase `cnt`**, meaning you count that palindrome.  
   - However, this logic **does not count single-character palindromes**, which might need a small adjustment.  

3️⃣ **Using Two Loops for Different Centers:**  
   - **First loop:** Expands around a single character (for odd-length palindromes).  
   - **Second loop:** Expands around two consecutive characters (for even-length palindromes).  

---
