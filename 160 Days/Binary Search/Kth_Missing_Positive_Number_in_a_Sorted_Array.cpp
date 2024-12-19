// GFG SOLUTION

// NAIVE APPROACH (IN LINEAR TIME)

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        vector<int>v;
        int n = arr.size();
        int num = 1;
        int i = 0;
        while(i<n && k>0)
        {
            if(arr[i]!=num)
            {
            k--;
            }
            else
            {
                i++;
            }
                num++;
        }
        while(k--)
        num++;
        return num-1;
    }
};

// ******************************** README ******************************** 

// Initialization:

// Ek num variable banaya jiska initial value 1 hai, jo current number ko track karega.
// i array ke index ko track karega (initially 0).
// k missing numbers ka count decrement hote rahega jab tak hum "k-th" missing number tak na pahuch jayein.

// First Loop:

// Jab tak array ka index i < n aur k > 0 hai:
// Agar num aur arr[i] match nahi karte (matlab num missing hai), to k-- karte hain.
// Agar num aur arr[i] match karte hain, to i++ karte hain (array ke agle element par move karte hain).
// Har iteration ke baad num++ karte hain, taki agla number check kar saken.

// Second Loop (Post Array):

// Agar array traverse karne ke baad bhi k > 0 bacha hai, iska matlab remaining missing numbers array ke baad ke numbers mein hain.
// k baar num++ karte hain aur required missing number tak pahuchte hain.

// Return Statement:

// Last mein num-1 return karte hain, kyunki last increment ke baad num ek extra badh chuka hoga.

// Example Execution:
// Input: arr[] = [2, 3, 4, 7, 11], k = 5

// Step-by-Step:
// Initialization: num = 1, i = 0, k = 5.
// First Loop:
// num = 1, missing hai → k = 4.
// num = 2, match hai (arr[0]) → i = 1.
// num = 3, match hai (arr[1]) → i = 2.
// num = 4, match hai (arr[2]) → i = 3.
// num = 5, missing hai → k = 3.
// num = 6, missing hai → k = 2.
// num = 7, match hai (arr[3]) → i = 4.
// num = 8, missing hai → k = 1.
// num = 9, missing hai → k = 0.
// Output: 9.



// Key Points + Edge Case:
// Har step pe num increment karke check karte hain ki wo missing hai ya nahi.
// Array ke elements se match hone par index (i) badhate hain.
// Agar k ka value array ke elements ke baad bhi bacha ho, to direct missing numbers calculate karte hain.




// OPTIMAL APPROACH (IN LOGARITHMIC TIME)

// Yeh optimal approach binary search ka use karke missing numbers ka count efficiently find karte hue "k-th" missing number dhoondhti hai. Is approach ka time complexity linear se kam O(logn) tak reduce ho jata hai.

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
       int n = arr.size();
       int start = 0,end = n-1;
       while(start<=end)
       {
           int mid = start + (end - start)/2;
           // missing number = arr[mid] - (mid+1);
           if(arr[mid] - (mid+1) < k)
           start = mid+1;
           else
           end = mid-1;
       }
        return end + k +1;
    }
};

// ******************************** README ******************************** 
// Initialization:

// start = 0 aur end = n-1 (array ke start aur end indices ko track karte hain).
// Binary search use karke missing numbers ka count calculate karenge.

// Binary Search Logic:

    // Jab tak start <= end hota hai:
        // mid calculate karte hain:

                // mid=start+(end-start)/2

    // Missing numbers arr[mid] tak calculate karne ka formula hai:

    // missing=arr[mid]-(mid+1)

    // Ye formula kaise kaam karta hai:

        // arr[mid] actual number hai.
        // mid + 1 ideal number hota agar koi number missing na hota.
        // Difference missing numbers ka count deta hai.

    // Agar missing < k hai, iska matlab k-th missing number mid ke baad hoga, to start = mid + 1.
    // Agar missing >= k hai, iska matlab k-th missing number mid ke pehle ya wahi par hoga, to end = mid - 1.

// Final Calculation:

// Jab binary search khatam hoga, end last valid index hoga jahan tak missing numbers calculate hue hain.

// Missing numbers calculate karke required position find karte hain:

// result=end+k+1

