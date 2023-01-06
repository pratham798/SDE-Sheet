// Approach 1 (map+heap)
//Time Complexity: O(N)
//Space Complextiy: O(2N)

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    priority_queue<pair<int,int>>pq;
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++) m[arr[i]]++;
    for(auto&it:m) pq.push({it.second,it.first});
    vector<int>res;
    while(k--)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(),res.end());
    return res;
}