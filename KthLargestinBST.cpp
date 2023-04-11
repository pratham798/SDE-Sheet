//Time Complexity: O(N)
//Space Complextiy: O(N) stack space

TreeNode<int>*helper(TreeNode<int>*root,int &k)
{
    if(!root) return NULL;
    TreeNode<int>*right=helper(root->right,k);
    if(right!=NULL) return right;
    k-=1;
    if(k==0) return root;
    TreeNode<int>*left=helper(root->left,k);
    return left;
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    TreeNode<int>*ans=helper(root,k);
    if(!ans) return -1;
    return ans->data;
}