//Approach 1
// Time Complexity: O(2^n*n)+O(NlogN)
// Space Complexity: O(1)

vector<int> subsetSum(vector<int> &nums)
{
    // Write your code here.
    int n=nums.size();
    vector<int>res;
    for(int num=0;num<pow(2,n);num++)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(num&(1<<i))
            {
                sum+=nums[i];
            }
        }
        res.push_back(sum);
    }
    sort(res.begin(),res.end());
    return res;
}

//Approach 2
// Time Complexity: O(2^N)+O(2^Nlog2^N)
// Space Complexity: O(1)

void helper(vector<int>&nums,int ind,int sum,vector<int>&res)
{
  if(ind==nums.size())
  {
      res.push_back(sum);
      return;
  }
  helper(nums,ind+1,sum+nums[ind],res);
  helper(nums,ind+1,sum,res);
}
vector<int> subsetSum(vector<int> &nums)
{
    // Write your code here.
    vector<int>res;
    helper(nums,0,0,res);
    sort(res.begin(),res.end());
    return res;
}