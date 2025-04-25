# Prblem: Majority Element
# Code:
```c++
class Solution {
    static int majorityElement(int arr[]) {
       int cnt = 0, ele = -1;
       for(int num : arr)
       {
        if(num == ele || cnt == 0)
        {
            cnt += 1;
            ele = num;
        }
        else 
        cnt -=1;
       }
       cnt = 0;
       for(int x:arr)
       {
           if(ele==x)
           cnt++;
       }
         return cnt > (arr.length/2 )?  ele : -1;
    }
}
```


1. **Boyer-Moore Voting Algorithm (First Loop)**:
   - Iterate through the array.
   - Maintain a candidate element (`ele`) and a counter (`cnt`).
   - If the current number is the same as the candidate or the counter is zero, increment the counter and set the current number as the new candidate.
   - If the current number is different, decrement the counter.

2. **Validation (Second Loop)**:
   - After identifying a potential candidate, loop through the array again to count how many times the candidate appears.

3. **Final Check**:
   - If the count of the candidate is greater than half the length of the array (`cnt > arr.length / 2`), return the candidate.
   - Otherwise, return `-1` as there is no majority element.

### Time Complexity: O(n) (two linear scans of the array).