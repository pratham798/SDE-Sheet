//Iterative
// Time Complexity: O(n)
// Space Complexity: O(1)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>*prev=NULL;
    LinkedListNode<int>*curr=head;
    LinkedListNode<int>*ahead;
    while(curr!=NULL)
    {
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
    }
    head=prev;
    return head;
}

//Recursive
// Time Complexity: O(n)
// Space Complexity: O(1)

ListNode*reverseList(ListNode*head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    ListNode*rev=reverseList(head->next);
    ListNode*temp=rev;
    while(temp->next!=NULL)
    {
       temp=temp->next;
    }
     temp->next=head;
     head->next=NULL;
     return rev;
}