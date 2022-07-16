//APPROACH 1
// Time Complexity: O(N*M + N*M)
// Space Complexity: O(N)

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int>row(m+1,1);
    vector<int>col(n+1,1);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
               row[i]=0;
               col[j]=0;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(row[i]==0||col[j]==0) matrix[i][j]=0;
        }
    }
}

//APPROACH 2
// Time Complexity: O(2*(N*M)), as we are traversing two times in a matrix,
// Space Complexity: O(1).
 void setZeroes(vector<vector<int>>& matrix)
    {
      int m=matrix.size();
      int n=matrix[0].size();
      int col0=1;
      for(int i=0;i<m;i++)
      {
        if(matrix[i][0]==0) col0=0;
        for(int j=1;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
               matrix[i][0]=0;
               matrix[0][j]=0;
            }
        }
      }
      for(int i=m-1;i>=0;i--)
      {
          for(int j=n-1;j>=1;j--)
          {
              if(matrix[i][0]==0||matrix[0][j]==0) matrix[i][j]=0;
          }
          if(!col0) matrix[i][0]=0;
      }
    }