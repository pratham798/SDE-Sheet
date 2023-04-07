// Time Complexity:O(logn)
// Space Complexity:O(n)
int ans;
void helper(BinaryTreeNode<int> * root, int X)
{
    if(!root) return;
    if(root->data==X)
    {
        ans=root->data;
        return;
    }
    else if(root->data > X) 
    {
        ans=min(ans,root->data);
        helper(root->left, X);
    }
    else helper(root->right,X);
    return;
}
int findCeil(BinaryTreeNode<int> *root, int X){
    // Write your code here.
    ans=1e9;
    helper(root,X);
    if(ans==1e9) return -1;
    return ans;
}