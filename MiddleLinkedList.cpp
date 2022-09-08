// Approach 1
// Time Complexity: O(2n)
// Space Complexity: O(1)

Node *findMiddle(Node *head) {
    // Write your code here
    int n=0;
    Node*temp=head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    for(int i=0;i<n/2;i++) head=head->next;
    return head;
}

// Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

Node *findMiddle(Node *head) {
    // Write your code here
    int n=0;
    Node*slow=head;
    Node*fast=head;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}