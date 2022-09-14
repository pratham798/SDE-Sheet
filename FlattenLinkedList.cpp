
//Approach 1
// Time Complexity: O(N)
// Space Complexity: O(1)


Node*merge(Node*first,Node*second)
{
    if(!first) return second;
    if(!second) return first;
    Node*res=new Node(NULL);
    Node*temp=res;
    while(first and second)
    {
        if(first->data<second->data)
        {
            temp->child=first;
            temp=temp->child;
            first=first->child;
        }
        else
        {
            temp->child=second;
            temp=temp->child;
            second=second->child;
        }  
    }
    if(first) temp->child=first;
    else temp->child=second;
    res->child->next=NULL;
    return res->child;
}
Node* flattenLinkedList(Node* root) 
{
	// Write your code here
    if(!root || !root->next) return root;
    root->next=flattenLinkedList(root->next);
    root=merge(root,root->next);
    return root;
}