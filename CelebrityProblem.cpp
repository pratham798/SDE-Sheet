 //Time Complexity=O(N)
//Space Complexity=O(N)
 
 bool knows(int a,int b,vector<vector<int>>&M)
    {
        if(M[a][b]==1) return false;
        return true;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>st;
    	for(int i=0;i<n;i++) st.push(i);
    	
    	while(st.size()>1)
    	{
    	    int a=st.top();
    	    st.pop();
    	    int b=st.top();
    	    st.pop();
    	    if(knows(a,b,M)) st.push(a);
    	    else st.push(b);
    	}
    	int res=st.top();
    	for(int i=0;i<M.size();i++) if(M[res][i]==1) return -1;
    	for(int i=0;i<M[0].size();i++) if(i!=res and M[i][res]==0) return -1;
    	return res;