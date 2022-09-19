//Approach 1
// Time Complexity: O(n^2)
// Space Complexity: O(1)

  int trap(vector<int>& heights) 
    {
      int res=0;
      for(int i=0;i<heights.size();i++)
      {
          int j=i;
          int left=0;
          while(j>=0)
          {
              left=max(left,heights[j]);
              j--;
          }
          int k=i;
          int right=0;
          while(k<heights.size())
          {
              right=max(right,heights[k]);
              k++;
          }
          int ans=min(left,right);
          res+=(ans-heights[i]);
      }
        return res;
    }

//Approach 2
// Time Complexity: O(3n)
// Space Complexity: O(2n)

 int trap(vector<int>& heights) 
    {
      int res=0;
      vector<int>left(heights.size());
      vector<int>right(heights.size());
      int sum=0;
      for(int i=0;i<heights.size();i++) 
      {
          sum=max(sum,heights[i]);
          left[i]=sum;
      }
      sum=0;
      for(int i=heights.size()-1;i>=0;i--) 
      {
          sum=max(sum,heights[i]);
          right[i]=sum;
      }
      for(int i=0;i<heights.size();i++)
      {
          int ans=min(left[i],right[i]);
          res+=(ans-heights[i]);
      }
        return res;
    }


//Approach 3
// Time Complexity: O(n)
// Space Complexity: O(1)

 int trap(vector<int>& arr) 
    {
        int l=0,r=arr.size()-1,lmax=arr[l],rmax=arr[r];
        int ans=0;
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(lmax<arr[l]) lmax=arr[l];
                else ans=ans+(lmax-arr[l]);
                l++;
            }
            else
            {
                if(rmax<arr[r]) rmax=arr[r]; 
                else ans=ans+(rmax-arr[r]);
                r--;
            }  

        }
        return ans;
    }