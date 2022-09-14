//Approach 1
// Time Complexity: O(n)
// Space Complexity: O(n)

bool detectCycle(Node *head)
{
	//	Write your code here
    if(!head||!head->next) return false;
    set<Node*>s;
    Node*temp=head;
    while(temp!=NULL)
    {
        if(s.find(temp)!=s.end()) return true;
        else s.insert(temp);
        temp=temp->next;
    }
    return false;
}


//Approach 2
// Time Complexity: O(n)
// Space Complexity: O(1)

bool detectCycle(Node *head)
{
	//	Write your code here
    if(!head||!head->next) return false;
    Node*slow=head;
    Node*fast=head;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}