//Approach 1
// Time Complexity: O(n^2)
// Space Complexity: O(1)

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        int curr=0;
        for(int j=i;j<arr.size();j++)
        {
            curr=curr^arr[j];
            if(curr==x) count++;
        }
    }
    return count;
}

//Approach 2
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int,int>m;
    int count=0,curr=0;
    for(int i=0;i<arr.size();i++)
    {
        curr=curr^arr[i];
        if(curr==x) count++;
        int h=curr^x;
        if(m.find(h)!=m.end()) count+=m[h];
        m[curr]++;
    }
    return count;
}