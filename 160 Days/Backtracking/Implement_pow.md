Problem: Implement_pow:

By Performing Backtracking:

*Code*

```c++

class Solution {
  public:
    double solve(double b, int e)
    {
        if(e==0) return 1.0;
        
        double temp = solve(b,e/2);
        temp = temp*temp;
        if(e%2==0) 
        return temp;
        else
        return temp*b;
    }
    
    double power(double b, int e) {
        if(e<0) return 1.0/solve(b,-e);
        return solve(b,e);
    }
};

```




*Approach*

1. **Recursive Function (`solve`)**: It calculates `b^e` using **divide and conquer** by recursively halving the exponent `e`.  
2. **Base Case (`e == 0`)**: Returns `1.0` since any number raised to the power `0` is `1`.  
3. **Recursive Step**: Computes `solve(b, e/2)`, squares the result, and multiplies by `b` if `e` is odd.  
4. **Handling Negative Exponents**: If `e` is negative, compute `1 / solve(b, -e)`.  
5. **Optimized Approach**: Uses **O(log e) time complexity** by reducing exponent size in each step.