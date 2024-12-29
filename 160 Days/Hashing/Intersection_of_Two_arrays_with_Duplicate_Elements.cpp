// Intersection of Two arrays with Duplicate Elements
TC: O(a+b) // a size and b size
SC: O(mp+ans) // map and ans 

vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto x:a)
        mp[x] = 1;
        
        for(int i=0; i<n2; i++)
        {
            if(mp.find(b[i])!=mp.end())
            {
                ans.push_back(b[i]);
                mp.erase(b[i]);
            }
        }
        return ans;
    }


// ************************ readme *************************

* unordered_map<int, int> mp; : A map is created to store elements from array a.
    vector<int> ans; : This vector will hold the intersection (common elements) of arrays a and b.


* mp[x] = 1 Each element from a is added to the map mp with a value of 1. This ensures that all elements of a are     stored, and duplicates are automatically handled by the map.

* if(mp.find(b[i]) != mp.end()): This checks if the element from b exists in the map mp (i.e., if it is also in a).

* ans.push_back(b[i]);: If the element exists in mp, it means this element is common in both arrays, so it's added to the result vector ans.

* mp.erase(b[i]); After adding the element to ans, it is removed from the map. This ensures that we don't add the same element again, even if it appears multiple times in b.

* and last return ans, driven code is sort it that's it.

