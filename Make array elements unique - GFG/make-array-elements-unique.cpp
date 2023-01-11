//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
    map<long long int,long long int> dict;
    set<long long int> used;
 
    // Load Frequency Map (Element -> Count) and Used Set
    for (int x = 0; x < N; x++) {
        int i = arr[x];
        if (dict[i] != 0)
            dict[i]++;
        else {
            dict[i] = 1;
            used.insert(i);
        }
    }
 
    int maxUsed = 0; // Works for +ve numbers
    long long int ans = 0;
 
    for (auto entry : dict) {
 
        int value = entry.first;
        int freq = entry.second;
 
        if (freq <= 1) // If not a duplicate, skip
            continue;
 
        int duplicates
            = freq
              - 1; // Number of duplicates 1 less than count
 
        // Start with next best option for this duplicate:
        // CurNum + 1 or an earlier maximum number that has
        // been used
        int cur = max(value + 1, maxUsed);
        while (duplicates > 0) {
            if (used.find(cur) == used.end()) {
                ans += cur - value; // Number of increments
                                    // = Available Spot -
                                    // Duplicate Value
                used.insert(cur);
                duplicates--;
                maxUsed = cur;
            }
            cur++;
        }
    }
 
    // return answer
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends