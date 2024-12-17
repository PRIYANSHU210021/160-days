//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k){
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int start = 0, end = stalls[n-1] - stalls[0], ans;
        while(start <= end)
        {
            int pos = stalls[0], cnt = 1, mid = start + (end-start)/2;
            for(int i=1; i<n; i++)
            {
                if(pos + mid <= stalls[i])
                {
                   cnt++;
                   pos = stalls[i];
                }
            }
            if(cnt < k)
                end = mid-1;
            else
            {
                start = mid+1;
                ans = mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends