//Time Complexity: O(N)
//Space Complextiy: O(N)

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<pair<int,int>>st;
    vector<int>res(arr.size(),-1);
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() and st.top().first>arr[i])
        {
            res[st.top().second]=arr[i];
            st.pop();
        }
        st.push({arr[i],i});
    }
    return res;
}