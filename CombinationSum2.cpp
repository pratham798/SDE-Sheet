    //Approach 1
    // Time Complexity: O(2^n(klogx))
    // Space Complexity: O(2^n*k)   

    vector<vector<int>>res;
    set<vector<int>>s;
    void helper(vector<int>&arr,int ind,int target,vector<int>&ans)
    {
        if(target==0)
        {
            vector<int>check=ans;
            sort(check.begin(),check.end());
            if(s.find(check)==s.end())
            {
               res.push_back(check);
               s.insert(check);
            }
            return;
        }
        if(ind==arr.size() || target<0) return;
        ans.push_back(arr[ind]);
        helper(arr,ind+1,target-arr[ind],ans);
        ans.pop_back();
        helper(arr,ind+1,target,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
    {
        vector<int>ans;
        helper(arr,0,target,ans);
        return res;
    }


       //Approach 2
       // Time Complexity: O(2^n*k)+O(NlogN)
      // Space Complexity: O(2^n*k)  
       vector<vector<int>>res;
       void helper(vector<int>&arr,int ind,int target,vector<int>&ans)
       {
          if(target<0) return;
          if(target==0)
          {
              res.push_back(ans);
              return;
          }
           for(int i=ind;i<arr.size();i++)
           {
               if(ind!=i and arr[i]==arr[i-1]) continue;
               ans.push_back(arr[i]);
               helper(arr,i+1,target-arr[i],ans);
               ans.pop_back();
           }
       }
       vector<vector<int>> combinationSum2(vector<int>& arr, int target) 
       {
         vector<int>ans;
         sort(arr.begin(),arr.end());
         helper(arr,0,target,ans);
         return res;
       }