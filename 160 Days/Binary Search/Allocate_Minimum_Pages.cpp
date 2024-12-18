//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size(), start = 0, end = 0;
        for(auto x:arr){
            start = max(start,x); 
            // how start work :
            // Chalo isko aur simple karte hain:

            // Hum start ko array ke maximum value par isliye rakhte hain kyunki:

            // Har student ko kam se kam ek book lena zaroori hai.
            // Agar ek book ke pages (e.g., 50) hain, toh kisi student ko wo book lena hi padega.
            // Iska matlab hai ki maximum pages wali book ko to kisi ek student ko lena hi padega.
            // Agar start ko usse chhota rakhen, toh allocation impossible ho jayega, kyunki us book ko allocate karna allowed hi nahi hoga.
            // Isliye, start = max(arr) rakha jata hai, jo guarantee karta hai ki allocation shuru se valid rahe. 
            
            end += x;

            // Hum `end` ko array ke sum (total pages) ke barabar isliye rakhte hain kyunki:  

            // 1. Sabhi books ek hi student ko dene ka worst-case scenario ho sakta hai.  
            // 2. Is case me ek hi student ko sari books milengi, aur unke pages ka total `sum(arr)` hoga.  
            // 3. Isliye, maximum pages ka upper limit kabhi bhi `sum(arr)` se zyada nahi ho sakta.  
            // 4. Binary search me, hum is upper limit ko gradually kam karte hain jab tak minimum possible answer na mil jaye.  

            // Toh `end = sum(arr)` isliye rakha jata hai, kyunki yeh allocation ka **maximum possible limit** hai.
        }
        if(n<k) return -1; // agar student jyada hai or books kam hai tab to (at least one book wala condition fail ho jayega isiliye not possible case hai ye to return karege  -1) 

        int ans, stud_cnt;

        while(start<=end){
            stud_cnt = 1 ;
            //Hum `stud_cnt` ko `1` se isliye initialize karte hain kyunki:  

            // 1. Shuruaat me hum maan ke chalte hain ki **kam se kam ek student** to chahiye hi hoga books allocate karne ke liye.  
            // 2. Jaise-jaise books allocate hoti hain, hum check karte hain ki current total pages (`pages`) allowed limit (`mid`) se zyada ho rahe hain ya nahi.  
            // 3. Agar limit cross ho jaye, iska matlab hai ek naye student ki zarurat hai, toh hum `stud_cnt` ko badha dete hain.  
            // 4. Agar hum `stud_cnt = 0` se start karte, toh pehle student ka count hi galat ho jata.  

            // Toh **`stud_cnt = 1` isliye karte hain kyunki pehle student ko shuru se count karna zaroori hai.**
            int pages = 0; 
            int mid = start + (end-start)/2;    
            for(int i=0; i<n; i++){
                pages += arr[i];
                if(pages > mid) // mid = allowed pages
                {
                    stud_cnt++;
                    pages = arr[i];
                }

                // pages:
                // pages variable har student ke liye total pages ko track karta hai.
                // Shuruaat me, pages = 0 hota hai, kyunki koi book abhi assign nahi ki gayi.
                // Jaise hi hum ek book assign karte hain, uski pages pages me add hoti hain.
                // Agar pages ki total value allowed limit (mid) se zyada ho jati hai, toh iska matlab hai ki current student ko aur books nahi de sakte. Toh, hum naye student ki zarurat samajhte hain aur pages ko reset kar dete hain, taaki wo student next book se shuru kar sake.

                // stud_cnt:
                // stud_cnt number of students ko track karta hai.
                // Initial value: stud_cnt = 1, kyunki pehle student ko allocate karna hai.
                // Jaise hi pages limit exceed hoti hai (i.e., ek student ko zyada pages mil jaate hain), hum stud_cnt ko 1 se increase kar dete hain, matlab ek aur student ki zarurat hai.
            }
            if(stud_cnt <= k){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1 ;
3

            //if (stud_cnt <= k) ka matlab:
            // stud_cnt wo number hai of students jo humein chahiye books ko allocate karne ke liye, current mid pages ke limit ke saath.
            // k wo maximum students hain jo humare paas available hain.
            // Condition: Agar stud_cnt <= k, matlab hum jo pages ka limit (mid) choose kiye hain usme hum k ya usse kam students ke saath books allocate kar pa rahe hain. Matlab allocation possible hai.

            // Agar allocation possible hai (stud_cnt <= k)
            // ans = mid;
            // Hum mid ko answer ke roop mein set karte hain, kyunki yeh ek valid solution hai jisme maximum pages per student kam se kam hain.

            // end = mid - 1;
            // Ab hum mid ko kam karna chahte hain, taaki hum dekhein ki kya hum aur chhota mid choose kar sakte hain jisme abhi bhi valid allocation ho. Toh hum upper limit (end) ko mid - 1 set kar dete hain.

            // Agar allocation possible nahi hai (stud_cnt > k)
            // Agar humare paas k se zyada students chahiye, toh iska matlab hai ki jo mid humne choose kiya, wo bahut chhota tha aur hume pages ka limit badhana padega, taaki hum kam students ke saath allocation kar sakein.

            // start = mid + 1;
            // Hum lower limit (start) ko mid + 1 set karte hain, taaki hum higher mid value search kar sakein jo allocation ko possible bana sake.
        }
        return ans;

            //Jab stud_cnt <= k hota hai, iska matlab allocation possible hai, toh hum ans = mid set karte hain, kyunki yeh ek valid answer hai. Fir, hum end = mid - 1 karte hain taaki hum aur chhota mid try kar sakein aur minimum possible maximum pages find kar sakein.

            // Basically:

            // ans ko update karte hain jab valid solution milta hai.
            // Binary search continue karte hain taaki sabse chhota mid find kar sakein.
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends