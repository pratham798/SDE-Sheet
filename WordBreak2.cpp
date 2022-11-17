// Time Complexity: O(2^n*k)+O(n)
// Space Complexity: O(n)
void helper(string &s,int ind,vector<string>&res,string path,string word,unordered_set<string>&st)
{
    if(ind==s.size())
    {
        if(st.find(word)!=st.end())
        {
            path+=word;
            res.push_back(path);
        }
        return;
    }
    word+=s[ind];
    if(st.find(word)!=st.end())
    {
        helper(s,ind+1,res,path+word+' ',"",st);
    }
    helper(s,ind+1,res,path,word,st);
    
}
vector<string> wordBreak(string &s,vector<string>&dictionary)
{
    // Write your code here
    unordered_set<string>st;
    for(auto&it:dictionary)
    {
        st.insert(it);
    }
    vector<string>res;
    string path="";
    string word="";
    helper(s,0,res,path,word,st);
    return res;

}