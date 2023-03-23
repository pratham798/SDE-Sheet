//Time Complexity=O(N)
//Space Complexity=O(N)

    vector<int>res;
    void helper(TreeNode*root)
    {
        if(!root) return;
        helper(root->left);
        helper(root->right);
        res.push_back(root->val);
    }
    vector<int> postOrderTraversal(TreeNode* root) 
    {
       helper(root);
       return res;
    }