// Approach 1
// Time Complexity: Exponential (int terms of power)
// Space Complexity: O(1)

int helper(int ind1,int ind2,int row,int col)
{
    if(ind1<0||ind1>=row||ind2<0||ind2>=col)
    {
        return 0;
    }
    if(ind1==0 and ind2==0) return 1;
    int a=helper(ind1,ind2-1,row,col);
    int b=helper(ind1-1,ind2,row,col);
    return a+b;
}
int uniquePaths(int m, int n) {
	// Write your code here.
    return helper(m-1,n-1,m,n);
}


// Approach 2
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

int helper(int ind1,int ind2,int row,int col,vector<vector<int>>&dp)
{
    if(ind1<0||ind1>=row||ind2<0||ind2>=col)
    {
        return 0;
    }
    if(ind1==0 and ind2==0) return 1;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    int a=helper(ind1,ind2-1,row,col,dp);
    int b=helper(ind1-1,ind2,row,col,dp);
    return dp[ind1][ind2]=a+b;
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    return helper(m-1,n-1,m,n,dp);
}
// Approach 3 (Combinatorics)
// Time Complexity: O(m-1) or O(n-1)
// Space Complexity: O(1)

int uniquePaths(int m, int n) {
	// Write your code here.
    int N=m+n-2;
    int r=m-1;
    int res=1;
    for(int i=1;i<=r;i++)
    {
        res=res*(N-i+1)/i;
    }
    return res;
}