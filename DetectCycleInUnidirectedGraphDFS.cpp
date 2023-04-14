//Time Complexity: O(V+E)
//Space Complextiy: O(N)

bool dfs(vector<vector<int>>&adj,vector<int>&visited,int curr,int par)
{
  visited[curr]=1;
  for(auto&it:adj[curr])
  {
    if(visited[it] and it!=par) return true;
    else if(!visited[it] and dfs(adj,visited,it,curr)) return true;
  }
  return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1,0);
    for(auto&it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(adj,visited,i,-1)) return "Yes";
        }
    }
    return "No";
    
}