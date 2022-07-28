// Optimized Approach
// Time Complexity: O(log(n*m))
// Space Complexity: O(1)
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int start=0,end=m-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(target==mat[mid][n-1]) return true;
        else if(target>mat[mid][n-1]) start=mid+1;
        else if(target<mat[mid][n-1] and target<mat[mid][0]) end=mid-1;
        else if(target<mat[mid][n-1] and target>mat[mid][0])
        {
            for(int i=0;i<n;i++)
            {
                if(target==mat[mid][i]) return true;
            }
            return false;
        }
    }
    return false;
}