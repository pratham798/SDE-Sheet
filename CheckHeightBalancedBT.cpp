 //Time Complexity: O(N)
//Space Complextiy: O(1)

bool res;
int helper(BinaryTreeNode<int>*root)
{
    if(!root) return 0;
    int left=helper(root->left);
    int right=helper(root->right);
    if(abs(left-right)>1) res=false;
    return 1+max(left,right);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    res=true;
    helper(root);
    return res;
}