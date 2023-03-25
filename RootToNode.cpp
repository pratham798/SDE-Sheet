//Time Complexity=O(N)
//Space Complexity=O(N)

bool helper(TreeNode*A,int B,vector<int>&res)
 {
     if(!A) return false;
     res.push_back(A->val);
     if(A->val==B) return true;
     if(helper(A->left,B,res)) return true;
     if(helper(A->right,B,res)) return true; 
     res.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int>res;
    helper(A,B,res);
    return res;
}
