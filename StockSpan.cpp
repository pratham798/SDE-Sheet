//Time Complexity=O(N)
//Space Complexity=O(N)
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>>st;
    vector<int>res;
    for(int i=0;i<price.size();i++)
    {
        int count=0;
        while(!st.empty() and price[i]>=st.top().first) 
        {
            count=count+st.top().second+1;
            st.pop();
        }
        st.push({price[i],count});
        res.push_back(1+count);
    }
    return res;
}