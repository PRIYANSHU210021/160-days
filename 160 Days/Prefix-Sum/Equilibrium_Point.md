Problem: Equilibrium Point

*Approach* 
Here Iam first computes the total sum of the array and iterates through each index to check if the left sum equals the right sum (calculated as total sum - left sum - current element). If an equilibrium point is found, it returns the index. The left sum is updated after each iteration. If no equilibrium point exists, it returns -1.


TC: O(N)
SC: O(1)

*Code*
``` c++
int findEquilibrium(vector<int> &arr) {
        int lsum = 0,sum=0;
        int n = arr.size();
        for(int i=0; i<n; i++)
            sum += arr[i];

        for(int i=0; i<n; i++)
        {
            if(lsum == sum - lsum- arr[i]) return i;
            lsum += arr[i];
        }
        return -1;
    }
```
*Intution*
1. Calculate Total Sum: The sum variable stores the total sum of all the elements in the array.
2. Iterate Through the Array:
    • For each element at index i, check if the left sum (lsum) equals the right sum.
    • The right sum is derived as sum - lsum - arr[i] because sum includes all elements.
3. Update Left Sum: Increment lsum with the current element after performing the check.
4. Return Result: If an equilibrium point is found, return the index. If not, return -1.