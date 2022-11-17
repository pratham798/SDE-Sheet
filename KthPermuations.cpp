  //Approach 1
  // Time Complexity: O(n!*n)
  // Space Complexity: O(n)

  void helper(string&s,int index,vector<string>&res)
{
    if(index==s.size())
    {
        res.push_back(s);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        swap(s[index],s[i]);
        helper(s,index+1,res);
        swap(s[index],s[i]);
    }
}
string kthPermutation(int n, int k) 
{
    // Write your code here.
    string s="";
    for(int i=1;i<=n;i++)
    {
        s+=(i+'0');
    }
    vector<string>res;
    helper(s,0,res);
    sort(res.begin(),res.end());
    return res[k-1];
}
  //Approach 2
  // Time Complexity: O(n^2)
  // Space Complexity: O(n)   
 
    string getPermutation(int n, int k) 
    {
       int fact=1;
       vector<int>nums;
       for(int i=1;i<n;i++)
       {
           fact=fact*i;
           nums.push_back(i);
       }
       nums.push_back(n);
       k=k-1;
       string res="";
       while(true)
       {
           res+=to_string(nums[k/fact]);
           nums.erase(nums.begin()+(k/fact));
           if(!nums.size()) break;
           k=k%fact;
           fact=fact/nums.size();
       }
       return res;
    }