 //Time Complexity: O(N)
//Space Complextiy: O(1)

 bool helper(TreeNode*root,long long low,long long high)
    {
        if(!root) return true;
        if(root->val<=low||root->val>=high) return false;
        return helper(root->left,low,root->val) and helper(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(!root->left and !root->right) return true;
        return helper(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
    }