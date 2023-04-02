//Time Complexity: O(N)
//Space Complextiy: O(1)

bool helper(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)
{
    if(!root1 and !root2) return true;
    if(!root1||!root2) return false;
    if(root1->data!=root2->data) return false;
    return helper(root1->left,root2->right) and helper(root1->right,root2->left);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(!root) return true;
    return helper(root->left,root->right);   
}