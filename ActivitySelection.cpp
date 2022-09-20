// Time Complexity: O(2N)+O(NlogN)
// Space Complexity: O(N*2)=O(N)

static bool comp(vector<int>&a, vector<int>&b)
{
    return a[1]<b[1];
}
int maximumActivities(vector<int>&start, vector<int>&finish) 
{
    // Write your code here.
    vector<vector<int>>time;
    for(int i=0;i<start.size();i++)
    {
        time.push_back({start[i],finish[i]});
    }
    sort(time.begin(),time.end(),comp);
    int end=time[0][1],res=1;
    for(int i=1;i<time.size();i++)
    {
        if(time[i][0]<end) continue;
        res++;
        end=time[i][1];
    }
    return res;   
}