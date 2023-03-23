//Time Complexity=O(N)
//Space Complexity=O(N)

    vector<int>res;
    void helper(TreeNode*root)
    {
        if(!root) return;
        res.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    vector<int> preOrderTraversal(TreeNode* root) 
    {
       helper(root);
       return res;
    }