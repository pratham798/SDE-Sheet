 // Approach 1
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
 vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>res;
        if(nums.size()<2) return res;
        vector<int>arr=nums;
        int n1,n2;
        sort(arr.begin(),arr.end());
        int left=0,right=arr.size()-1;
        while(left<right)
        {
            if(arr[left]+arr[right]==target) 
            {
                n1=arr[left];
                n2=arr[right];
                break;
            }
            else if(arr[left]+arr[right]>target) right--;
            else if(arr[left]+arr[right]<target) left++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==n1) res.emplace_back(i);
            else if(nums[i]==n2) res.emplace_back(i);
        }
        return res;
    }

// Approach 1
// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {

   	 if (mp.find(target - nums[i]) != mp.end()) {

   		 res.emplace_back(i);
   		 res.emplace_back(mp[target - nums[i]]);
   		 return res;
   	 }

   	 mp[nums[i]] = i;
    }

    return res;
}