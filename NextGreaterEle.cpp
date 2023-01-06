//Time Complexity: O(N)
//Space Complextiy: O(N)

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int>res(arr.size(),-1);
    stack<pair<int,int>>st;
    for(int i=0;i<arr.size();i++)
    {
        while(!st.empty() and st.top().first<arr[i])
        {
            res[st.top().second]=arr[i];
            st.pop();
        }
        st.push({arr[i],i});
    }
    return res;
}