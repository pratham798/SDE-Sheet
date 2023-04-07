// Time Complexity:O(logn)
// Space Complexity:O(n)
int ans;
void helper(TreeNode<int> * root, int X)
{
    if(!root) return;
    if(root->val==X)
    {
        ans=root->val;
        return;
    }
    else if(root->val < X) 
    {
        ans=max(ans,root->val);
        helper(root->right, X);
    }
    else helper(root->left,X);
    return;
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    ans=0;
    helper(root,X);
    return ans;
}