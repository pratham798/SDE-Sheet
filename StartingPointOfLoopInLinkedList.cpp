//Approach 1
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(!head||!head->next) return NULL;
    set<Node*>s;
    while(head!=NULL)
    {
        if(s.find(head)!=s.end()) 
        {
            return head;
        }
        s.insert(head);
        head=head->next;
    }
    return NULL;
}

//Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(!head||!head->next) return NULL;
    Node*slow=head;
    Node*fast=head;
    while(fast->next and fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) 
        {
            Node*entry=head;
            while(entry!=slow)
            {
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return NULL;
}