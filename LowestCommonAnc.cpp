 //Time Complexity: O(N)
//Space Complextiy: O(1)

 Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(!root) return root;
       if(root->data==n1 || root->data==n2)
       {
           return root;
       }
       Node*left=lca(root->left,n1,n2);
       Node*right=lca(root->right,n1,n2);
       if(!left and !right) return NULL;
       if(left and !right) return left;
       if(right and !left) return right;
       return root;
    }