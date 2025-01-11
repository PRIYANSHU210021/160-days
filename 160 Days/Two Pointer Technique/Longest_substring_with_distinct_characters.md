Problem: Longest_substring_with_distinct_characters

*Intution*: 

The intuition behind using an unordered map for finding the longest substring without repeating characters is to track 
the last occurrence index of each character. As we move the right pointer (j) through the string, if a duplicate 
character is found within the current window, we use the map to jump the left pointer (i) directly to the position after
the last occurrence of that character. This ensures the substring remains valid without duplicates.
By updating the map with the current position of each character and calculating the window size (j - i + 1) at each step,

TC: O(N)
SC: O(min(n,k)) (The map stores at most k entries where k is the size of the character set.)

```c++
int longestUniqueSubstr(string &s) {
        int n = s.size();
        int mx =0;
        int i=0,j=0;
        unordered_map<char,int>st;
       while(j<n)
        {
            while(st.find(s[j])!=st.end())
            {
                st.erase(s[i]);
                i++;
            }
            // lenght of substring = r-l+1;
            st[s[j]]++;
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }

```

*Approach*:

1. Expand the Window:
    • Traverse the string using the j pointer (right pointer).
    • For each character s[j], check if it exists in the map:
        • If it exists and its last occurrence is within the current window (mp[s[j]] >= i), adjust the left pointer i to mp[s[j]] + 1.
        • This ensures the window starts immediately after the last occurrence of the repeating character.

2. Update Map:
    Add or update the last occurrence index of the current character s[j] in the map as mp[s[j]] = j.
    
3. Update Maximum Length:
    • Calculate the length of the current window as j - i + 1.
    • Update mx as the maximum of its current value and the length of the current window.
    
4. Continue Until End:
    • Move the j pointer to the end of the string, ensuring all characters are processed.

5. Return the Result:
    • After the loop, mx will contain the length of the longest substring without repeating characters.
