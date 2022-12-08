class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Calculate indegree
	    vector<int>inorder(V,0);
	    vector<int>res;
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            inorder[it]++;
	        }
	    }
        
       // Push nodes with indegree 0 into queue
	   queue<int>q;
	   	 for(int i=0;i<V;i++){
	        if(inorder[i]==0){
	            q.push(i);
	        }
	    }
	    
	    // Perform BFS
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        res.push_back(node);
	        // Decrement indegree for the neighbours
	        for(auto it : adj[node]){
	            inorder[it]--;
	            if(inorder[it]==0) q.push(it);
	        }
	    }
	    return res;
	}
};
