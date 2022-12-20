class three{
    public:
    int sum,ind1,ind2;
};
struct cmp
{
    bool operator()(three a,three b)
    {
        return a.sum<b.sum;
    }
};
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<three,vector<three>,cmp>pq;
    set<pair<int,int>>s;
    vector<int>ans;
    pq.push({a[n-1]+b[n-1],n-1,n-1});
    s.insert({n-1,n-1});
    while(ans.size()!=k)
    {
        int i=pq.top().ind1,j=pq.top().ind2,val=pq.top().sum;
        ans.push_back(val);
        pq.pop();
        if(j>0 and s.count({i,j-1})==0)
        {
            s.insert({i,j-1});
            pq.push({a[i]+b[j-1],i,j-1});
        }
        if(i>0 and s.count({i-1,j})==0)
        {
            s.insert({i-1,j});
            pq.push({a[i-1]+b[j],i-1,j});
         }
    }
    return ans;
}