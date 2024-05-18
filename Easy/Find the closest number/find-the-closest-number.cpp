//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int ans = arr[0], maxDiff = abs(arr[0] - k);
        for(int i=1; i<n; i++)
        {
            int diff = abs(arr[i] - k);
            if(diff < maxDiff)
            {
                maxDiff = diff;
                ans = arr[i];
            }
            else if(diff == maxDiff)
            {
                ans = max(ans, arr[i]);
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends