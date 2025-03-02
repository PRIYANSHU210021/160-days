# Problem: K Sized Subarray Maximum

# Code: 
```c++
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0; i<k; i++)
        {
            while(!dq.empty() && arr[dq.back()]<arr[i])
            dq.pop_back();
            dq.push_back(i);
        }
        int i = 1;
        int j = k;
        ans.push_back(arr[dq.front()]);
        while(j<arr.size())
        {
            while(!dq.empty() && arr[dq.back()]<arr[j])
                dq.pop_back();
            dq.push_back(j);
            
            int temp = dq.front();
            if(temp < i){
                dq.pop_front();
            }
            temp = dq.front();
            ans.push_back(arr[temp]);
            i++;
            j++;
        }
        return ans;
    }
};
```

---


### **1. Aaj ka problem thoda sa complex tha that's why Hindi Explanation😃**  

### **1. Deque ka use kyu kiya?**  
- Deque ek aisa data structure hai jo **front aur back dono se elements add/remove** karne allow karta hai.  
- Isme **hum indexes store karte hain**, values nahi, taki har ek window ka maximum efficiently track ho sake.  
- Deque ke **front** pe hamesha **sabse bada element ka index** hota hai jo current window ka max hoga.  

---

### **2. Pehle k elements process karna (Deque initialize karna)**  
- Pehle `k` elements traverse karte time:
  - Agar deque ke **back pe koi chhota element hai**, toh usko hata dete hain kyunki wo kabhi future window ka max nahi ban sakta.  
  - Phir **current index ko push karte hain** deque me.  
- Jab `k` elements process ho jate hain, toh deque ke **front pe max element ka index** hota hai jo pehli window ka answer hai.  

---

### **3. Window Slide karna (Remaining elements process karna)**  
- Ab `k` ke baad ke elements traverse karte hain aur har window ka max nikalte hain:  
  - **Back se** chhote elements ko remove karte hain kyunki naye element ke aane ke baad wo max banne ke layak nahi hain.  
  - Naya index **back me push** kar dete hain.  
  - **Front se** element remove karte hain agar wo window ke bahar chala gaya ho (`i se chhota ho gaya ho`).  
  - **Deque ke front ka element** hi current window ka max hoga, use answer array me store kar lete hain.  

---

### **4. Observations**  
- **Deque use karne se time complexity O(N) ho gayi**, warna brute-force approach O(N*k) hoti.  
- Har ek element sirf **ek baar insert aur ek baar remove ho raha hai**, isiliye ye efficient hai.  
- **Back se chhoti values hata rahe hain** taki sirf useful elements bache.  
- **Front se old values hata rahe hain** jo ab window ke andar nahi hain.  

---

### **Example Samjho**  
#### **Input:**  
`arr = [1, 3, -1, -3, 5, 3, 6, 7]`, `k = 3`  

| Index | Window | Deque (Indexes) | Max in Window |
|--------|--------|----------------|--------------|
| `0` | `[1]` | `[0]` | - |
| `1` | `[1, 3]` | `[1]` (pop 0, push 1) | - |
| `2` | `[1, 3, -1]` | `[1, 2]` | `3` |
| `3` | `[3, -1, -3]` | `[1, 2, 3]` | `3` |
| `4` | `[-1, -3, 5]` | `[4]` (pop 3,2,1) | `5` |
| `5` | `[-3, 5, 3]` | `[4,5]` | `5` |
| `6` | `[5, 3, 6]` | `[6]` (pop 5,4) | `6` |
| `7` | `[3, 6, 7]` | `[7]` (pop 6) | `7` |

#### **Output:** `[3, 3, 5, 5, 6, 7]`  

---
