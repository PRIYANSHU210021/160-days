// Problem : Count_All_Triplets_With_Given_Sum_In_Sorted_Array

*********** Approach 1st **************
First I solve this problem in TC: O(N*N) by Hashing

int countTriplets(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        mp[arr[i]]++;
        int cnt=0;
        for(int i=0; i<n-1; i++)
        {
            mp[arr[i]]--;
            for(int j=0; j<i; j++)
            {
                int target = k - (arr[i]+arr[j]);
                if(mp.find(target) != mp.end()) 
                {
                    cnt = cnt + mp[target];
                }
                
            }
        }
        return cnt;
    }




* Intution :
1. Pahle Simple hash krr liye sath me frequency hold krr liye unordered_map(mp) me.

2. Fir easy sa logic ye laga hai ki hmko koi triplet find karna hai to or hamare pas 2 element hai uss triplet me se to 3rd element to asani se nikal jayega like (triplet a=2, b=-3, c=? and target = 3) so (c = target - a - b -> c= 3-2+3=4)

3. Issi C ko hmm target naam diye ho code krte time.

4. Fir first loop ke just baad hmm mp[arr[i]]--; iska mtlb ki ye element arr[i] , arr[j] ke sath considered na ho, or jo freqency ho uss key ka usko unti bar use krr ke triplet bana skte hai isiliye uske frequency ko hmm cnt me add krr rhe hai.

5. Jab hum i ke liye loop chalate hain, iska matlab hai, arr[i] triplet ka second element hota hai.
j aur k ko aise select karte hain ki arr[j] triplet ka first element ho (aur j < i ho).
k triplet ka third element ho (aur k > i ho).


* Intution explained in English(chatgpt):

1. First, we create a simple hash and store the frequencies in an unordered map (mp).
- This step is efficient because the unordered map helps us store the elements and their frequencies. It allows us to quickly search for the third element of the triplet when we have two known elements.


2. The logic to find the third element is simple:
When we want to find a triplet and we already have two elements, the third element can be calculated easily.  
For example, if the triplet is `(a=2, b=-3)` and the target is `3`, we can find the third element `c` by calculating:  
c = target - a - b` → `c = 3 - 2 + 3 = 4`.  
This simplifies the process of finding the third element.


3. We call this third element `target` during coding:
- We use `target` to refer to the value that the third element should have in order to make the sum of the triplet equal to the given target.

4. After the first loop, we decrement the frequency of arr[i]
- The reason we do `mp[arr[i]]--;` is to ensure that the element `arr[i]` is no longer considered in future calculations for the triplet.  
- By decrementing the frequency, we make sure that this element isn’t reused when finding other triplets.
- The frequency of the element is added to the `cnt` because it tells us how many times this particular element can form a valid triplet with the previous elements.


5. When we run the loop for `i`, it means `arr[i]` is the second element of the triplet:
- We then select `j` and `k` in such a way that:
  arr[j] is the first element (and `j < i`),
  arr[k] is the third element (and `k > i`).



This is the overall approach you’re following to find and count the triplets that sum to a given target. The key idea is using the first two elements to calculate the third element and making sure that the indices satisfy the condition `i < j < k`.






*********** Approach 2nd **************
By Two Pointer

 int countTriplets(vector<int> &arr, int k) {
        int n = arr.size();
        int start,end,sum,cnt=0;
        for(int i=0; i<=n-3;i++)
        {
            start = i+1,end = n-1;
            while(start<end)
            {
                sum = arr[i]+arr[start]+arr[end];
                if(sum == k)
                {
                    cnt++;
                    int temp = start+1;
                    while(temp < end && arr[temp] == arr[temp-1])
                    {
                        cnt++;
                        temp++;
                    }
                    end--;
                }
                else if(sum>k) end--;
                else start++;
            }
        }
        return cnt;
    }


1.Fix the First Element:

We iterate through the array and, for each element (arr[i]), fix it as the first element of the triplet. This is done using an outer loop. The first element will be the i-th element, and we will find the other two elements in the triplet (i.e., arr[j] and arr[k]).

2.Use Two Pointers for the Other Two Elements:

For each fixed element arr[i], we use two pointers, start and end, to find the remaining two elements (arr[j] and arr[k]) such that their sum equals k - arr[i].
The start pointer is initialized to i + 1 (just after the fixed element), and the end pointer is initialized to the last element of the array.

3.Calculate the Sum:

At each step, calculate the sum of the current triplet: arr[i] + arr[start] + arr[end].
If the sum is equal to k, a valid triplet is found.

4.Count and Skip Duplicates:

// cnt++;
// int temp = start + 1;
// while(temp < end && arr[temp] == arr[temp - 1]) {
//     cnt++;
//     temp++;
// }
// end--;

When we find a valid triplet, we count it and then skip any duplicates of the start element (if the next element is the same as the current one). This ensures we dont count the same triplet multiple times.
After handling duplicates, we move the end pointer one step to the left to continue searching for new triplets.

5.Adjust Pointers Based on Sum:

If the sum is less than k, move the start pointer to the right to increase the sum (because the array is sorted).
If the sum is greater than k, move the end pointer to the left to decrease the sum.

6.Repeat for All Elements:

We repeat this process for every element in the array, treating each as the first element of a potential triplet, and checking for valid pairs using the two-pointer technique.

7.Return the Count:

After processing all elements, the total number of valid triplets is returned.

