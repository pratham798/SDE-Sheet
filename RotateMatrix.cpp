// Approach 1
// Time Complexity O(n*n)
// Space Complexiity O(n*n)
 void rotate(vector<vector<int>>& matrix) 
    {
        vector<vector<int>>res=matrix;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][n-i-1]=res[i][j];
            }
        }
    }
// Approach 2
// Time Complexity O(n*n)+O(n*n)
// Space Complexiity O(1)

    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    