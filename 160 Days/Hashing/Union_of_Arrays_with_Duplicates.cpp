// Union_of_Arrays_with_Duplicates

TC: O(N+M)
SC: O(N+M)

 int findUnion(vector<int>& a, vector<int>& b) {
        int ans = 0;
        unordered_map<int,int>mp;
        for(int x:a)
        {
            if(mp[x] == 0)
            ans++;
            mp[x]=1;
        }
        
        for(int x:b)
        {
            if(mp[x] == 0)
            ans++;
            mp[x]=1;
        }
        
        return ans;
        
    }

// *************** README ********************

1. For each element x in a:
    Check if mp[x] (the element's presence in the map) is 0 (not yet encountered).
    If true, increment ans because this is a new distinct element.
    Set mp[x] = 1 to mark that the element has now been processed.

2.  Similar to the first loop, traverse the array b and perform the same operations:
If the element is not already in the map, increment ans.
Add the element to the map by setting mp[x] = 1.

3. And Return ans , thats it.