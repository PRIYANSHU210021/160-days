Problem: Count_distinct_elements_in_every_window

*Intution*: 
In this question, I am using the two-pointer technique. First, I take the first k elements of the array and add them to a map to track their frequencies. While adding each element, I check if its frequency is 0, which means the element is appearing in the map for the first time. If so, I increment the count, which represents the number of distinct elements in the current window, and push this count into a result vector. After that, I traverse the remaining part of the array starting from the k-th element (denoted by j in the code). For each element, I check if it is occurring for the first time and increase the count accordingly. I also use another pointer i, initialized to zero, to keep track of the first element of the previous window. The pointer i decreases the frequency of this element since it is no longer part of the current window. If its frequency becomes 0, it means the element is no longer present in any window, so I decrease the count. Then, I push this updated count into the result vector. Finally, I keep incrementing j to process the rest of the array and return the result at the end.


TC: O(N)
SC: O(N)

*Code*: 
```c++
vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        vector<int>res;
        int j=0;
        int cnt =0;
        while(j<k)
        {
            if(mp[arr[j]]==0) cnt++;
            mp[arr[j]]++;
            j++;
        }
        res.push_back(cnt);
        
        int i=0;
        while(j<n)
        {
            if(mp[arr[j]] == 0) cnt++;
            mp[arr[j]]++;
            mp[arr[i]]--;
            if(mp[arr[i]]==0) cnt--;
            res.push_back(cnt);
            i++;
            j++;
        }
        return res;
    }
```

*Approach*:
1. First Window:
    Process the first k elements, adding them to the hashmap while counting distinct elements (cnt).
    Push the distinct count into the result vector.

2. Sliding the Window:
    For the remaining elements, slide the window by:
        Adding the next element (j) to the hashmap. If it appears for the first time, increment cnt.
        Removing the first element of the previous window (i) by reducing its frequency. If its frequency becomes 0, decrement cnt.
    Push the updated cnt into the result vector after each step.

3.  Result:
    Return the result vector containing distinct counts for all windows.

