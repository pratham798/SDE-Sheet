//Approach 1
// Time Complexity: O(n)
// Space Complexity: O(n)

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector<int>arr;
    while(head!=NULL)
    {
        arr.push_back(head->data);
        head=head->next;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=arr[arr.size()-i-1]) return false;
    }
    return true;
}

//Approach 2
// Time Complexity: O(n/2)+O(n/2)+O(n/2)
// Space Complexity: O(1)

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    if(!head||!head->next) return head;
    LinkedListNode<int> *prev=NULL;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *ahead;
    while(curr)
    {
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head||!head->next) return true;
    LinkedListNode<int> *slow=head;
    LinkedListNode<int> *fast=head;
    while(fast->next!=NULL and fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;
    LinkedListNode<int> *t1=slow;
    LinkedListNode<int> *t2=head;
    while(t1!=NULL)
    {
        if(t1->data!=t2->data) return false;
        t1=t1->next;
        t2=t2->next;
    }
    return true;
}