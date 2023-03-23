//Time Complexity=O(N)
//Space Complexity=O(N)

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>res;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int count=0;
    while(!q.empty() and q.front()!=NULL)
    {
        BinaryTreeNode<int>*curr=q.front();
        q.pop();
        res.push_back(curr->val);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return res;
}