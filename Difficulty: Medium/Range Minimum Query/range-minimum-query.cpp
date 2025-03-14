//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */

void buildSegmentTree(int ind,int left,int right,int segT[],int arr[]){
    if(left==right){
        segT[ind]=arr[left];
        return;
    }
    int mid = left+(right-left)/2;
    buildSegmentTree(2*ind+1,left,mid,segT,arr);
    buildSegmentTree(2*ind+2,mid+1,right,segT,arr);
    segT[ind]=min(segT[2*ind+1],segT[2*ind+2]);
}

int *constructST(int arr[],int n)
{
    int* segT = new int[4*n];
    buildSegmentTree(0,0,n-1,segT,arr);
    return segT;
  //Your code here
}

int querySegmentTree(int start,int end,int ind,int left,int right,int st[]){
    if(left>end or right<start) return INT_MAX;
    if(left>=start and right<=end) return st[ind];
    int mid = left+(right-left)/2;
    return min(querySegmentTree(start,end,2*ind+1,left,mid,st),querySegmentTree(start,end,2*ind+2,mid+1,right,st));
}


/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
return querySegmentTree(a,b,0,0,n-1,st);
}