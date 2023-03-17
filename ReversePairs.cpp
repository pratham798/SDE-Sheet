//Time Complexity=O(NlogN)+O(N)+O(N)
//Space Complexity=O(N)

int merge(int start,int mid,int end,vector<int>&nums)
    {
        int size=end-start+1,i=start,j=mid+1,k=0,res=0;
        int n=mid+1;
        for(int m=start;m<=mid;m++)
        {
            while(n<=end and nums[m]>(2*(long long)nums[n])) n++;
            res+=(n-(mid+1));
        }
        vector<int>ans(size);
        while(i<=mid and j<=end) ans[k++]=nums[i]<=nums[j]?nums[i++]:nums[j++];
        while(i<=mid) ans[k++]=nums[i++];
        while(j<=end) ans[k++]=nums[j++];
        for(int i=0;i<size;i++) nums[start+i]=ans[i];
        return res;
    }
    int helper(vector<int>&nums,int start,int end)
    {
        if(start>=end) return 0;
        int count=0;
        int mid=(start+end)/2;
        count+=helper(nums,start,mid);
        count+=helper(nums,mid+1,end);
        count+=merge(start,mid,end,nums);   
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }