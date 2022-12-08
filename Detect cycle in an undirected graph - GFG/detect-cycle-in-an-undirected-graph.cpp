//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.

    bool solveBFS(int i, vector<int> adj[], vector<int> parent, vector<bool>& visited) {
        queue<int> q;
        q.push(i);
        parent[i]=-1;
        visited[i]=true;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            for(int j: adj[temp]) {
                if(visited[j]==true && parent[temp]!=j)
                    return true;
                else if(!visited[j]) {
                    q.push(j);
                    visited[j]=true;
                    parent[j]=temp;
                }
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool ans=false;
        vector<bool> visited(V,false);
        vector<int> parent(V);
        for(int i=0;i<V;i++) {
            if(!visited[i]) {
                ans=solveBFS(i,adj,parent,visited);
                if(ans==1)
                    return true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends