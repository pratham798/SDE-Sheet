// Approach 1
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int>res;
    unordered_map<int,int>m;
    for(int&i:arr)
    {
        m[i]+=1;
    }
    for(auto&it:m)
    {
        if(it.second>arr.size()/3) 
        {
            res.push_back(it.first);
        }
    }
    return res;
}
// Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int e1=-1,e2=-1,c1=0,c2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(e1==arr[i]) c1++;
        else if(e2==arr[i]) c2++;
        else if(c1==0)
        {
            e1=arr[i];
            c1++;
        }
        else if(c2==0)
        {
            e2=arr[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1=c2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==e1) c1++;
        else if(arr[i]==e2) c2++;
    }
    vector<int>res;
    if(c1>arr.size()/3) res.push_back(e1);
    if(c2>arr.size()/3) res.push_back(e2);
    return res;
}