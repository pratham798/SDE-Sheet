   //Approach 1
  // Time Complexity: O(n*n)
  // Space Complexity: O(n*n)
    vector<vector<string>>ans;
    bool isSafe(vector<string>&chess,int row,int col)
    {
        for(int i=row;i>=0;i--)
        {
            if(chess[i][col]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 and j>=0;i--,j--)
        {
            if(chess[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 and j<chess[0].size();i--,j++)
        {
            if(chess[i][j]=='Q') return false;
        }
        return true;
    }
    void nQueen(vector<string>&chess,int row,int n)
    {
        if(row==n)
        {
          ans.push_back(chess);
          return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(chess,row,i))
            {
                chess[row][i]='Q';
                nQueen(chess,row+1,n);
                chess[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>chess(n,string(n,'.'));
        nQueen(chess,0,n);
        return ans;
    }

   //Approach 2
  // Time Complexity: O(n!*n)
  // Space Complexity: O(n)

      void nQueen(vector<string>&chess,int row,int n,vector<int>&up,vector<int>&leftD,vector<int>rightD)
    {
        if(row==n)
        {
          ans.push_back(chess);
          return;
        }
        for(int i=0;i<n;i++)
        {
            if(up[i]==0 and leftD[(n-1)+(i-row)]==0 and rightD[i+row]==0)
            {
                chess[row][i]='Q';
                up[i]=1;
                leftD[(n-1)+(i-row)]=1;
                rightD[i+row]=1;
                nQueen(chess,row+1,n,up,leftD,rightD);
                chess[row][i]='.';
                up[i]=0;
                leftD[(n-1)+(i-row)]=0;
                rightD[i+row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>chess(n,string(n,'.'));
        vector<int>up(n,0),leftD(2*n-1,0),rightD(2*n-1*0);
        nQueen(chess,0,n,up,leftD,rightD);
        return ans;
    }