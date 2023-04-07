//Time Complexity: O(N)
//Space Complextiy: O(1)
int res=0;
int helper(TreeNode<int>*root)
{
    if(!root) return 0;
    int left=helper(root->left);
    int right=helper(root->right);
    res=max(res,left+right);
    return 1+max(left,right);

}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    res=0;
    helper(root);
    return res;
}