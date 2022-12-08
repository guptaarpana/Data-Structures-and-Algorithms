//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        //Calculate indegree
	    vector<int>inorder(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            inorder[it]++;
	        }
	    }
        
       // Push nodes with indegree 0 into queue
	   int cnt=0;
	   queue<int>q;
	   	 for(int i=0;i<V;i++){
	        if(inorder[i]==0){
	            q.push(i);
	        }
	    }
	    // Perform BFS
	    while(!q.empty()){
	        cnt++;
	        int node=q.front();
	        q.pop();
	        // Decrement indegree for the neighbours
	        for(auto it : adj[node]){
	            inorder[it]--;
	            if(inorder[it]==0) q.push(it);
	        }
	    }
	    return (cnt!=V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends