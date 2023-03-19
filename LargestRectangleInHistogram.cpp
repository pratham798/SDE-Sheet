 //Time Complexity=O(N)
//Space Complexity=O(3N)

int largestRectangle(vector < int > & heights) {
   // Write your code here.
   stack<pair<int,int>>s1;
   vector<int>left(heights.size());
   for(int i=0;i<heights.size();i++)
   {
     int count=0;
     while(!s1.empty() and heights[i]<=s1.top().first)
     {
       count=count+1+s1.top().second;
       s1.pop();
     }
     s1.push({heights[i],count});
     left[i]=count;
   }
   stack<pair<int,int>>s2;
   vector<int>right(heights.size());
   for(int i=heights.size()-1;i>=0;i--)
   {
     int count=0;
     while(!s2.empty() and heights[i]<=s2.top().first)
     {
       count=count+1+s2.top().second;
       s2.pop();
     }
     s2.push({heights[i],count});
     right[i]=count;
   }
   int res=0;
   for(int i=0;i<heights.size();i++)
   {
     int len=1+left[i]+right[i];
     res=max(res,(len*heights[i]));
   }
   return res;
 }