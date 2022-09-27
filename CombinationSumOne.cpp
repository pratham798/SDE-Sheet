 // Time Complexity: O(2^target*k)
// Space Complexity: O(k*x)   
    
    vector<vector<int>>res;
    void helper(vector<int>&arr,int n,int ind,int target,vector<int>&ans,int sum)
    {
        if(sum==target)
        {
            res.push_back(ans);
            return;
        }
        if(ind==n || sum>target) return;
        ans.push_back(arr[ind]);
        helper(arr,n,ind,target,ans,sum+arr[ind]);
        ans.pop_back();
        helper(arr,n,ind+1,target,ans,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {
        vector<int>ans;
        helper(arr,arr.size(),0,target,ans,0);
        return res;
    }