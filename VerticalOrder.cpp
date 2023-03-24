
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if(!root) return {};
    map<int,vector<int>>m;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        TreeNode<int>*curr=q.front().first;
        int ind=q.front().second;
        q.pop();
        m[ind].push_back(curr->data);
        if(curr->left) q.push({curr->left,ind-1});
        if(curr->right) q.push({curr->right,ind+1});
    }
    vector<int>res;
    for(auto&it:m)
    {
        for(int i=0;i<it.second.size();i++) res.push_back(it.second[i]);
    };
    return res;
}