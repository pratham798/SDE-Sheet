string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>>adj(n+1);
    vector<int>visited(n+1,0),path(n+1);
    for(auto&it:edges) 
    {
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    for(int i=1;i<=n;i++)
    {
      if(!visited[i]){
        queue<pair<int,int>>q;
        q.push({i,-1});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            visited[x]=1;
            q.pop();
            for(auto&it:adj[x])
            {
                if(visited[it] and it!=y) return "Yes";
                if(!visited[it])
                  q.push({it, x});
            }
        }
      }
    }
    return "No";

}