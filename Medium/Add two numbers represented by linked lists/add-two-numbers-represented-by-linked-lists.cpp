//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    
    Node *reverse(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *n=curr->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=n;
            if(n){
                n=n->next;
            }
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node *dummy = new Node(-1);
        Node *temp=dummy;
        int carry=0;
        while(first!=NULL || second!=NULL || carry==1){
            int sum=0;
            if(first!=NULL){
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL){
                sum+=second->data;
                second=second->next;
            }
            sum+=carry;
            carry=sum/10;
            Node *newOne=new Node(sum%10);
            temp->next=newOne;
            temp=temp->next;
        }
        Node *hehe=dummy->next;
        hehe=reverse(hehe);
        while(hehe!=NULL && hehe->data==0){
            hehe=hehe->next;
        }
        if(hehe==NULL){
            Node *hihi=new Node(0);
            return hihi;
        }
        return hehe;
        // code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends