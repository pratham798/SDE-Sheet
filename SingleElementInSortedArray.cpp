 //Time Complexity:O(logN)
 //Space Complexity:O(1)
 int singleNonDuplicate(vector<int>& nums) 
    {
       int start=0,end=nums.size()-2;
       while(start<=end)
       {
           int mid=(start+end)/2;
           if(mid%2==0)
           {
               if(nums[mid]==nums[mid+1]) start=mid+1;
               else end=mid-1;
           }
           else
           {
               if(nums[mid]==nums[mid+1]) end=mid-1;
               else start=mid+1;
           }
       }
       return nums[start];
    }