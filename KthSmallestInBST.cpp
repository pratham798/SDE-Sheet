//Time Complexity: O(N)
//Space Complextiy: O(N) stack space

TreeNode<int>*helper(TreeNode<int>*root,int &k)
{
    if(!root) return 0;
    TreeNode<int>*left=helper(root->left,k);
    if(left!=NULL) return left;
    k-=1;
    if(k==0) return root;
    TreeNode<int>*right=helper(root->right,k);
    return right;
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    return helper(root,k)->data;
}