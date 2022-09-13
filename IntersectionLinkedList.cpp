//Approach 1
// Time Complexity: O(m*n)
// Space Complexity: O(1)

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    while(firstHead!=NULL)
    {
        Node*temp=secondHead;
        while(temp!=NULL)
        {
            if(temp==firstHead) return temp->data;
            temp=temp->next;
        }
        firstHead=firstHead->next;
    }
    return -1;
}

//Approach 2
// Time Complexity: O(n+m)
// Space Complexity: O(n)

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node*temp=firstHead;
    set<Node*>s;
    while(temp!=NULL)
    {
        s.insert(temp);
        temp=temp->next;
    }
    temp=secondHead;
    while(temp!=NULL)
    {
        if(s.find(temp)!=s.end()) return temp->data;
        temp=temp->next;
    }
    return -1;
}

//Approach 3
// Time Complexity: O(m+n)+O(abs(n-m))+O(min(n,m))
// Space Complexity: O(1)

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node*temp=firstHead;
    int l1=0,l2=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        l1++;
    }
    temp=secondHead;
    while(temp!=NULL)
    {
        temp=temp->next;
        l2++;
    }
    int diff=l2-l1;
    if(diff<0)
    {
        while(diff<0)
        {
            firstHead=firstHead->next;
            diff++;
        }
    }
    else
    {
        while(diff>0)
        {
            secondHead=secondHead->next;
            diff--;
        }
    }
    temp=firstHead;
    Node*temp2=secondHead;
    while(temp)
    {
        if(temp==temp2) return temp2->data;
        temp=temp->next;
        temp2=temp2->next;
    }
    return -1;
}

//Approach 4
// Time Complexity: O(2*max(n,m))
// Space Complexity: O(1)

Node*temp1=firstHead;
    Node*temp2=secondHead;
    while(temp1!=temp2)
    {
        temp1=temp1==NULL?secondHead:temp1->next;
        temp2=temp2==NULL?firstHead:temp2->next;
    }
    return temp1->data;