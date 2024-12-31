// Longest_Consecutive_Subsequence
TC: O(nlogn)
SC: O(n) 

int longestConsecutive(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
    
        for(int x : arr){
            if(mp.find(x-1) != mp.end()) 
                mp[x]= mp[x-1]+1;
            else
                mp[x] = 1;
        }
        int ans = 0;
        for(auto x : mp){
            ans = max(ans,x.second);
        }
        return ans;
    }

Sort the Array:

First, the array arr[] is sorted to bring any consecutive integers together.
Sorting helps in easily identifying consecutive sequences in the next step.

An unordered map (mp) is used to store the length of the longest consecutive subsequence ending at each element.
The key is the integer, and the value is the length of the consecutive subsequence ending at that key.

For each element x in the sorted array:
If x-1 exists in the map (mp.find(x-1)), it means x can extend the subsequence ending at x-1. So, update the length of the subsequence at x by adding 1 to the length at x-1.
If x-1 is not found, it means x starts a new subsequence, so set mp[x] = 1.

After processing all elements, iterate through the map mp to find the maximum value (the longest subsequence length).