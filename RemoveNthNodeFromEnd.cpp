// Approach 1
// Time Complexity: O(2n)
// Space Complexity: O(1)

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head ||K==0) return head;
    int n=0;
    LinkedListNode<int>*temp=head;
    while(temp!=NULL)
    {
        n++;
        temp=temp->next;
    }
    n=n-K;
    if(n==0) return head->next;
    LinkedListNode<int>*dummy=new LinkedListNode<int>(NULL);
    temp=head;
    dummy->next=temp;
    while(n>1)
    {
        n--;
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return dummy->next;   
}

// Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    if(!head||K==0) return head;
    LinkedListNode<int>*dummy=new LinkedListNode<int>(NULL);
    dummy->next=head;
    LinkedListNode<int>*slow=dummy;
    LinkedListNode<int>*fast=dummy;
    
    for(int i=0;i<K;i++)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}