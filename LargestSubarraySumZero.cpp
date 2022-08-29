// Approach 1
// Time Complexity: O(n^2)
// Space Complexity: O(1)
  int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int res=0;
        for(int i=0;i<n;i++)
        {
            int sum=A[i];
            if(A[i]==0) res=max(res,1);
            for(int j=i+1;j<n;j++)
            {
                sum+=A[j];
                if(sum==0)
                {
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
    }
// Approach 2
// Time Complexity: O(n)
// Space Complexity: O(n)

       int n=A.size();
       int res=0,sum=0;
        unordered_map<int,int>m;    
        for(int i=0;i<n;i++)
        {
           sum+=A[i];
           if(sum==0) res=max(res,i+1);
           else
           {
               if(m.find(sum)!=m.end())
               {
                   res=max(res,i-m[sum]);
               }
               else m[sum]=i;
           }
        }
        return res;