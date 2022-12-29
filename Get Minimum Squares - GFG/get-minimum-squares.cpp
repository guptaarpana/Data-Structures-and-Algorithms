//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solveMem(int n, vector<int>& dp) { //base case
    if (n == 0)
        return 0;
    if(dp[n] != INT_MAX)
        return dp [n];
    int ans = n;
    for(int i=1; i*i <= n; i++) {
        int temp = i*i;
        ans = min(ans, 1+solveMem(n-temp, dp));
    }
        dp [n] = ans;
        return dp[n];
    }
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> dp(n+1, INT_MAX);
	    return solveMem(n,dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends