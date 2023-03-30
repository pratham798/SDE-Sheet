//Time Complexity: O(N)
//Space Complextiy: O(1)

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 
    if(!root1 and !root2) return true;
    if(!root1||!root2) return false;
    if(root1->data!=root2->data) return false;
    return identicalTrees(root1->left,root2->left) and identicalTrees(root1->right,root2->right);	 
}