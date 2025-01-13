Problem: Container With Most Water


*Intution*: 
The idea is to use two pointers, one starting from the beginning (start) and the other from the end (end) of the array. These pointers represent the potential edges of a container where water can be trapped. The width between these pointers (end - start) represents the base of the container, and the minimum of the heights at these pointers (min(arr[start], arr[end])) represents the height of the container walls. The goal is to maximize the area of water that can be held between these two walls. I used two variables, left_max and right_max, to track the maximum heights dynamically. This reduced the space complexity to O(1) while keeping the time complexity at O(n).

TC: O(N)
SC: O(1)

*Code*: 
```c++
int maxWater(vector<int> &arr) {
        int n = arr.size();
        int start = 0, end = n-1,mx_ans=0,ans=0;
        int left_max=0,right_max=0;
        while(start<end)
        {
            left_max = max(left_max,arr[start]);
            right_max = max(right_max,arr[end]);
            
            if(arr[start]<arr[end])
            {
                ans = min(arr[start],arr[end])*(end-start);
                start++;
            }
            else
            {
                ans = min(arr[start],arr[end])*(end-start);
                end--;
            }
            mx_ans =  max(mx_ans,ans);
        }
        return mx_ans;
    }
```




*Approach*:
1. Two Pointers:
    • Use two pointers: start (left) and end (right).
    • Maintain two variables:
        • left_max (left maximum): The tallest block encountered so far from the left.
        • right_max (right maximum): The tallest block encountered so far from the right.

2. Most Water Calculation:
    • Compare the heights at the start and end pointers:
        • If the block at start is shorter (arr[start]≤arr[end]):
            • Update the ans from product of minimum of start element, end element and gap between them. 
            • Move the start pointer to the right.
        Otherwise:
            • Similarly for right side.
            • Move the end pointer to the left.

3. Store Max of right and left side by mx_ans variable:
        • And last return max one.







