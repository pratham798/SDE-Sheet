//Approach 1
//Time Complexity:O(N!*N)
//Space Complexity:O(N)
    void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      vector < int > ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
//Approach 2
// TIME COMPLEXITY= O(N!*N)
// SPACE COMPLEXITY= O(1)
void helper(string&s,int index,vector<string>&res)
{
    if(index==s.size())
    {
        res.push_back(s);
    }
    for(int i=index;i<s.size();i++)
    {
        swap(s[index],s[i]);
        helper(s,index+1,res);
        swap(s[index],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>res;
    helper(s,0,res);
    return res;
}