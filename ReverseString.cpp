 //Time Complexity=O(N)
//Space Complexity=O(1)

 string reverseWords(string s) 
    {
        string t1="";
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' and t1!="")
            {
                if(ans!="") ans=t1+" "+ans;
                else ans+=t1;
                t1="";
            }
            else if(s[i]!=' ')t1+=s[i];
        }
        if(t1!="")
        {
            if(ans!="") ans=t1+" "+ans;
            else ans+=t1;
        }
        return ans;   
    }