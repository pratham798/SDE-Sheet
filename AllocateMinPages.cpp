//Time Complexity: O(NlogN)
//Space Complexity: O(1)
bool isPossible(vector<int>&time,long long barrier,int n)
{
      long long books=0,count=0;
      for(int i=0;i<time.size();i++)
      {
          if(books+time[i]>barrier)
          {
              count+=1;
              books=time[i];
              if(books>barrier) return false;
           }
          else  books+=time[i];
       }
        if(count<n) return true;
        return false;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    if(n>m) return -1;
    long long start=time[0],end=0;
    for(auto&i:time)
    {
        end+=i;
        start=min(start,(long long)i);
    }
    while(start<=end)
    {
        long long mid=start+(end-start)/2;
        if(isPossible(time,mid,n)) end=mid-1;
        else start=mid+1;
    }
    return start;
}