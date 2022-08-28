// Approach 1
// Time Complexity: O(nlogn+n)=O(nlogn)
// Space Complexity: O(1)
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int count=1,res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-arr[i-1]>1)
        {
            res=max(res,count);
            count=1;
        }
        else if(arr[i-1]!=arr[i]) count++;
    }
    res=max(count,res);
    return res;
}
// Approach 2
// Time Complexity: O(n)
// Space Complexity: O(n)

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<int,int>m;
    for(auto&it:arr) m[it]++;
    int count=1,res=0;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        if(m.find(x-1)==m.end())
        {
            while(m.find(x+1)!=m.end())
            {
                count++;
                x+=1;
            }
            res=max(res,count);
            count=1;
        }
    }
    return res;
}