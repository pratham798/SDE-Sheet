//Time Complexity: O(N)
//Space Complextiy: O(1)

class NodeVal{
    public:
    int size;
    int left;
    int right;
    NodeVal(int size,int left,int right)
    {
        this->size=size;
        this->left=left;
        this->right=right;
    }
};
NodeVal helper(TreeNode<int>*root)
{
    if(!root) return NodeVal(0,INT_MAX,INT_MIN);
    auto l=helper(root->left);
    auto r=helper(root->right);
    if(root->data>l.right and root->data<r.left) 
    {
      return NodeVal(l.size+r.size+1,min(root->data,l.left),max(root->data,r.right));
    } 
    return NodeVal(max(l.size,r.size),INT_MIN,INT_MAX);
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return helper(root).size;
}
