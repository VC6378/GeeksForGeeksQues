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
    }
}

// } Driver Code Ends


/* The functions which 
builds the segment tree */

void buildSegmentTree(int i,int l,int r,int segmentTree[],int arr[]){
    if(l==r){
        segmentTree[i]=arr[l];
        return;
    }
    int mid=l+(r-l)/2;
    buildSegmentTree(2*i+1,l,mid,segmentTree,arr);
    buildSegmentTree(2*i+2,mid+1,r,segmentTree,arr);
    segmentTree[i]=min(segmentTree[2*i+1],segmentTree[2*i+2]);
}

int *constructST(int arr[],int n)
{
    int *segment= new int[4*n];
    buildSegmentTree(0,0,n-1,segment,arr);
    return segment;
  //Your code here
}


/* The functions returns the
 min element in the range
 from a and b */
 
int query(int start,int end,int i,int l,int r,int segmentTree[]){
    if(l>end || r<start) return INT_MAX;
    if(l>=start && r<=end) return segmentTree[i];
    int mid=l+(r-l)/2;
    return min(query(start,end,2*i+1,l,mid,segmentTree),query(start,end,2*i+2,mid+1,r,segmentTree));
}
 
int RMQ(int st[] , int n, int a, int b)
{
    
    return query(a,b,0,0,n-1,st);
//Your code here
}