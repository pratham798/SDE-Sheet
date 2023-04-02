//Time Complexity: O(N)
//Space Complextiy: O(1)

long long int ans;
long long int helper(TreeNode<int>*root)
{
    if(!root) return 0;
    long long int left=helper(root->left);
    long long int right=helper(root->right);
    ans=max(ans,(root->val+left+right));
    return max(left,right)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root || !root->left || !root->right) return -1;
    ans=0;
    helper(root);
    return ans;
}