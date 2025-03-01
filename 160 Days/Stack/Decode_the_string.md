# Problem: Decode the string
```
Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
Note: The test cases are generated so that the length of the output string will never exceed 105 .

Examples:

Input: s = "1[b]"
Output: "b"
Explanation: "b" is present only one time.
Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation:
1. Inner substring “2[ca]” breakdown into “caca”.
2. Now, new string becomes “3[bcaca]”
3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.
``` 

# Code: 
```c++
class Solution {
  public:
    string decodedString(string &s) {
        stack<char>stk;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != ']')
            stk.push(s[i]);
            else
            {
                string word;
                while(!stk.empty() && stk.top()!='[')
                {
                    word.push_back(stk.top());
                    stk.pop();
                }
                reverse(word.begin(),word.end());
                
                stk.pop(); 
                string num;
                while(!stk.empty() && isdigit(stk.top()))
                {
                    num.push_back(stk.top());
                    stk.pop();
                }   
                reverse(num.begin(),num.end());
                int val = stoi(num);
                string samestr;
                
                for(int j=0; j<val; j++)
                    samestr.append(word);
                
                for(char ch : samestr)
                    stk.push(ch);
            }
        }
        string ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```


### **Step-by-Step Explanation**
#### **1. Using a Stack**
- The code uses a **stack** to process the string.
- The stack helps in handling **nested** structures like `"3[a2[c]]"`, where you need to decode `a2[c]` first.

#### **2. Iterating Through the String**
```cpp
for(int i=0; i<s.size(); i++) {
```
- The loop iterates through the entire string `s` character by character.

#### **3. Handling Different Characters**
##### **Case 1: Push Everything Except `]` into the Stack**
```cpp
if(s[i] != ']')
    stk.push(s[i]);
```
- If the current character is **not** a `]`, push it onto the stack.

##### **Case 2: When `]` is Found (Start Decoding)**
```cpp
else {
```
- When `]` is encountered, the **decoding process starts**.

---

### **Decoding the Encoded Substring**
#### **Step 1: Extract the Encoded Substring**
```cpp
string word;
while(!stk.empty() && stk.top() != '[') {
    word.push_back(stk.top());
    stk.pop();
}
reverse(word.begin(), word.end());
```
- Pop characters from the stack **until `[` is found**.
- Since characters are pushed in **reverse order**, we reverse `word` to get the correct substring.

#### **Step 2: Remove the `[`**
```cpp
stk.pop();
```
- Remove the opening bracket `[` from the stack.

#### **Step 3: Extract the Number (`k`)**
```cpp
string num;
while(!stk.empty() && isdigit(stk.top())) {
    num.push_back(stk.top());
    stk.pop();
}
reverse(num.begin(), num.end());
int val = stoi(num);
```
- Pop **digits** from the stack to get the number **`k`**.
- Since numbers are pushed in reverse order, we **reverse** the string `num`.
- Convert it to an **integer (`val`)** using `stoi()`.

#### **Step 4: Repeat the Decoded String `k` Times**
```cpp
string samestr;
for(int j=0; j<val; j++)
    samestr.append(word);
```
- Append `word` **`val` times** to `samestr`.

#### **Step 5: Push the Expanded String Back into the Stack**
```cpp
for(char ch : samestr)
    stk.push(ch);
```
- Each character of `samestr` is pushed back into the stack.

---

### **Constructing the Final Answer**
```cpp
string ans;
while(!stk.empty()) {
    ans.push_back(stk.top());
    stk.pop();
}
reverse(ans.begin(), ans.end());
return ans;
```
- Pop all characters from the stack and **reverse** them to get the final decoded string.

---

### **Dry Run Example**
#### **Example 1:**
**Input:**  
`s = "3[a]2[bc]"`

**Step 1: Pushing Characters into Stack**
```
Stack after processing "3[a]":
Stack = ['3', '[', 'a', ']']

Stack after processing "2[bc]":
Stack = ['a', 'a', 'a', 'b', 'c', 'b', 'c']
```

**Step 2: Extracting and Repeating**
- `"a"` repeated **3 times** → `"aaa"`
- `"bc"` repeated **2 times** → `"bcbc"`

**Final Output:**  
`"aaabcbc"`

---

### **Time and Space Complexity**
- **Time Complexity:** \(O(N)\) (Each character is pushed and popped once)
- **Space Complexity:** \(O(N)\) (Stack stores characters)

