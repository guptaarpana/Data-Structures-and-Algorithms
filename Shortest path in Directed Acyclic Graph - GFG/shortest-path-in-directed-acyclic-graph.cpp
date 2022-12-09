//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int i, vector<bool>& visited, map<int, vector<pair<int,int>>> adj, stack<int>& s) {
        visited[i]=true;
        for(auto j: adj[i]) {
            if(!visited[j.first])
                dfs(j.first, visited, adj, s);
        }
        s.push(i);
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        map<int, vector<pair<int,int>>> adj;
        for(int i=0;i<M;i++) {
            pair<int,int> p=make_pair(edges[i][1],edges[i][2]); 
            adj[edges[i][0]].push_back(p);
        }
        vector<bool> visited(N, false);
        stack<int> s;
        for(int i=0;i<N;i++) {
            if(!visited[i])
                dfs(i, visited, adj, s);
        }
        vector<int> dist(N, INT_MAX);
        dist[0]=0;
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            if(dist[top]!=INT_MAX) {
                for(auto i: adj[top]) {
                    if(dist[i.first]>dist[top]+i.second) {
                        dist[i.first]=dist[top]+i.second;
                    }
                }
            }
        }
        for(int i=0;i<dist.size();i++) {
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends