class Solution {
  public:
   bool hasCycleBFS(vector<int> adj[],unordered_map<int,bool>& mp,int i)
   {
       queue<int> q;
       q.push(i);
       mp[i]=true;
       
       unordered_map<int,int> p;
       p[i]=-1;
       
       while(!q.empty())
       {
           int x=q.front();
           q.pop();
           
           for(auto it : adj[x])
           {
              if(mp[it]==true && p[x]!=it)
               {
                      return true;
               }
            
              else if(mp[it]==false)
              {
                  mp[it]=true;
                  q.push(it);
                  p[it]=x;
              }
           }
       }
   }
    bool hasCycleDFS(vector<int> adj[],unordered_map<int,bool>& mp,int i,int p)
    {
        mp[i]=true;
        
        for(auto it : adj[i])
        {
            if(mp[it]!=true)
            {
                bool res=hasCycleDFS(adj,mp,it,i);
                if(res==true)
                return true;
            }
            else if(mp[it]==true && it!=p)
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
          unordered_map<int,bool> mp;
          
          int i;
        for(i=0; i<V; i++)
        {
            if(mp[i]!=true)
            {
                bool res=hasCycleBFS(adj,mp,i);
                if(res==true)
                return true;
            }
        }
        return false;
        
        
    }
};
