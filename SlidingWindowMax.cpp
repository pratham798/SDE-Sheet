//Time Complexity=O(N)
//Space Complexity=O(K)
  vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>res;
        deque<int>dq;
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
          if(i>=k)
          {
            res.push_back(dq.front());
            if(dq.front()==nums[prev++]) dq.pop_front();
          } 
          while(!dq.empty() and nums[i]>dq.back()) dq.pop_back();
          dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        return res;
    }