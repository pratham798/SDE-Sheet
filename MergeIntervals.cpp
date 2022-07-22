
// Approach 1
// Time Complexity O(n*n)+O(nlogn)
// Space Complexiity O(n*n)
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>>res;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<intervals.size();i++)
    {
        int start=intervals[i][0],end=intervals[i][1];
        if(!res.empty())
        {
            if(start<=res[res.size()-1][1]) continue;
        }
        for(int j=i+1;j<intervals.size();j++)
        {
            if(intervals[j][0]<=end)
            {
                end=max(end,intervals[j][1]);
            }
        }
        end=max(end,intervals[i][1]);
        res.push_back({start,end});
    }
    return res;
}
// Approach 2
// Time Complexity O(n)+O(nlogn)
// Space Complexiity O(n*n)
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    if(intervals.size()==1) return intervals;
    vector<vector<int>>res;
    sort(intervals.begin(),intervals.end());
    int prev=0,start=0;
    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[start][1]<intervals[i][0])
        {
            res.push_back({intervals[prev][0],intervals[start][1]});
            prev=i;
            start=i;
        }
        if(i==intervals.size()-1)
        {
           res.push_back({intervals[prev][0],max(intervals[i][1],intervals[start][1])});
        }
        if(intervals[start][1]<intervals[i][1]) start=i;
    }
    return res;
}