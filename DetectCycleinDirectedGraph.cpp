//Time Complexity: O(V+E)
//Space Complextiy: O(N)+O(N)

bool dfs(vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathVis,int curr)
{
  visited[curr]=1;
  pathVis[curr]=1;
  for(auto&it:adj[curr])
  {
    if(visited[it]==1 and pathVis[it] == 1) return true;
    else if(dfs(adj,visited,pathVis,it)) return true;
  }
  pathVis[curr]=0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>>adj(n+1);
  vector<int>visited(n+1,0);
  vector<int>pathVis(n+1,0);
  for(auto&it:edges)
  {
    adj[it.first].push_back(it.second);
  }
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      if(dfs(adj,visited,pathVis,i)) return 1;
    }
  }
  return 0;
}