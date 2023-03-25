// Time Complexity= O(N + 2E) + O(N)
//Space Complexity=O(3N)

void dfs(vector<vector<int>>&adj,vector<int>&visited,int curr,vector<int>&path)
{
    if(visited[curr]) return;
    visited[curr]=1;
    path.push_back(curr);
    for(auto&it:adj[curr])
    {
        if(!visited[it]) dfs(adj,visited,it,path);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>adj(V);
    vector<int>visited(V,0);
    vector<vector<int>>res;
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int>path;
            dfs(adj,visited,i,path);
            res.push_back(path);
        }
    }
    return res;
}