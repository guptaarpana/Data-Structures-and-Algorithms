//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void bfs(int node, vector<bool>& visited, vector<int>& ans, vector<int> adj[]) {
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto i: adj[temp]) {
                if(!visited[i]) {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        vector<int> ans;
        queue<int> q;
        //for(int i=0; i<V; i++) {
        //    if(!visited[i])
                bfs(0, visited, ans, adj);
        //}
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends