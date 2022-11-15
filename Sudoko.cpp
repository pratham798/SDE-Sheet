  // Time Complexity: O(n!*n)
  // Space Complexity: O(9^(n^2))
 bool isSafe(vector<vector<char>>&board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c||board[row][i]==c) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    bool helper(vector<vector<char>>&board,int row,int col)
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1;k<=9;k++)
                    {
                        char c=(k+'0');
                        if(isSafe(board,i,j,c))
                        {
                            board[i][j]=c;
                            if(helper(board,row,col)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        int row=9,col=9;
        bool ans=helper(board,row,col);
        return;
    }