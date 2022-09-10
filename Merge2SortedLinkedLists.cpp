//Approach 1
// Time Complexity: O(m+n)
// Space Complexity: O(m+n)

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>*dummy=new Node<int>(NULL);
    Node<int>*temp=dummy;
    while(first and second)
    {
        if(first->data<second->data)
        {
          Node<int>*newNode=new Node<int>(first->data);
          temp->next=newNode;  
          first=first->next;
        }
        else
        {
          Node<int>*newNode=new Node<int>(second->data);
          temp->next=newNode;
          second=second->next;
        }
        temp=temp->next;
    }
    while(first)
    {
          Node<int>*newNode=new Node<int>(first->data);
          temp->next=newNode;  
          first=first->next;
          temp=temp->next;
    }
    while(second)
    {
          Node<int>*newNode=new Node<int>(second->data);
          temp->next=newNode;  
          second=second->next;
          temp=temp->next;
    }
    return dummy->next;
}

//Approach 2
// Time Complexity: O(m+n)
// Space Complexity: O(1)

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(!first) return second;
    if(!second) return first;
    if(first->data>second->data) std::swap(first,second);
    Node<int>*res=first;
    while(first and second)
    {
        Node<int>*temp=NULL;
        while(first and first->data<=second->data)
        {
          temp=first;
          first=first->next;
        }
          temp->next=second;
          std::swap(first,second);
    }
    return res;
}
