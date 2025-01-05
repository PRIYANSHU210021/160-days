Problem : Count_Pairs_Whose_Sum_Is_Less_Than_Target

TC: O(nlogn)
SC: O(1)

In this question , count pairs whose sum is less than the target, first sort the array. Then, use two pointers: one starting at the beginning (start) and the other at the end (end). Check the sum of the numbers at these two pointers. 
If the sum is less than the target, it means all pairs between start and end are valid because the array is sorted. Add these pairs to the count and move the start pointer forward.
If the sum is greater than or equal to the target, move the end pointer backward to try smaller numbers.

int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int n =arr.size();
        int cnt=0; //2 3 5 7
        int start =0,end=n-1;
        while(start <end)
        {
            if((arr[start]+arr[end])<target)
            {
                int possible_pair = end-start;
                cnt += possible_pair;
                start++;
            }
            else end--;
        }
        return cnt;
    }


Intution:

Sorting the Array:
    Sorting helps ensure that smaller elements are handled first, allowing the two-pointer approach to work efficiently.

Two Pointers:
    Use two variables (start and end) as pointers:
        start begins at the start of the array.
        end begins at the end of the array.
    Check the sum of the elements at start and end.
    
Counting Pairs:
    If the sum of arr[start] and arr[end] is less than the target:
        All pairs between start and end are valid because the array is sorted.
        Count these pairs (end - start) and move start forward. // key point in this question
    If the sum is greater than or equal to the target:
        Move end backward to reduce the sum.



