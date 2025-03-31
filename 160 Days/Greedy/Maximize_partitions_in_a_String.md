# Problem: Maximize partitions in a String

# Code (Brute , Using Merge Intervals of first and last index)

```c++

class Solution {
  public:
    int maxPartitions(string &s) {
        int n = s.size();
        
        vector<pair<int,int>> ocur;
        unordered_map<char,pair<int,int>> mp;
        
        for(size_t i=0; i<s.length(); i++)
        {
            char ch = s[i];
            
            if(mp.find(ch) == mp.end()){
                mp[ch].first = i;
            }
            mp[ch].second = i;
        }
        
        for(auto x:mp)
        ocur.push_back(x.second);
        
        sort(ocur.begin(),ocur.end());
        
        int cnt = 0;
        int currMax = -1;
        for(int i=0; i<ocur.size(); i++)
        {
            int target = ocur[i].first;
            if(target < currMax)
            {
                cnt+=0;
            }
            else
            {
                cnt++;
            }
            currMax = max(currMax,ocur[i].second);
        }
        // for(auto x:ocur)
        // cout<<x.first<<x.second<<endl;
        return cnt;
    }
};
```


# Code (optimal , Greedy Concept)

```c++
class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size();
        vector<int>v(26,-1); // last index of char.
        for(int i=0; i<n; i++)
        {
            v[s[i]-'a'] = i; 
        }
        int cnt = 0;
        int currIdx = -1;
        for(int i=0; i<n; i++)
        {
            currIdx =  max(currIdx,v[s[i]-'a']);
            if(currIdx == i)
            {
                cnt++;
                currIdx = -1;
            }
        }
        
        return cnt;
        
    }
};

```


##  **Intuition**  

### **Step 1: Find the Last Occurrence of Each Character**  
Before making partitions, first, store the **last index** of every character in the string.  
This helps us know how far we must go before we can safely **cut** a partition.

Example:  
For `s = "abacbde"`  
- `'a'` last appears at index `2`  
- `'b'` last appears at index `4`  
- `'c'` last appears at index `3`  
- `'d'` last appears at index `5`  
- `'e'` last appears at index `6`  

Now, we have a **map** of where each character **must be included** in a partition.

---

### **Step 2: Iterate & Track the Maximum Boundary of the Current Partition**  
We scan the string again and maintain a variable `currIdx`, which tells us **how far we must extend the current partition**.

- If `currIdx == i`, it means:  
 **All characters in the current partition won’t appear in the future**, so we can safely **cut** here.  

 **Increment partition count** and start a new partition.

---

### **Example Walkthrough: "abacbde"**  

#### **1st Pass: Store Last Occurrences**  
| Character | Last Index |
|-----------|-----------|
| a         | 2         |
| b         | 4         |
| c         | 3         |
| d         | 5         |
| e         | 6         |

#### **2nd Pass: Partitioning the String**  

- `i = 0` → `'a'` → `currIdx = max(-1, 2) = 2`  
- `i = 1` → `'b'` → `currIdx = max(2, 4) = 4`  
- `i = 2` → `'a'` → `currIdx = max(4, 2) = 4`  
- `i = 3` → `'c'` → `currIdx = max(4, 3) = 4`  
- `i = 4` → `'b'` → `currIdx == i` → **Cut the partition!** (1st partition done)  

Now start a new partition:  
- `i = 5` → `'d'` → `currIdx = 5`  
- `i = 6` → `'e'` → `currIdx = 6` → **Cut the partition!** (2nd partition done)  

---

 **Total Partitions = 2**  





