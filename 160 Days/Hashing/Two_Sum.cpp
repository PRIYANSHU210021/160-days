// As you known about Naive Approah which perform in n^2 complexity 

// Lets Jump On Optimal Way:

// kyoki unordered map hamara hashing concept pe kaam krta hai to find operation me O(1) avg TC hota hai or map me hi tree ke concept pe kaam krta hai to ye hamara O(log n) avg case deta hai insert , find jaise functions pe , that's why iam using unordered map here

bool twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> mp; // Hash map to store numbers and their indices
    for (int i = 0; i < arr.size(); i++) { // Iterate through the array
        if (mp.find(target - arr[i]) != mp.end()) 
            return true; // Pair found, return true
        mp[arr[i]] = i; // Store the current number with its index in the map
    }
    return false; // No pair found, return false
}


// ************************* readme ************************
// 1. Hash Map (unordered_map) Banaya:
// Yeh mp banate hain jo numbers ko as key aur unke indices ko as value store karega.

// 2. Loop Shuru Kiya (for loop):
// Array ke har element par iterate karenge.

// 3. Check for Complement (target - arr[i]):
// Har element arr[i] ke liye target - arr[i] (complement) calculate karte hain.
// Agar complement hash map mp mein mil gaya, iska matlab ek aisa pair hai jiska sum target ke barabar hai, aur true return karte hain.

// Agar complement nahi mila, toh current number arr[i] aur uska index i hash map mp mein store karte hain future lookups ke liye.

// 4. Agar loop ke baad bhi koi pair nahi mila jo target ke barabar ho, toh false return karte hain.



