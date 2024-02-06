//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
     Node *sortedInsert(Node* head, int data)
    {
       //Your code here
        Node *temp=new Node(data);
        Node *dummy=head;
        Node *tail=head;
        if(head==NULL)
        {
            temp->next=temp;
            return temp;
        }
        
        while(tail->next!=head)
        {
            tail=tail->next;
        }
        if(tail==head)
        {
            if(head->data<= data)
            {
                head->next=temp;
                temp->next=head;
                
            }
            else{
                temp->next=head;
                head->next=temp;
                head=temp;
            }
            return head;
        }
        while(dummy->next!=head)
        {
            if(dummy->data > data)
            {
                temp->next=head;
                tail->next=temp;
                head=temp;
                break;
            }
            else if(dummy->data <= data && dummy->next->data >=data)
            {
                
                temp->next=dummy->next;
                dummy->next=temp;
                break;
            }
            else if(dummy->data < data && dummy->next->data <data)
            {
                if(dummy->next==tail)
                {
                    dummy->next->next=temp;
                    temp->next=head;
                    break;
                }
                dummy=dummy->next;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;
  
  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;
  
  
    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);
    
    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }
    
    if(n>0)
    temp->next=start;
 
    scanf("%d",&x);
    Solution ob;
    start = ob.sortedInsert(start,x);
    printList(start);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}

// } Driver Code Ends