Problem: Sum_Pair_closest_to_target

1st Approach (TC: O(nlogn) & SC: O(n))

Intution: 
In today's POTD (Problem of the Day), we basically needed to find the pair of numbers whose sum is closest to the target.
If there are multiple such pairs, we return the pair with the maximum absolute difference. It's clear from the problem
that the two-pointer technique will work here, but the twist lies in how to implement both the closest sum and the
 absolute difference conditions.

So, first, I sorted the array. If the array size is 1, I directly returned an empty result. Otherwise, using the
two-pointer approach, I calculated the sum of the current pair and subtracted it from the target to get the new_diff.
If this new_diff is smaller than the current diff, I updated the vector by clearing it and pushing the new pair.
If it’s equal, I just added the new pair to the vector. After this, I ran a loop to find the pair with the maximum
absolute difference and returned it.

Later, I optimized the solution by solving the same problem without using extra space. In this version,
I calculated both the closest pair and the maximum absolute difference simultaneously, eliminating the
need for the extra vector. That’s it!

```c++
vector<int> sumClosest(vector<int>& arr, int target) {
       sort(arr.begin(),arr.end());
       int n = arr.size();
       int start =0,end=n-1;
       int diff = INT_MAX,  new_diff,  a,b;
        vector<pair<int,int>>res;
        if(n==1) return {};
       while(start<end)
       {
            new_diff = abs(target-(arr[start]+arr[end]));
            if(new_diff < diff)
            {
                res.clear();
                res.push_back({arr[start],arr[end]});
                diff = new_diff;
            }
           if(arr[start]+arr[end] < target) start++;
           else end--;
       }
       int abs_diff = INT_MIN;
       int x;
       if(res.size() == 1)
           return {res[0].first,res[0].second};
       else{
           for(int i=0; i<res.size(); i++)
           {
               x = abs(res[i].first-res[i].second);
               if(abs_diff < x)
               {
                   a = res[i].first, b = res[i].second, abs_diff = x;
               }
           }
       }
       return {a,b};
    }
```

2nd Approach (TC: O(nlogn) & SC: O(1))

Key Changes in This Approach:
    1. No res vector is used, so space for storing candidate pairs is eliminated.
    2. Constant space is used to store:
        • a and b (the best pair found so far).
        • Integers for the closest difference (diff) and maximum absolute difference (abs_diff).
```c++
vector<int> sumClosest(vector<int>& arr, int target) {
       sort(arr.begin(),arr.end());
       int n = arr.size();
       int start =0,end=n-1;
       int diff = INT_MAX, abs_diff=INT_MIN,  new_diff,  a,b;
        if(n==1) return {};
       while(start<end)
       {
           int sum = arr[start]+arr[end];
           new_diff = abs(target - sum);
           
            if(new_diff < diff || (new_diff==diff && abs(arr[start]-arr[end])>abs_diff)) 
            {
                diff = new_diff;
                abs_diff = abs(arr[start]-arr[end]);
                a = arr[start];
                b = arr[end];
            };
            
           if(sum < target) start++;
           else end--;
       }
       return {a,b};
    }
```
    Intution Update:
Key Variables:
1. new_diff:
    The absolute difference between the target and the sum of the current pair:
    new_diff=∣target−(arr[start]+arr[end])∣

2. diff:
    The smallest difference encountered so far.

3. abs(arr[start] - arr[end]):
    The absolute difference between the two numbers in the current pair. This ensures we maximize the difference between 
    a and b when sums are equally close.

4. abs_diff:
The largest absolute difference between a and b for pairs with the same smallest difference.

