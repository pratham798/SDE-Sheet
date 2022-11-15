  // Approach 1
  // Time Complexity: O(4^(m*n))
  // Space Complexity: O(m*n)
void helper(vector<vector<int>>&maze,int i,int j,int row,int col,vector<vector<int>>&res,vector<vector<int>>&ans)
{
    if(i==row||j==col||i<0||j<0||res[i][j]==1||maze[i][j]==0) return;
    res[i][j]=1;
    if(i==0 and j==0)
    {
        vector<int>temp;
        for(int x=0;x<row;x++)
        {
            for(int y=0;y<col;y++)
            {
                temp.push_back(res[x][y]);
            }
        }
        ans.push_back(temp);
        res[i][j]=0;
        return;
    }
    helper(maze,i-1,j,row,col,res,ans);
    helper(maze,i,j+1,row,col,res,ans);
    helper(maze,i,j-1,row,col,res,ans);
    helper(maze,i+1,j,row,col,res,ans);
    res[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
       vector<vector<int>>res(maze.size(),vector<int>(maze.size()+1,0));
       vector<vector<int>>ans;
       int i=0,j=0,row=maze.size(),col=maze[0].size();
       helper(maze,row-1,col-1,row,col,res,ans);
       return ans;
}

// Approach 2
// Time Complexity: O(4^(m*n))
// Space Complexity: O(m*n)

void helper(vector<vector<int>>&maze,int i,int j,int row,int col,vector<vector<int>>&res,
            vector<vector<int>>&ans,int di[],int dj[])
{
    if(i==row||j==col||i<0||j<0||res[i][j]==1||maze[i][j]==0) return;
    res[i][j]=1;
    if(i==0 and j==0)
    {
        vector<int>temp;
        for(int x=0;x<row;x++)
        {
            for(int y=0;y<col;y++)
            {
                temp.push_back(res[x][y]);
            }
        }
        ans.push_back(temp);
        res[i][j]=0;
        return;
    }
    for(int m=0;m<4;m++)
    {
        helper(maze,i+di[m],j+dj[m],row,col,res,ans,di,dj);   
    }
    res[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
       vector<vector<int>>res(maze.size(),vector<int>(maze.size()+1,0));
       vector<vector<int>>ans;
       int di[]={1,0,0,-1};
       int dj[]={0,1,-1,0};
       int i=0,j=0,row=maze.size(),col=maze[0].size();
       helper(maze,row-1,col-1,row,col,res,ans,di,dj);
       return ans;
}
