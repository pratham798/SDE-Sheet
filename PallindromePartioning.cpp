    // Time Complexity: O(2^n*n/2*k)
    // Space Complexity: O(x*k)   
    vector<vector<string>>res;
    bool isPal(string&s,int i1,int i2)
    {
        while(i1<=i2)
        {
            if(s[i1]!=s[i2])
            {
                return false;
            }
            i1++;
            i2--;
        }
        return true;
    }
    void helper(string&s,int i1,int i2,vector<string>&ans)
    {
        if(i2>=s.size()) 
        {
            if(i1==i2) res.push_back(ans);
            return;
        }
        if(isPal(s,i1,i2)) 
        {
            string a1=s.substr(i1,i2-i1+1);
            ans.push_back(a1);
            helper(s,i2+1,i2+1,ans);
            ans.pop_back();
        }
        helper(s,i1,i2+1,ans);
    }
    vector<vector<string>> partition(string s) 
    {
        vector<string>ans;
        helper(s,0,0,ans);
        return res;
    }