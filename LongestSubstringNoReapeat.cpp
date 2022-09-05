// Approach 1
// Time Complexity: O(n^2)
// Space Complexity: O(n)

int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_set<int>s;
    int res=0;
    for(int i=0;i<input.size();i++)
    {
        int count=0;
        for(int j=i;j<input.size();j++)
        {
            if(s.find(input[j])!=s.end())
            {
                res=max(res,count);
                break;
            }
            s.insert(input[j]);
            count++;
        }
        s.clear();
    }
    return res;
} 

// Approach 2
// Time Complexity: O(2n)
// Space Complexity: O(n)  

int uniqueSubstrings(string input)
{
    //Write your code here
    set<char>s;
    int res=0,l=0,r=0;
    for(int i=0;i<input.size();i++)
    {
       while(s.find(input[i])!=s.end()) 
       {
           s.erase(input[l]);
           l++;
       }
       res=max(res,(r-l+1));
       s.insert(input[i]);
       r++;
    }
    return res;
}

// Approach 3
// Time Complexity: O(n)
// Space Complexity: O(n)

int uniqueSubstrings(string input)
{
    //Write your code here
    map<char,int>s;
    int res=0,l=0,r=0;
    for(int i=0;i<input.size();i++)
    {
       if(s[input[i]]>0) l=max(l,s[input[i]]+1);
       res=max(res,(r-l+1));
       s[input[i]]=i;
       r++;
    }
    return res;
}