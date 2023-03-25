//Time Complexity=O(N)
//Space Complexity=O(1)
  
  int maxDepth(TreeNode* root) 
    {
        if(!root) return 0;
        int count=1;
        count=count+max(maxDepth(root->left),maxDepth(root->right));
        return count;
    }