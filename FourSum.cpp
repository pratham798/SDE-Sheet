// Approach 1
// Time Complexity: O(nlogn+n^3logn)
// Space Complexity: O(n) 
 
  vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        map<vector<int>,int>m;
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                { 
                    long long find=(long long)target-(long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                    if(binary_search(nums.begin()+k+1,nums.end(),find))
                    {
                      vector<int>ans;
                      ans.push_back(nums[i]);
                      ans.push_back(nums[j]);
                      ans.push_back(nums[k]);
                      ans.push_back(find);
                      if(m[ans]==0) res.push_back(ans);
                      m[ans]=1;
                    }
                }
            }
        }
        return res;
        }
 
// Approach 2
// Time Complexity: O(n^3)
// Space Complexity: O(1)

 vector<vector<int>> fourSum(vector<int>& arr, int target) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                   long long find=(long long)target-(long long)arr[i]-(long long)arr[j];
                   int start=j+1;
                   int end=arr.size()-1;
                   while(start<end)
                   {
                       if(arr[start]+arr[end]<find) start++;
                       else if(arr[start]+arr[end]>find) end--;
                       else
                       {
                          vector<int>ans(4,0);
                          ans[0]=arr[i];
                          ans[1]=arr[j];
                          ans[2]=arr[start];
                          ans[3]=arr[end];
                          res.push_back(ans);
                           
                          while(start<end and arr[start]==ans[2]) start++;
                          while(end>start and arr[end]==ans[3]) end--;
                       }
                   }
                   while(j+1<n and arr[j+1]==arr[j]) j++;
            }
            while(i+1<n and arr[i+1]==arr[i]) i++;
        }
        return res;
        }