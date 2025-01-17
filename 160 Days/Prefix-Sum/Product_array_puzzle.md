Problem : Product_array_puzzle

Here I solve with two Approaches.

*Approach 1*

```c++
vector<int> productExceptSelf(vector<int>& arr) {
        int left = 1,right =1,n = arr.size();
        vector<int>res(n,0);
        int zcnt=0,idx;
        long long ans = 1;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
            {
                zcnt++;
                idx = i;
            }
            else
                ans = ans*arr[i];
        }
        if(zcnt>1) return res;
        if(zcnt==1)
        {
            res[idx] = ans;
            return res;
        }
        else
        {
            for(int i=0;i<n ;i++)
                res[i] = ans/arr[i];
        }
        return res;
    }
```

Intution:
1. Traverse the array to compute:
    The total product of all non-zero elements.
    The count of zeros and the index where the zero exists.
2. Handle three cases:
    More than one zero: Return an array of zeros.
    Exactly one zero: Populate the zero's position with the total product; others remain zero.
    No zeros: Compute the result as total_product / arr[i] for each element.
    Return the resultant array.

Time Complexity: O(n)
Space Complexity: O(n)


*Approach 2*:
```c++
vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int>res(n);
        int left = 1,right =1;
        for(int i=0; i<n; i++)
        {
            res[i] = left;
            left = left*arr[i];
        }
        for(int i = n-1; i>=0; i--)
        {
            res[i] = right*res[i];
            right = right*arr[i];
        }
        return res;
    }
```

*Intution*

1.  Traverse the array from left to right:
    Maintain a left variable to store the cumulative product of elements to the left of the current index.
    Store this value in the result array.

2. Traverse the array from right to left:
    Maintain a right variable to store the cumulative product of elements to the right of the current index.
    Multiply this value with the value already stored in the result array.
    Return the result array.

Time Complexity: O(n)
Space Complexity: O(n)