//Approach 1
// Time Complexity: O(2^n)*O(KlogX)
// Space Complexity: O(2^N*k)+O(2^N*K)
set<vector<int>>s;
void helper(vector<int>&nums,int ind,vector<int>&res)
{
  if(ind==nums.size())
  {
     sort(res.begin(),res.end());
     s.insert(res);
     return;
  }
  res.push_back(nums[ind]);
  helper(nums,ind+1,res);
  res.pop_back();
  helper(nums,ind+1,res);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    // Write your code here.
    vector<int>res;
    helper(nums,0,res);
    vector<vector<int>>ans;
    for(auto&it:s)
    {
        ans.push_back(it);
    }
    return ans;
}

//Approach 2 
// Time Complexity: O(2^N*K)+O(NlogN)
// Space Complexity: O(2^N*K)
void helper(vector<int>&nums,int ind,vector<int>&res,vector<vector<int>>&ans)
{
  ans.push_back(res);
  for(int i=ind;i<nums.size();i++)
  {
      if(i!=ind and nums[i]==nums[i-1]) continue;
      else    
      {
          res.push_back(nums[i]);
          helper(nums,i+1,res,ans);
          res.pop_back();
      }
  }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
{
    // Write your code here.
    vector<int>res;
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    helper(nums,0,res,ans);
    return ans;
}