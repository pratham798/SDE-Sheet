//Approach 1
// Time Complexity: O(n)+O(n-(k%n))
// Space Complexity: O(1)

Node *rotate(Node *head, int k) {
     // Write your code here.
    if(k==0||!head||!head->next) return head;
    Node*back=head;
    int len=1;
    while(back->next)
    {
        len++;
        back=back->next;
    }
    k=k%len;
    if(k==0) return head;
    k=len-k;
    Node*rot=head;
    while(k>1)
    {
        rot=rot->next;
        k--;
    }
    Node*temp=rot->next;
    rot->next=NULL;
    back->next=head;
    head=temp;
    return head;
}