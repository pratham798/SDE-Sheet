 //Time Complexity: O(LogN)
//Space Complextiy: O(1)

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(!root) return false;
    if(root->data==x) return true;
    if(x<root->data) return searchInBST(root->left,x);
    return searchInBST(root->right,x);
}