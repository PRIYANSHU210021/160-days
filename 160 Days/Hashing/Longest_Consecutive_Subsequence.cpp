// Longest_Consecutive_Subsequence
TC: O(n)
SC: O(n) 

int longestConsecutive(vector<int>& arr) {
        vector<int>v(1000001,0);
        int n = arr.size();
        int mx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            v[arr[i]] = 1;
            mx = max(mx,arr[i]);
        }
        int ans = INT_MIN;
        int cnt = 0;
        for(int i=0; i<=mx; i++)
        {
            if(v[i])
            cnt++;
            else
            {
                // ans = max(cnt,ans);
                cnt = 0;
            }
                ans = max(cnt,ans);
        }
        return ans;
    }



readme:

Marking the Presence of Elements:
We use a vector<int> v(1000001, 0) to mark which elements are present in the array. The index of the vector represents the value of an element in the array, and we mark the value at that index as 1 if the element is present in arr.
For example, if arr[i] = 5, then we set v[5] = 1, which tells us that 5 exists in the array.
We also track the maximum element in the array (mx = max(mx, arr[i])) because we only need to check up to the maximum value to find the longest consecutive sequence.


Counting Consecutive Elements:
We initialize a variable cnt to keep track of the current length of a consecutive sequence.
We iterate through the vector v (from index 0 to mx), checking if the current index i is present in the array by checking if v[i] == 1.
If v[i] == 1, it means that i is part of a consecutive sequence, so we increment the cnt.
If v[i] == 0, it means that i is missing, and the sequence breaks. In this case, we reset cnt to 0, because the current consecutive sequence has ended.

Tracking the Longest Sequence:
Whenever we encounter a break in the sequence (v[i] == 0), we update the ans variable with the maximum of cnt and ans. This ensures that we always keep track of the longest consecutive sequence.
The cnt is reset to 0 after every break, as we're counting a new potential sequence.
After the loop finishes, we return the longest consecutive sequence found, which is stored in ans.
