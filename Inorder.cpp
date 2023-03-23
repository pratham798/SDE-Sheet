//Time Complexity=O(N)
//Space Complexity=O(N)

    vector<int>res;
    void helper(TreeNode*root)
    {
        if(!root) return;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
       helper(root);
       return res;
    }