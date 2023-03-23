//Time Complexity=O(N)
//Space Complexity=O(H) (Height of Tree)

void helper(Node*root,int level,vector<int>&res)
{
    if(!root) return;
    if(level==res.size()) res.push_back(root->data);
    helper(root->left,level+1,res);
    helper(root->right,level+1,res);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>res;
   helper(root,0,res);
   return res;
}