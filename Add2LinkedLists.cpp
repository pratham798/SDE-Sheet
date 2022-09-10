// Time Complexity: O(max(m,n))
// Space Complexity: O(max(m,n))

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
      Node*dummy=new Node(NULL);
      Node*temp=dummy;
      int carry=0;
      while(l1||l2||carry)
      {
          int sum=0;
          if(l1)
          {
              sum+=l1->data;
              l1=l1->next;
          }
          if(l2)
          {
              sum+=l2->data;
              l2=l2->next;
          }
          sum+=carry;
          carry=sum/10;
          Node*newNode=new Node(sum%10);
          temp->next=newNode;
          temp=temp->next;
      }
    return dummy->next;
}