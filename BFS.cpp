// Time Complexity= O(N + 2E) + O(N)
//Space Complexity=O(N)+O(N)
vector<int> bfsOfGraph(int vertex, vector<int> adj[]) {
        // Code here
        vector<int>visited(vertex,0);
        vector<int>res;
        queue<int>q;
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto&it:adj[curr])
            {
              if (!visited[it]) {
                q.push(it);
                visited[it] = 1;
              }
            }
        }
        return res;
    }