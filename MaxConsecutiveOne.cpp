 // Time Complexity: O(n)
// Space Complexity: O(1)
 int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int ans=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans=max(count,ans);
                count=0;
            }
            else count++;
        }
        ans=max(count,ans);
        return ans;
    }