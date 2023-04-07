// Time Complexity:O(n*n)
// Space Complexity:O(n*n)

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int,int>>q;
    int res=0,count=0;
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!=0) count++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty())
    {
        int k=q.size();
        count-=k;
        while(k--)
        {
            int c1=q.front().first,c2=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int i1=c1+dx[i],i2=c2+dy[i];
                if(i1<0||i2<0||i1>=n||i2>=m||grid[i1][i2]!=1) continue;
                grid[i1][i2]=2;
                q.push({i1,i2});
            }
        }
        if(!q.empty())res++;
    }

    if(count==0) return res;
    return -1;
    
}